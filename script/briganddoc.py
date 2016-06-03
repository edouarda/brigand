#!/usr/bin/env python

import os
import re
import sys
import argparse

brigand_git = 'https://github.com/edouarda/brigand'
blacklist = [ 'brigand.hpp', 'detail', 'comparisons.hpp', 'config.hpp' ]

def error(what, code=1):
    sys.stderr.write('briganddoc:error: ' + what + '\n')
    sys.exit(code)

def say(s):
    print(':: ' + s)

def parse_opts(args):
    p = argparse.ArgumentParser(description='Create skeleton documentation')
    p.add_argument('root', nargs='?', type=str, metavar='<root-directory>', default='',
            help='The root directory')
    return p.parse_args(args)

def find_hpps(root):
    def sanitize_path(path, brigand_root):
        return path.replace(os.path.join(brigand_root, 'brigand') + os.sep, '', 1)
    def blacklisted(f):
        for b in blacklist:
            if b in f:
                return True
        return os.path.isdir(f.replace('.hpp', ''))
    hpps = []
    root = os.path.normpath(root)
    brigand_root = root
    for root, dirs, files in os.walk(os.path.join(root, 'brigand')):
        for f in files:
            f = os.path.join(root, f)
            if blacklisted(f):
                continue
            f = sanitize_path(f, brigand_root)
            if f.endswith('.hpp'):
                hpps.append(f)
    return sorted(hpps)

def create_md_name(hpp):
    root, name = os.path.split(hpp)
    root = '.'.join(root.split(os.path.sep))
    name = name.replace('.hpp', '.md')
    return '{}.{}'.format(root, name)

def create_md(hpp, where):
    md = os.path.join(where, create_md_name(hpp))
    if not os.path.exists(md):
        say('+ {}'.format(md))
    f = open(md, 'w+')
    w = lambda l: f.write(l + '\n')
    w('# Synopsis')
    w('')
    w('```cpp')
    w('```')
    w('')
    w('# Description')
    w('')
    w('# When to use')
    w('')
    w('# Header')
    w('')
    w('```cpp')
    w('#include <brigand/{}>'.format(hpp))
    w('```')
    w('')
    w('# Parameters')
    w('')
    w('# Example')
    w('')
    w('```cpp')
    w('#include <brigand/{}>'.format(hpp))
    w('```')
    w('')
    w('# See also')
    w('')
    w('[[sequences.list]]')

def update_reference(hpps, where):
    def parse_reference(f, level=0):
        ref = {}
        r_entry = re.compile(' \* \[.*\]\((.*)\)')
        for line in f:
            m = r_entry.match(line)
            if m:
                path = m.group(1)
                name = path.split('.')[-1]
                dirs = path.split('.')[:-1]
                temp = ref
                for key in dirs:
                    temp = temp.setdefault(key, {})
                temp[name] = path
        return ref
    def update_reference_from_hpps(ref, hpps):
        for hpp in hpps:
            md = create_md_name(hpp)
            root, f = os.path.split(hpp)
            temp = ref
            for d in root.split(os.path.sep):
                temp = temp.setdefault(d, {})
            name = f.replace('.hpp', '')
            link = md.replace('.md', '')
            if name not in temp:
                say('Reference: + {}'.format(link))
                temp[name] = link
        return ref
    def write_reference(md, ref, level=0):
        for r in sorted(ref):
            if isinstance(ref[r], str):
                md.write(' * [{}]({})\n'.format(r, ref[r]))
        md.write('\n')
        for r in sorted(ref):
            if isinstance(ref[r], dict):
                md.write('#{} {}\n\n'.format(level * '#', r.capitalize()))
                write_reference(md, ref[r], level + 1)
        md.write('\n')
    ## ---------------------------------------------------------------------------------------------
    ref = {}
    md_path = os.path.join(where, 'Reference.md')
    if os.path.exists(md_path):
        with open(md_path, 'r') as md:
            ref = parse_reference(md)
    ref = update_reference_from_hpps(ref, hpps)
    with open(md_path, 'w') as md:
        write_reference(md, ref)

def is_brigand_root(root):
    root = os.path.join(root, 'brigand')
    return os.path.isdir(root) and os.path.exists(os.path.join(root, 'nothing.cpp'))

def git_clone_wiki(wiki):
    if os.path.exists(wiki):
        return wiki
    git = 'git clone {}.wiki.git {}'.format(brigand_git, wiki)
    say(git)
    if os.system(git) is not 0:
        return error('Something went wrong when cloning wiki')
    return wiki

def briganddoc(args):
    opts = parse_opts(args)
    if not is_brigand_root(opts.root):
        return error('Your root directory is not a valid brigand root')
    hpps = find_hpps(opts.root)
    wiki = git_clone_wiki(os.path.join(opts.root, 'wiki'))
    for hpp in hpps:
        create_md(hpp, where=wiki)
    update_reference(hpps, where=wiki)
    say('Done!')

if __name__ == '__main__':
    briganddoc(sys.argv[1:])
