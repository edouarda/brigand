#!/bin/env python2

#==============================================================================
#         Copyright 2012 - 2015 NumScale SAS
#
#         Distributed under the Boost Software License, Version 1.0.
#                See accompanying file LICENSE.txt or copy at
#                    http://www.boost.org/LICENSE_1_0.txt
#==============================================================================

"""
This script aims to preprocess files to aggregate every matching includes to
create a single file by removing extra includes guard, C comments, etc...

The generated file can easily be embedded as dependency for huge projects!
"""

import re
import sys
import os.path
import argparse

# defaults paths to look for includes
default_includes_path = ['.']

# pp tokens regexp
r_escape_line = re.compile(r'^.*\\\n$')
r_empty_line = re.compile('^[ \t]*\n$')
r_pp_include = re.compile('^\s*#\s*include\s+["|<](.*)["|>]$')
r_pp_ifndef = re.compile('^\s*#\s*ifndef\s+(.*)\s*$')
r_pp_if_defined = re.compile('^\s*#\s*if\s+defined\(\s*(.*)\s*\)\s*$')
r_pp_if = re.compile('^\s*#\s*if.*$')
r_pp_endif = re.compile('^\s*#\s*endif.*$')
r_pp_define = re.compile('^\s*#\s*define\s+(.*)\s*$')
r_pp_pragma_once = re.compile('^\s*#\s*pragma\s+once\s*$')
r_C_one_line_comment = re.compile('^(.*?)\s*//.*$')
r_C_one_line_block_comment = re.compile('^(.*)/\*.*\*/(.*)$')
r_C_block_begin_comment = re.compile('(.*)/\*.*')
r_C_block_end_comment = re.compile('.*\*/(.*)')

# globals
will_escape = False
guard_stack = []
included_files = []
keep_guard = True
in_C_block_comments = False

"""
Parse options. Here is the list of supported options:
    see `help`(s)
"""
def parse_opts(args):
    p = argparse.ArgumentParser(
            description='Aggregates headers into one single file')
    p.add_argument('-I', type=str, action='append', metavar='<dir>', default=[], dest='includes_path',
            help='Add the specified directory to the search path for include files')
    p.add_argument('-v', dest='verbose', action='store_true', default=False,
            help='Enable verbose mode, useful for debugging')
    p.add_argument('--include-match', type=str, metavar='<regexp>', default='.*', dest='r_include',
            help='The regexp to match includes that will be expanded')
    p.add_argument('--guard-match', type=str, metavar='<regexp>', default='^.*_INCLUDED$', dest='r_guard',
            help='The regexp to match includes guard')
    p.add_argument('-o', type=argparse.FileType('w'), metavar='<output-file>', dest='output', default=sys.stdout,
            help='The output file')
    p.add_argument('filename', type=str, metavar='<input-file>',
            help='The file to preprocess')

    opts = p.parse_args(args)
    opts.r_guard = re.compile(opts.r_guard)
    opts.r_include = re.compile(opts.r_include)
    return opts

"""
Print only if 'verbose' option is enabled
"""
def vprint(opts, what):
    if opts.verbose:
        sys.stderr.write('verbose: {}\n'.format(what))

"""
Try to find a valid path for the given filename, if not found then exit
"""
def get_path_for(f, opts):
    for path in opts.includes_path:
        path = os.path.join(path, f)
        vprint(opts, 'try to include: {}'.format(path))
        if os.path.isfile(path):
            return path
    sys.stderr.write('{}: file not found! aborting.\n'.format(f))
    sys.exit(1)

"""
Preprocess a single line
"""
def pp_line(line, output, opts):
    global will_escape
    global keep_guard
    global in_C_block_comments

    is_escaped = will_escape
    will_escape = False
    if r_empty_line.match(line):
        # skip empty lines
        return
    # we do not want to remove comments before the first guard as
    # its content may be a license or whatever else important
    if not keep_guard:
        # C comments (one line) '//'
        m = r_C_one_line_comment.match(line)
        if m:
            line = m.group(1)
        # C (block) comments (one line) '/* */'
        m = r_C_one_line_block_comment.match(line)
        if m:
            line = m.group(1) + m.group(2)
        # C (block) comments '/*'
        m = r_C_block_begin_comment.match(line)
        if m:
            in_C_block_comments = True
            line = m.group(1)
        # C (block) comments '*/'
        m = r_C_block_end_comment.match(line)
        if m:
            in_C_block_comments = False
            line = m.group(1)
            return pp_line(line, output, opts)
        # in C (block) comments
        if in_C_block_comments:
            return
    # #include
    m = r_pp_include.match(line)
    if m and opts.r_include.match(m.group(1)):
        keep_guard = False
        path = get_path_for(m.group(1), opts)
        pp_file(path, output, opts)
        return
    # we keep the guard only for the very first preprocessed file
    if not keep_guard:
        # #pragma once
        if r_pp_pragma_once.match(line):
            return
        # #ifndef / #if defined(...)
        m = r_pp_ifndef.match(line) or r_pp_if_defined.match(line)
        if m and opts.r_guard.match(m.group(1)):
            # we've found a new include guard, add a new counter to
            # keep track of it!
            guard_stack.append(1)
            return
        # #{if,ifndef} / #endif (pairs)
        if len(guard_stack):
            if r_pp_if.match(line):
                guard_stack[-1] += 1
            elif r_pp_endif.match(line):
                guard_stack[-1] -= 1
                if guard_stack[-1] < 0:
                    sys.stderr.write('non matching #endif found! aborting.')
                    sys.exit(1)
                if guard_stack[-1] == 0:
                    # we hit the 'endif' part of the guard, so pop it from
                    # the stack counter and do not print it!
                    guard_stack.pop()
                    return
            # define (guard)
            # we do check this one only if we have a valid stack counter
            # DO NOT PUT IT OUTSIDE OF THE `if len(guard_stack):`
            m = r_pp_define.match(line)
            if m and opts.r_guard.match(m.group(1)):
                return
    # add missing '\n' if needed, for example:
    #
    # '/* foo */\n'
    # gets turned into:
    # ''
    #
    # also:
    #
    # #define foo\
    # /**/
    # gets turned into:
    # #define foo
    # '\n'
    #
    if (is_escaped or len(line) > 0) and '\n' not in line:
        line += '\n'
    # check if the current line escape the next one
    if r_escape_line.match(line):
        will_escape = True
    # everything has been checked now! so we can print the current line
    output.write(line)

"""
Preprocess the file here!
"""
def pp_file(f, output, opts):
    # use the absolute version of the filename to always get the same path
    # e.g. ./foo.h == foo.h == bar/../foo.h
    f = os.path.abspath(f)
    if f in included_files:
        # if included, then do not process it!
        return
    included_files.append(f)
    vprint(opts, 'preprocessing: {}'.format(f))
    try:
        with open(f, 'r') as f:
            dirname = os.path.dirname(f.name)
            opts.includes_path.append(dirname)
            for line in f.readlines():
                pp_line(line, output, opts)
            opts.includes_path.remove(dirname)
    except IOError as e:
        sys.stderr.write(str(e) + '\n')
        sys.exit(1)

"""
The top-level function
"""
def embed():
    args = sys.argv[1:]
    for path in default_includes_path:
        args.append('-I')
        args.append(path)
    opts = parse_opts(args)
    pp_file(opts.filename, opts.output, opts)

# The entry point!
if __name__ == '__main__':
    embed()
