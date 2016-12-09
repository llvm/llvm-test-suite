#!/usr/bin/env python
#
# This tool queries a ninja build file for the test-suite to figure out details
# about the build like the sourcefiles involved in a target or the assembly
# files output when clang is invoked with -save-temps=obj.
# It comes with an additional mode that given two build directories invokes the
# diff tool for each pair of files.
#
# Examples:
#
# List .stats files for the build in the current directory (assuming
# -save-stats=obj in CFLAGS):
#   $ tdiff.py --stats all
#
# Compare assembly files of the 176.gcc benchmark between two test-suite build
# directories (assuming -save-temps=obj in CFLAGS):
#   $ tdiff.py -a path/dir_before -b path/dir_after --s_files 176.gcc | less
#
# Ninja query code based on ninja/src/browse.py (apache license version 2.0).
import sys
import subprocess
import argparse
import os
from collections import namedtuple


Node = namedtuple('Node', ['inputs', 'rule', 'target', 'outputs'])


def match_strip(line, prefix):
    if not line.startswith(prefix):
        return (False, line)
    return (True, line[len(prefix):])


def parse(text):
    text = text.strip()
    lines = iter(text.split('\n'))

    rule = None
    inputs = []
    outputs = []

    try:
        line = None
        while True:
            target = None
            if line is None:
                line = next(lines)
            target = line[:-1]  # strip trailing colon

            line = next(lines)
            (match, rule) = match_strip(line, '  input: ')
            if match:
                (match, line) = match_strip(next(lines), '    ')
                while match:
                    type = None
                    (match, line) = match_strip(line, '| ')
                    if match:
                        type = 'implicit'
                    (match, line) = match_strip(line, '|| ')
                    if match:
                        type = 'order-only'
                    inputs.append((line, type))
                    (match, line) = match_strip(next(lines), '    ')

            match, _ = match_strip(line, '  outputs:')
            if match:
                (match, line) = match_strip(next(lines), '    ')
                while match:
                    outputs.append(line)
                    (match, line) = match_strip(next(lines), '    ')
            yield Node(inputs, rule, target, outputs)
    except StopIteration:
        pass

    if target is not None:
        yield Node(inputs, rule, target, outputs)


def query_ninja(targets, cwd):
    # Query ninja for a node in its build dependency tree.
    proc = subprocess.Popen(['ninja', '-t', 'query'] + targets, cwd=cwd,
                            stdout=subprocess.PIPE, universal_newlines=True)
    out, _ = proc.communicate()
    if proc.returncode != 0:
        raise Exception("Failed to query ninja for targets: %s" % (targets,))
    return parse(out)


def determine_max_commandline_len():
    """Determine maximum length of commandline possible"""
    # See also http://www.in-ulm.de/~mascheck/various/argmax/
    sc_arg_max = os.sysconf('SC_ARG_MAX')
    if sc_arg_max <= 0:
        return 10000 # wild guess
    env_len = 0
    for key,val in os.environ.iteritems():
        env_len += len(key) + len(val) + 10
    return sc_arg_max - env_len


def get_inputs_rec(target, cwd):
    worklist = [target]

    result = dict()
    maxquerylen = determine_max_commandline_len() - 100
    while len(worklist) > 0:
        querylist = []
        querylen = 0
        while len(worklist) > 0:
            w = worklist.pop()
            if w in result:
                continue
            querylen += 9 + len(w)
            if querylen > maxquerylen:
                break
            querylist.append(w)
        if querylist == []:
            break

        queryres = query_ninja(querylist, cwd)
        for res in queryres:
            result[res.target] = res
            for inp,typ in res.inputs:
                if typ == 'order-only':
                    continue
                worklist.append(inp)
    return result


def replace_ext(filename, newext):
    # Note that os.path.splitext() does not work here: We want '.c.o' -> '.xxx'
    dirname, basename = os.path.split(filename)
    return dirname + "/" + basename.split(".", 1)[0] + newext


def filelist(mode, target, cwd, config):
    tree = get_inputs_rec(config.target[0], cwd)

    if config.mode == 'sources':
        # Take leafs in the dependency tree
        for target, depnode in tree.iteritems():
            if len(depnode.inputs) == 0:
                yield target
    else:
        # Take files ending in '.o'
        for target, depnode in tree.iteritems():
            if target.endswith(".o"):
                # Determine .s/.stats ending used by -save-temps=obj or
                # -save-stats=obj
                if config.mode == 's_files':
                    target = replace_ext(target, '.s')
                elif config.mode == 'stats':
                    target = replace_ext(target, '.stats')
                else:
                    assert config.mode == 'objects'
                yield target


def diff_file(dir0, dir1, target, config):
    u_args = ['-u']
    if config.diff_U is not None:
        u_args = ['-U' + config.diff_U]
    files = ["%s/%s" % (dir0, target), "%s/%s" % (dir1, target)]
    rescode = subprocess.call(['diff'] + u_args + files)
    return rescode


def main(argv):
    parser = argparse.ArgumentParser(prog=argv[0])
    parser.add_argument('-s', '--s_files', dest='mode', action='store_const',
                        const='s_files', help="Select assembly files")
    parser.add_argument('-i', '--sources', dest='mode', action='store_const',
                        const='sources', help="Select source files")
    parser.add_argument('-o', '--objects', dest='mode', action='store_const',
                        const='objects', help="Select object files")
    parser.add_argument('-S', '--stats', dest='mode', action='store_const',
                        const='stats', help="Select statistics files")
    parser.add_argument('-a', '--dir0', dest='dir0')
    parser.add_argument('-b', '--dir1', dest='dir1')
    parser.add_argument('-U', dest='diff_U')
    parser.add_argument('target', metavar='TARGET', nargs=1)
    config = parser.parse_args()
    if config.mode is None:
        parser.print_usage(sys.stderr)
        sys.stderr.write("%s: error: Must specify a mode\n" % (argv[0], ))
        sys.exit(1)
    if (config.dir0 is None) != (config.dir1 is None):
        sys.stderr.write("%s: error: Must specify dir0+dir1 (or none)")
        sys.exit(1)

    files = filelist(config.mode, config.target[0], config.dir0, config)

    if config.dir0:
        global_rc = 0
        for target in files:
            rc = diff_file(config.dir0, config.dir1, target, config)
            if rc != 0:
                global_rc = rc
        sys.exit(global_rc)
    else:
        # Simply print file list
        for f in files:
            print(f)


if __name__ == '__main__':
    main(sys.argv)
