#!/usr/bin/env python3
#
# This script parses the DejaGNU annotations from the files in the gfortran test
# suite and updates the static test configuration files. This must
# be run whenever the tests are updated with new tests from upstream
# gfortran. There are currently several limitations in the way the annotations
# are parsed and how they are dealt with in the static test
# configuration. These are described in inline comments. The format of the
# static test configuration files is also documented inline.
#
# This script modifies the test configuration files in place. If this is not
# desirable,
#
#   update-test-config.py -h
#
# will provide some other options.

import argparse
import chardet
import os
import re
import shutil
import typing

# Class representing a single test. The fields of the test should be those that
# are eventually serialized into the test configuration. The configuration will
# only contain the test kind, the sources and flags as determined directly
# from the DejaGNU annotations in the corresponding source file(s). Any custom
# handling of the test, e.g. to run it conditionally on some platform, should
# not be present, either in this class or in the generated static test
# configuration file.
class Test:
    def __init__(
        self,
        kind: str,
        sources: list[str],
        options: list[str],
        enabled_on: list[str],
        disabled_on: list[str],
        expected_fail: bool
    ):
        # The kind of the test. This must be one of 'preprocess', 'assemble',
        # 'compile', 'link' or 'run'.
        self.kind: str = kind

        # The sources needed by the test. This will have at least one element.
        # The first element of the list will be the "main" file. The rest must
        # be in the order in which they should be compiled. The elements will be
        # the basenames of the files because all dependent files are in the
        # same directory, so there is no need to have the full (or relative)
        # path.
        self.sources: list[str] = sources

        # The command-line flags that are needed to build the test.
        #
        # FIXME: Currently, only the flags from the main file in multi-file
        # tests are recorded. This might need to be fixed.
        self.options: list[str] = options

        # The optional targets on which the test should be run. The DejaGNU
        # targets annotation can be fairly complex with both wildcards and
        # logical operators, but we will probably only ever handle "simple"
        # targets.
        self.enabled_on: list[str] = enabled_on

        # The targets for which the test should be excluded.
        self.disabled_on: list[str] = disabled_on

        # Whether the test is expected to fail. For run tests, this indicates
        # the presence of a shouldfail annotation. For all other test kinds,
        # a dg-error annotation is present somewhere in the file. In the latter
        # case, the error may only manifest on certain targets, but that should
        # have been captured in the self.enabled_on member of this class.
        self.xfail: bool = expected_fail

    def __eq__(self, other):
        if not isinstance(other, Test):
            return NotImplemented

        return self.kind == other.kind and \
            self.sources == other.sources and \
            self.options == other.options and \
            self.xfail == other.xfail and \
            self.enabled_on == other.enabled_on and \
            self.disabled_on == other.disabled_on

    def __str__(self):
        return ';'.join([
            self.kind,
            ' '.join(self.sources),
            'xfail' if self.xfail else '',
            ' '.join(self.options),
            ' '.join(self.enabled_on),
            ' '.join(self.disabled_on)
        ])

# The strings containing regexes which will be compiled later.
pfx = '[{][ ]*'
sfx = '[ ]*[}]'

# In DejaGNU, braces can be used instead of quotes ... I think.
res = '[{]?[ ]*(.+?)[ ]*[}]?'

# The target is always optional. It also can be fairly complex. This regex is
# definitely not right for the job, but it will catch the simple cases which is
# all we really intend to support anyway.
tgt = f'({pfx}target[ ]*(?P<target>.+){sfx})?'

re_btxt = re.compile('[{][ ]*(.+?)[ ]*[}]')
re_fortran = re.compile('^.+[.][Ff].*$')
re_assemble = re.compile(f'{pfx}dg-(lto-)?do[ ]*assemble{sfx}')
re_preprocess = re.compile(f'{pfx}dg-do[ ]*preprocess{sfx}')
re_compile = re.compile(f'{pfx}dg-do[ ]*compile[ ]*{tgt}{sfx}')
re_link = re.compile(f'{pfx}dg-(lto-)?do[ ]*link[ ]*{tgt}{sfx}')
re_run = re.compile(f'{pfx}dg-(lto-)?do[ ]*run[ ]*{tgt}{sfx}')
re_sources = re.compile(f'{pfx}dg-additional-sources[ ]*{res}{sfx}')
re_aux_modules = re.compile(f'{pfx}dg-compile-aux-modules[ ]*{res}{sfx}')
re_opts = re.compile(f'{pfx}dg-options[ ]*{res}[ ]*{tgt}{sfx}')
re_addnl_opts = re.compile(f'{pfx}dg-additional-options[ ]*{res}[ ]*{tgt}{sfx}')
re_lto_opts = re.compile(
    f'{pfx}dg-lto-options[ ]*'
    f'[{{][ ]*({pfx}.+?{sfx}[ ]*)[ ]*[}}][ ]*'
    f'{tgt}{sfx}'
)
re_ld_opts = re.compile(f'{pfx}dg-extra-ld-options[ ]*{res}[ ]*{tgt}{sfx}')
re_shouldfail = re.compile(f'{pfx}dg-shouldfail[ ]*.*{sfx}')
re_error = re.compile(f'{pfx}dg-error[ ]*.*{tgt}{sfx}')
re_platform = re.compile('^[A-Za-z0-9*?_]+-[A-Za-z0-9*?_]+-[A-Za-z0-9*?_]+$')

# Maps from known platforms to triples that LLVM will understand.
# FIXME: The ia32 target probably does not always correspond to i386. Does it
# means that it will be enabled on other non-X86 platforms?
platforms = {'ia32': 'i386-*-*'}

# Get the n-th level ancestor of the given file. The 1st level ancestor is
# the directory containing the file. The 2nd level ancestor is the parent of
# that directory and so on.
def get_ancestor(f: str, n: int) -> str:
    anc = f
    for _ in range(0, n):
        anc = os.path.dirname(anc)
    return anc

# Get the encoding of the file.
def get_encoding(filepath: str) -> str | None:
    with open(filepath, 'rb') as f:
        return chardet.detect(f.read())['encoding']
    return None

# Get the lines in the file.
def get_lines(filepath: str) -> list[str]:
    lines = []
    try:
        encoding = get_encoding(filepath)
        with open(filepath, 'r', encoding = encoding) as f:
            lines = f.readlines()
    except:
        warning('Could not open file: {}', os.path.basename(filepath))
    finally:
        return lines

# Collect the subdirectories of the gfortran directory which may contain tests.
def get_subdirs(gfortran: str) -> list[str]:
    regression = os.path.join(gfortran, 'regression')
    torture = os.path.join(gfortran, 'torture')

    subdirs = [regression]
    for root, dirs, _ in os.walk(regression):
        subdirs.extend([os.path.join(root, d) for d in dirs])
    subdirs.append(torture)
    for root, dirs, _ in os.walk(torture):
        subdirs.extend([os.path.join(root, d) for d in dirs])
    return subdirs

# Strip any leading and trailing whitespace from the string as well as any
# optional quotes around the string. Then split the string on whitespace and
# return the resulting list.
def qsplit(s: str) -> list[str]:
    s = s.strip()
    if s.startswith('"'):
        s = s[1:]
    if s.endswith('"'):
        s = s[:-1]
    return s.split()

# Drop the leading '{' and trailing '}', if any. This will only drop the
# braces if both are present. The string will be unconditionally stripped of
# leading and trailing whitespace.
def strip_braces(s: str) -> str:
    s = s.strip()
    if s.startswith('{') and s.endswith('}'):
        s = s[1:-1].strip()
    return s

# Try to match the line with the regex. If the line matches, add the match
# object to the MOUT list and return True. Otherwise, leave the MOUT list
# unchanged and return False.
def try_match(regex: re.Pattern, line: str, mout: list[re.Match[str]]) -> bool:
    m = regex.search(line)
    if m:
        mout.append(m)
        return True
    return False

# Count the number of elements in the list that satisfy the predicate.
def count_if(l, predicate):
    return sum(1 for e in l if predicate(e))

# Print a message. This is only around to save a bit of typing.
def printf(fmt: str, *args) -> None:
    print(fmt.format(*args))

# Print a message.
def message(fmt: str, *args) -> None:
    printf(fmt, *args)

# Print a warning message.
def warning(fmt: str, *args) -> None:
    printf('WARNING: ' + fmt, *args)

# Print an error message and exit.
def error(fmt: str, *args) -> None:
    printf('ERROR: ' + fmt, *args)
    exit(1)

# The target is usually a regular expression. But the regex syntax used by
# DejaGNU is not exactly the same as that supported by cmake. This translates
# the DejaGNU regex to a cmake-compatible regex.
def convert_target_regex(t: str) -> str:
    # XXX: This translation is not strictly correct.
    # In DejaGNU, the ? character matches a single character unless it follows
    # an atom. In the target specifications in the gfortran test suite, this is
    # only used as a single character match.
    t = t.replace('?', '.')

    # XXX: This translation is not strictly correct.
    # in DejaGNU, the * character can also be a wildcard match for zero or more
    # characters unless it follows an atom. In the target specifications in the
    # gfortran test suite, it is only used as a wildcard.
    t = t.replace('*', '.+')

    return t

# Parse the enabled targets from a target specification string. Some of the
# targets may require additional compiler/linker options. Those options are
# returned as well.
def parse_enabled_targets(t: str) -> tuple[list[str], list[str]]:
    targets = []
    options = []

    # An expression can be wrapped with braces. While this seems to be necessary
    # for complex expressions, it can be used with simple expressions as well.
    t = strip_braces(t)

    # A simple expression may be a sequence of targets.
    for tgt in t.split(' '):
        if re_platform.match(tgt):
            targets.append(convert_target_regex(tgt))
        elif tgt in platforms:
            targets.append(convert_target_regex(platforms[tgt]))
        # Some "targets" need to be translated to compiler/linker flags.
        elif tgt in ['fopenmp', 'fopenacc', 'pthread']:
            options.append('-' + tgt)
        elif tgt in ['c99_runtime']:
            options.append('-lc')
        elif tgt in [
            'fd_truncate',
            'fortran_large_int',
            'fortran_real_10',
            'fortran_real_16'
        ]:
            # FIXME: These may need something sane to be done.
            pass
        elif tgt in [
            'arm_eabi',
            'avx_runtime',
            'fpic',
            'libatomic_available',
            'vect_simd_clones'
        ]:
            # As far as I can tell, nothing needs to be done for these targets.
            pass
        else:
            warning('Unknown target: {}', tgt)

    return targets, options

# Parse the disabled targets from a target specification string.
def parse_disabled_targets(t: str) -> list[str]:
    targets = []

    # An expression can be wrapped with braces. While this seems to be necessary
    # for complex expressions, it can be used with simple expressions as well.
    t = strip_braces(t)

    # A simple expression may be a sequence of targets.
    for tgt in t.split(' '):
        if re_platform.match(tgt):
            targets.append(convert_target_regex(tgt))
        elif tgt in platforms:
            targets.append(convert_target_regex(platforms[tgt]))
        elif tgt in ['newlib']:
            # FIXME: These may need something sane to be done.
            pass
        else:
            warning('Unknown target to disable: {}', tgt)

    return targets

# Parse the target specification, if possible.
# This is not guaranteed to parse all target specifications. We don't care
# about the arbitrarily complex expressions that seem to be possible, so this
# will only deal with "simple" expressions. Some of the target expressions
# will be translated to compiler/linker flags. In those cases, update the
# list of flags that are passed in.
def parse_targets_into(
    t: str, enabled_on: list[str], disabled_on: list[str], options: list[str]
) -> None:
    t = t.strip()

    # An expression can be wrapped with braces. While this seems to be necessary
    # for complex expressions, it can be used with simple expressions as well.
    t = strip_braces(t)

    # A simple expression is one which does not have any logical operators.
    if ('&&' in t) or ('||' in t):
        warning('Ignoring target specification: {}', t)
        return

    # The only "complex" expression that we handle is a "top-level" negation
    # which excludes certain targets.
    if t.startswith('!'):
        targets = parse_disabled_targets(t[1:].strip())
        disabled_on.extend(targets)
    else:
        targets, opts = parse_enabled_targets(t)
        enabled_on.extend(targets)
        options.extend(opts)

# Collect the tests in a given directory.
def collect_tests(d: str) -> list[Test]:
    tests: list[Test] = []
    files: list[str] = []
    for e in os.scandir(d):
        if e.is_file() and re_fortran.match(e.name):
            files.append(e.path)
    message('Found {} Fortran files', len(files))

    if not len(files):
        return tests

    # Some files cannot be read because they are invalid UTF-16. Just handle
    # those as a special case here. This is a really ugly way of doing things
    # but this script is only intended for occasional use, so I am not too
    # bothered about this.
    remove = []
    for f in files:
        if f.endswith('regression/bom_error.f90'):
            tests.append(
                Test('compile', [os.path.basename(f)], [], [], [], True)
            )
            remove.append(f)
    for f in remove:
        files.remove(f)
    if len(remove):
        message(
            'Filter known problematic files: {}\n  {}',
            len(remove),
            '  \n'.join([os.path.basename(f) for f in remove])
        )

    # Find all the files that are dependencies of some file that is the
    # main file in a test.
    dependents = set([])
    for filename in files:
        for l in get_lines(filename):
            mout: list[re.Match] = []
            if try_match(re_sources, l, mout) or \
               try_match(re_aux_modules, l, mout):
                for m in mout:
                    for src in qsplit(m[1]):
                        dependents.add(src)
    message('Found {} dependent files', len(dependents))

    for f in files:
        filename = os.path.basename(f)
        if filename in dependents:
            continue

        kind: str | None = None
        sources: list[str] = [filename]
        options: list[str] = []
        enabled_on: list[str] = []
        disabled_on: list[str] = []
        xfail: bool = False

        for l in get_lines(f):
            mout = []
            if try_match(re_assemble, l, mout):
                kind = 'assemble'
            elif try_match(re_preprocess, l, mout):
                kind = 'preprocess'
            elif try_match(re_compile, l, mout):
                m = mout[0]
                kind = 'compile'
                if m['target']:
                    parse_targets_into(
                        m['target'], enabled_on, disabled_on, options
                    )
            elif try_match(re_link, l, mout):
                m = mout[0]
                kind = 'link'
                if m['target']:
                    parse_targets_into(
                        m['target'], enabled_on, disabled_on, options
                    )
            elif try_match(re_run, l, mout):
                m = mout[0]
                kind = 'run'
                if m['target']:
                    parse_targets_into(
                        m['target'], enabled_on, disabled_on, options
                    )
                # TODO: Does lto-run need to be handled differently?
            elif try_match(re_shouldfail, l, mout) or \
                 try_match(re_error, l, mout):
                xfail = True
            elif try_match(re_sources, l, mout) or \
                 try_match(re_aux_modules, l, mout):
                m = mout[0]
                sources.extend(qsplit(m[1]))
            elif try_match(re_opts, l, mout) or \
                 try_match(re_addnl_opts, l, mout) or \
                 try_match(re_ld_opts, l, mout):
                m = mout[0]

                # FIXME: This is not correct.
                # If the options have a target annotation, those options should
                # only be added on a specific target. We currently cannot handle
                # this case in the static configuration, so just ignore those
                # options entirely for now.
                if not m['target']:
                    options.extend(qsplit(m[1]))
            elif try_match(re_lto_opts, l, mout):
                m = mout[0]
                # FIXME: There are two sets of options in some files. It is
                # possible that an arbitrary number of these is allowed, but I
                # don't know exactly what it is for, so for now, just use the
                # first set.
                opts = qsplit(re_btxt.findall(m[1])[0])

                # FIXME: This is not correct.
                # If the options have a target annotation, those options should
                # only be added on a specific target. We currently cannot handle
                # this case in the static configuration, so just ignore those
                # options entirely for now.
                if not m['target']:
                    options.extend(opts)

        # If the kind is missing, assume that it is a compile test except
        # for torture/execute where it is an execute test.
        anc1 = os.path.basename(get_ancestor(f, 1))
        anc2 = os.path.basename(get_ancestor(f, 2))
        if not kind:
            if anc2 == 'torture' and anc1 == 'execute':
                kind = 'run'
            else:
                kind = 'compile'

        tests.append(
            Test(kind, sources, options, enabled_on, disabled_on, xfail)
        )

    # Count the fortran files in the tests. Eventually, we want to ensure
    # that all the fortran files are accounted for.
    accounted = set([])
    for test in tests:
        for s in test.sources:
            if re_fortran.match(s):
                accounted.add(s)
    filenames = set([os.path.basename(f) for f in files])
    orphans = filenames - set(accounted)
    if len(orphans):
        error('{} orphan files found\n  {}', len(orphans), '  \n'.join(orphans))

    order = {'preprocess': 0, 'assemble': 1, 'compile': 2, 'link': 3, 'run': 4}
    tests.sort(key = lambda t: (order[t.kind], t.sources[0].lower()))

    return tests

# Parse tests from the given file.
def parse_tests(filename: str) -> list[Test]:
    tests = []
    with open(filename, 'r') as f:
        for lno, l in enumerate(f.readlines()):
            line = l.strip()

            # Lines starting with a # are comment lines.
            if not line or line.startswith('#'):
                continue

            # The format of each non-comment line is specified at the start of
            # this file.
            elems = l.split(';')
            if len(elems) != 6:
                error('{}:{}: Unexpected number of elements', filename, lno + 1)
            if elems[2] not in ['', 'xfail']:
                error(
                    '{}:{}: Expected error field must be xfail or empty',
                    filename,
                    lno + 1
                )

            kind = elems[0]
            sources = elems[1].split(' ')
            xfail = True if elems[2] == 'xfail' else False
            options = elems[3].split(' ')
            enabled_on = elems[4].split(' ')
            disabled_on = elems[5].split(' ')

            tests.append(
                Test(kind, sources, options, enabled_on, disabled_on, xfail)
            )

    return tests

# Setup the argument parser and return it.
def get_argument_parser():
    ap = argparse.ArgumentParser(
        description =
        'Update the static test configuration files in the gfortran tests '
        'within the LLVM test suite. This will update the configuration files '
        'within the repository in which this script is contained.',
    )

    ap.add_argument(
        '-b',
        '--backup',
        default = False,
        action = 'store_true',
        help =
        'create a backup file for each test configuration file before it is '
        'updated'
    )

    return ap

def main() -> int:
    ap = get_argument_parser()
    args = ap.parse_args()

    root = get_ancestor(os.path.realpath(__file__), 4)
    gfortran = os.path.join(root, 'Fortran', 'gfortran')
    dirs = get_subdirs(gfortran)

    stats = {
        'total': 0,
        'preprocess': 0,
        'assemble': 0,
        'compile': 0,
        'link': 0,
        'run': 0
    }
    for d in dirs:
        printf('{}', d)
        tests = collect_tests(d)
        if not tests:
            continue

        existing = []
        config_file = os.path.join(d, 'tests.cmake')
        if os.path.exists(config_file):
            message('Backing up test configuration')
            existing = parse_tests(config_file)
            if args.backup:
                shutil.move(config_file, config_file + '.bak')
        else:
            message('Test configuration not found')

        message('Writing test configuration')
        with open(config_file, 'w') as f:
            f.write("""# This file was generated by update-test-config.py
#
# Each line in this file corresponds to a single test. The format of each line
# is:
#
#     <kind>;<sources>;<xfail>;<options>;<enabled-on>;<disabled-on>
#
# where
#
#     <kind>         is one of 'preprocess', 'assemble', 'compile', 'link' or
#                    'run'.
#
#     <sources>      is a space separated list of sources files that comprise
#                    the test. The first file is the \"main\" file. The rest
#                    of the files must be specified in program compilation
#                    order.
#
#     <xfail>        if present, must be 'xfail' which indicates that the test
#                    is expected to trigger a compile-time or runtime error.
#
#     <options>      is a space separated list of options to be passed to the
#                    compiler when building the test.
#
#     <enabled-on>   is a space-separated list of targets on which the test is
#                    enabled. Each element of the list will be a regular
#                    expression that is expected to match an LLVM target triple.
#                    If no targets are provided, the test is enabled on all
#                    targets.
#
#     <disabled-on>  is a space-separated list of targets on which the test is
#                    disabled. Each element of the list will be a regular
#                    expression that is expected to match an LLVM target triple.
#
""")
            f.write('\n'.join([str(t) for t in tests]))

        stats['total'] += len(tests)
        for k in ['preprocess', 'assemble', 'compile', 'link', 'run']:
            stats[k] += count_if(tests, lambda t: t.kind == k)
        printf('{:16}{}', 'Found tests', len(tests))
        for k in ['preprocess', 'assemble', 'compile', 'link', 'run']:
            printf('  {:14}{}', k, count_if(tests, lambda t: t.kind == k))
        printf('{:16}{}', 'Existing tests', len(existing))
        printf('')

    printf('\nTEST SUITE\n')
    printf('{:16}{}', 'Found tests', stats['total'])
    for k in ['preprocess', 'assemble', 'compile', 'link', 'run']:
        printf('  {:14}{}', k, stats[k])

    return 0

if __name__ == '__main__':
    exit(main())
