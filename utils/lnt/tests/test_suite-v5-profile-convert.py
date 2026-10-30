# Check how `run-test-suite.py` converts a single profile for the report for
# LNT v5 with `lnt v5 convert-profile`.
#
# RUN: rm -rf %t && mkdir -p %t
# RUN: %{python} %s %S/Inputs/test-suite-cmake/fake-lnt-v5-profile %t

import logging
import os
import sys
import time

from test_suite_runner import _convert_profile_v5
from test_suite_runner.util import logger

lnt, tmpdir = sys.argv[1:]
profile = os.path.join(tmpdir, 'bench.perf_data')
with open(profile, 'w') as f:
    f.write('fake perf data\n')


class Recorder(logging.Handler):
    def __init__(self):
        super().__init__()
        self.messages = []

    def emit(self, record):
        self.messages.append(record.getMessage())


recorder = Recorder()
logger.addHandler(recorder)


def convert(mode, path=profile, objdump='/usr/bin/objdump', timeout=60):
    os.environ['FAKE_LNT_MODE'] = mode
    recorder.messages = []
    return _convert_profile_v5(lnt, objdump, path, timeout)


# The profile is what `lnt` prints, without its newline. The objdump is only
# given to `lnt` when there is one.
log = os.path.join(tmpdir, 'log')
os.environ['FAKE_LNT_LOG'] = log
assert convert('') == 'encoded:bench.perf_data'
assert convert('', objdump=None) == 'encoded:bench.perf_data'
assert recorder.messages == []
with open(log) as f:
    assert f.read().splitlines() == [
        'v5 convert-profile --encode --objdump /usr/bin/objdump ' + profile,
        'v5 convert-profile --encode ' + profile,
    ]
del os.environ['FAKE_LNT_LOG']

# What `lnt` warns about is logged.
assert convert('warn') == 'encoded:bench.perf_data'
assert recorder.messages == [
    'Converting profile %s:\nwarning: the profile lists no function\n' %
    profile], recorder.messages

# A profile that cannot be converted is None, with a warning.
assert convert('fail') is None
assert recorder.messages == [
    'Profile %s could not be converted:\nerror: cannot read the profile\n' %
    profile], recorder.messages

missing = os.path.join(tmpdir, 'missing.perf_data')
assert convert('', path=missing) is None
assert recorder.messages == ['Profile %s does not exist' % missing]

# A conversion that takes too long is stopped.
start = time.monotonic()
assert convert('sleep', timeout=1) is None
assert time.monotonic() - start < 20
assert recorder.messages == [
    'Profile %s could not be converted within 1 seconds' % profile]
