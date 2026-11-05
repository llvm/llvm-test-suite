"""Information about the compiler under test, as `run-test-suite.py`
reports it."""
import hashlib
import os
import re

from .util import capture, fatal, logger


def ishexhash(string):
    return len(string) == 40 and \
        len([c
             for c in string
             if c.isdigit() or c in 'abcdef']) == 40


def get_cc_info(path, cc_flags=[]):
    """get_cc_info(path) -> { ... }

    Extract various information on the given compiler and return a dictionary
    of the results."""

    cc = path

    # Interrogate the compiler.
    cc_version = capture([cc, '-v', '-E'] + cc_flags +
                         ['-x', 'c', '/dev/null', '-###'],
                         include_stderr=True).strip()

    # Determine the assembler version, as found by the compiler.
    cc_as_version = capture([cc, "-c", '-Wa,-v', '-o', '/dev/null'] +
                            cc_flags + ['-x', 'assembler', '/dev/null'],
                            include_stderr=True).strip()

    if "clang: error: unsupported argument '-v'" in cc_as_version:
        cc_as_version = "Clang built in."

    # Determine the linker version, as found by the compiler.
    cc_ld_version = capture(([cc, "-Wl,-v", "-dynamiclib"]),
                            include_stderr=True).strip()
    # Extract the default target .ll (or assembly, for non-LLVM compilers).
    cc_target_assembly = capture([cc, '-S', '-flto', '-o', '-'] + cc_flags +
                                 ['-x', 'c', '/dev/null'],
                                 include_stderr=True).strip()

    # Extract the compiler's response to -dumpmachine as the target.
    cc_target = cc_dumpmachine = capture([cc, '-dumpmachine']).strip()

    # Default the target to the response from dumpmachine.
    cc_target = cc_dumpmachine

    # Parse out the compiler's version line and the path to the "cc1" binary.
    cc1_binary = None
    version_ln = None
    cc_name = cc_version_num = cc_build_string = cc_extra = ""
    for ln in cc_version.split('\n'):
        if ' version ' in ln:
            version_ln = ln
        elif 'cc1' in ln or 'clang-cc' in ln:
            m = re.match(r' "?([^"]*)"?.*"?-E"?.*', ln)
            if not m:
                fatal("unable to determine cc1 binary: %r: %r" % (cc, ln))
            cc1_binary, = m.groups()
        elif "-_Amachine" in ln:
            m = re.match(r'([^ ]*) *-.*', ln)
            if not m:
                fatal("unable to determine cc1 binary: %r: %r" % (cc, ln))
            cc1_binary, = m.groups()
    if cc1_binary is None:
        logger.error("unable to find compiler cc1 binary: %r: %r" %
                     (cc, cc_version))
    if version_ln is None:
        logger.error("unable to find compiler version: %r: %r" %
                     (cc, cc_version))
    else:
        m = re.match(r'(.*) version ([^ ]*) +(?:[0-9]+ +)?(\([^(]*\))(.*)',
                     version_ln)
        if m is not None:
            cc_name, cc_version_num, cc_build_string, cc_extra = m.groups()
        else:
            # If that didn't match, try a more basic pattern.
            m = re.match(r'(.*) version ([^ ]*)', version_ln)
            if m is not None:
                cc_name, cc_version_num = m.groups()
            else:
                logger.error("unable to determine compiler version: %r: %r" %
                             (cc, version_ln))
                cc_name = "unknown"

    # Compute normalized compiler name and type. We try to grab source
    # revisions, branches, and tags when possible.
    cc_norm_name = None
    cc_build = None
    cc_src_branch = cc_alt_src_branch = None
    cc_src_revision = cc_alt_src_revision = None
    cc_src_tag = None
    llvm_capable = False
    cc_extra = cc_extra.strip()
    if cc_name == 'icc':
        cc_norm_name = 'icc'
        cc_build = 'PROD'
        cc_src_tag = cc_version_num

    elif cc_name == 'gcc' and (cc_extra == '' or
                               cc_extra == '(GCC)' or
                               re.match(r' \(dot [0-9]+\)', cc_extra)):
        cc_norm_name = 'gcc'
        m = re.match(r'\(Apple Inc. build ([0-9]*)\)', cc_build_string)
        if m:
            cc_build = 'PROD'
            cc_src_tag, = m.groups()
        elif 'experimental' in cc_build_string:
            cc_build = 'DEV'
        else:
            cc_build = 'PROD'
    elif (cc_name in ('clang', 'LLVM', 'Debian clang', 'Apple clang',
                      'Apple LLVM') and
          (cc_extra == '' or 'based on LLVM' in cc_extra or
           (cc_extra.startswith('(') and cc_extra.endswith(')')))):
        llvm_capable = True
        if cc_name == 'Apple clang' or cc_name == 'Apple LLVM':
            cc_norm_name = 'apple_clang'
        else:
            cc_norm_name = 'clang'

        m = re.match(r'\(([^ ]*)( ([0-9]+))?\)', cc_build_string)
        if m:
            cc_src_branch, _, cc_src_revision = m.groups()

            # With a CMake build, the branch is not emitted.
            if cc_src_branch and not cc_src_revision and \
                    cc_src_branch.isdigit():
                cc_src_revision = cc_src_branch
                cc_src_branch = ""

            # These show up with git-svn.
            if cc_src_branch == '$URL$':
                cc_src_branch = ""
        else:
            # Otherwise, see if we can match a branch and a tag name. That
            # could be a git hash.
            m = re.match(r'\((.+) ([^ ]+)\)', cc_build_string)
            if m:
                cc_src_branch, cc_src_revision = m.groups()
            else:
                logger.error('unable to determine '
                             'Clang development build info: %r' %
                             ((cc_name, cc_build_string, cc_extra),))
                cc_src_branch = ""

        m = re.search('clang-([0-9.]*)', cc_src_branch)
        if m:
            cc_build = 'PROD'
            cc_src_tag, = m.groups()

            # We sometimes use a tag of 9999 to indicate a dev build.
            if cc_src_tag == '9999':
                cc_build = 'DEV'
        else:
            cc_build = 'DEV'
    elif cc_name == 'gcc' and 'LLVM build' in cc_extra:
        llvm_capable = True
        cc_norm_name = 'llvm-gcc'
        m = re.match(r' \(LLVM build ([0-9.]+)\)', cc_extra)
        if m:
            llvm_build, = m.groups()
            if llvm_build:
                cc_src_tag = llvm_build.strip()
            cc_build = 'PROD'
        else:
            cc_build = 'DEV'
    else:
        logger.error("unable to determine compiler name: %r" %
                     ((cc_name, cc_build_string),))

    if cc_build is None:
        logger.error("unable to determine compiler build: %r" % cc_version)

    # If LLVM capable, fetch the llvm target instead.
    if llvm_capable:
        m = re.search('target triple = "(.*)"', cc_target_assembly)
        if m:
            cc_target, = m.groups()
        else:
            logger.error("unable to determine LLVM compiler target: %r: %r" %
                         (cc, cc_target_assembly))

    cc_exec_hash = hashlib.sha1()
    with open(cc, 'rb') as f:
        cc_exec_hash.update(f.read())

    info = {
        'cc_build': cc_build,
        'cc_name': cc_norm_name,
        'cc_version_number': cc_version_num,
        'cc_dumpmachine': cc_dumpmachine,
        'cc_target': cc_target,
        'cc_version': cc_version,
        'cc_exec_hash': cc_exec_hash.hexdigest(),
        'cc_as_version': cc_as_version,
        'cc_ld_version': cc_ld_version,
        'cc_target_assembly': cc_target_assembly,
    }
    if cc1_binary is not None and os.path.exists(cc1_binary):
        cc1_exec_hash = hashlib.sha1()
        cc1_exec_hash.update(open(cc1_binary, 'rb').read())
        info['cc1_exec_hash'] = cc1_exec_hash.hexdigest()
    if cc_src_tag is not None:
        info['cc_src_tag'] = cc_src_tag
    if cc_src_revision is not None:
        info['cc_src_revision'] = cc_src_revision
    if cc_src_branch:
        info['cc_src_branch'] = cc_src_branch
    if cc_alt_src_revision is not None:
        info['cc_alt_src_revision'] = cc_alt_src_revision
    if cc_alt_src_branch is not None:
        info['cc_alt_src_branch'] = cc_alt_src_branch

    # Infer the run order from the other things we have computed.
    info['inferred_run_order'] = get_inferred_run_order(info)

    return info


def get_inferred_run_order(info):
    # If the CC has an integral src revision, use that.
    if info.get('cc_src_revision', '').isdigit():
        order = int(info['cc_src_revision'])

        # If the CC has an alt src revision, use that if it is greater:
        if info.get('cc_alt_src_revision', '').isdigit():
            order = max(order, int(info.get('cc_alt_src_revision')))

        return str(order)

    # Otherwise if we have a git hash, use that
    if ishexhash(info.get('cc_src_revision', '')):
        # If we also have an alt src revision, combine them.
        #
        # We don't try and support a mix of integral and hash revisions.
        if ishexhash(info.get('cc_alt_src_revision', '')):
            return '%s,%s' % (info['cc_src_revision'],
                              info['cc_alt_src_revision'])

        return info['cc_src_revision']

    # If this is a production compiler, look for a source tag. We don't accept
    # 0 or 9999 as valid source tag, since that is what llvm-gcc builds use
    # when no build number is given.
    if info.get('cc_build') == 'PROD':
        m = re.match(r'^[0-9]+(.[0-9]+)*$', info.get('cc_src_tag', ''))
        if m:
            return m.group(0)

    # If that failed, infer from the LLVM revision (if specified on input).
    #
    # FIXME: We should remove this eventually.
    if info.get('llvm_revision', '').isdigit():
        return info['llvm_revision']

    # Otherwise, force at least some value for run_order, as it is now
    # generally required by parts of the "simple" schema.
    return '0'


def infer_cxx_compiler(cc_path):
    # If this is obviously a compiler name, then try replacing with the '++'
    # name.
    name = os.path.basename(cc_path)
    if 'clang' in name:
        expected_cxx_name = 'clang++'
        cxx_name = name.replace('clang', expected_cxx_name)
    elif 'gcc' in name:
        expected_cxx_name = 'g++'
        cxx_name = name.replace('gcc', expected_cxx_name)
    elif 'icc' in name:
        expected_cxx_name = 'icpc'
        cxx_name = name.replace('icc', expected_cxx_name)
    else:
        # We have no idea, give up.
        return None

    # Check if the compiler exists at that path.
    cxx_path = os.path.join(os.path.dirname(cc_path), cxx_name)
    if os.path.exists(cxx_path):
        return cxx_path

    # Otherwise, try to let the compiler itself tell us what the '++' version
    # would be. This is useful when the compiler under test is a symlink to the
    # real compiler.
    cxx_path = capture([cc_path,
                        '-print-prog-name=%s' % expected_cxx_name]).strip()
    if os.path.exists(cxx_path):
        return cxx_path
