"""Check the path-list files that litsupport/modules/compiletime.py reads.

Usage: test_compile_time_lists.py <test-file> <object-name>

<test-file> is the .test file of the running test. CMake writes
<test-file>.o.time.list and <test-file>.link.time.list next to it, and the
build writes the *.time files they point to.
"""
import os
import sys

test_file, object_name = sys.argv[1], sys.argv[2]

def read_list(path):
    if not os.path.isfile(path):
        sys.exit("missing path-list file: %s" % path)
    with open(path) as f:
        text = f.read()
    if text and not text.endswith("\n"):
        sys.exit("%s: last line is not newline terminated" % path)
    lines = text.splitlines()
    for line in lines:
        if not line:
            sys.exit("%s: contains an empty line" % path)
        if not os.path.isabs(line):
            sys.exit("%s: not an absolute path: %s" % (path, line))
        if not os.path.isfile(line):
            sys.exit("%s: listed file does not exist: %s" % (path, line))
    return lines

objects = read_list(test_file + ".o.time.list")
if len(objects) != 1 or os.path.basename(objects[0]) != object_name + ".time":
    sys.exit("unexpected .o.time.list content: %r" % objects)

links = read_list(test_file + ".link.time.list")
if len(links) != 1 or not links[0].endswith(".link.time"):
    sys.exit("unexpected .link.time.list content: %r" % links)
