# Check the compiler version sniffing of `run-test-suite.py`.
#
# RUN: %{python} %s %S/Inputs/FakeCompilers

import logging
import os
import pprint
import sys

from test_suite_runner.compilers import get_cc_info

basedir = sys.argv[1]

logging.basicConfig(level=logging.DEBUG)


def get_info(name):
    logging.info("checking compiler: %r", name)
    return get_cc_info(os.path.join(basedir, name))


# Check icc.
info = get_info("icc-12.1.3")
pprint.pprint(info)
assert info['cc_name'] == 'icc'
assert info['cc_build'] == 'PROD'
assert info['cc_target'] == 'i686-apple-darwin11'
assert info['inferred_run_order'] == '12.1.3'

# Check a random Clang from SVN.
info = get_info("clang-r154331")
pprint.pprint(info)
assert info['cc_name'] == 'clang'
assert info['cc_build'] == 'DEV'
assert info['inferred_run_order'] == '154331'

# Check an Apple Clang.
info = get_info("apple-clang-138.1")
pprint.pprint(info)
assert info['cc_name'] == 'apple_clang'
assert info['cc_build'] == 'PROD'
assert info['inferred_run_order'] == '138.1'

# Check a monorepo Clang.
info = get_info("clang-monorepo")
pprint.pprint(info)
assert info['cc_name'] == 'clang'
assert info['cc_build'] == 'DEV'
assert info['cc_src_branch'] == 'ssh://something.com/llvm-project.git'
assert info['cc_src_revision'] == '597522d740374f093a089a2acbec5b20466b2f34'
assert info['inferred_run_order'] == info['cc_src_revision']
assert info['cc_version_number'] == '1.2.3'

# Same as clang-monorepo, except the version string has some extra parens at
# the end. Verify that we can still match this.
info = get_info("clang-monorepo2")
pprint.pprint(info)
assert info['cc_src_branch'] == 'ssh://something.com/llvm-project.git'
assert info['cc_src_revision'] == '597522d740374f093a089a2acbec5b20466b2f34'
assert info['inferred_run_order'] == info['cc_src_revision']
assert info['cc_version_number'] == '1.2.3'

# Check a Clang that prints no info.
info = get_info("clang-no-info")
pprint.pprint(info)
assert info['cc_name'] == 'clang'
assert info['cc_version_number'] == '3.2'

# Check a GCC packaged from Debian.
info = get_info("gcc-debian")
pprint.pprint(info)
assert info['cc_name'] == 'gcc'
assert info['cc_build'] == 'PROD'
assert info['cc_version_number'] == '12.2.0'
assert info['cc_target'] == 'x86_64-linux-gnu'

# Check a GCC built from trunk.
info = get_info("gcc-trunk")
pprint.pprint(info)
assert info['cc_name'] == 'gcc'
assert info['cc_build'] == 'DEV'
assert info['cc_version_number'] == '16.0.0'
assert info['cc_target'] == 'x86_64-linux-gnu'
