#!/usr/bin/env python

import sys
import os
import re

pragma_once_pat = re.compile("^(\ |\t)*#pragma(\ |\t)+once")

if __name__ == '__main__':

    if len(sys.argv) < 2:
        print "expect dir"
        sys.exit(0)

    for root, dir, files in os.walk(sys.argv[1]):

        header_guard_prefix = reduce(lambda acc, val: acc + '_' + val.upper() , root.split(os.sep)[1:], "BOOST_BRIGAND")

        for file in files:

            header_guard = header_guard_prefix + '_' + os.path.splitext(file)[0].upper() + '_HPP'

            replaced = False

            full_path = os.path.join(root, file)

            all_lines = []

            with open(full_path) as f:

                for line in f:

                    if not replaced and pragma_once_pat.match(line):
                        all_lines.append("#ifndef " + header_guard + "\n")
                        all_lines.append("#define " + header_guard + "\n")
                        replaced = True
                    else:
                        all_lines.append(line)

            if replaced:
                with open(full_path, "w") as f:
                    for line in all_lines:
                        f.write(line)
                    f.write("#endif\n")

