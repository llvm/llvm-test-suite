# Check how `run-test-suite.py` builds the report for LNT v5 from lit's JSON
# reports.
#
# RUN: %{python} %s

import datetime
import json

from test_suite_runner.report_v5 import build_submission, render


def test(name, code, **metrics):
    return {'name': 'test-suite :: ' + name, 'code': code, 'metrics': metrics}


long_name = 'SingleSource/' + 'x' * 250 + '.test'
first_build = {'tests': [
    test('B/b.test', 'PASS', compile_time=2.0, link_time=0.5, exec_time=1,
         compile_maxrss=4096, link_maxrss=0, size=100, **{'size..text': 50}),
    test('A/a.test', 'PASS', compile_time=1.0, exec_time=3.5,
         score=float('nan'), hash='', **{'size.__text': 8.5}),
    test('A/a.test:BM_A/8', 'PASS', exec_time=0.25),
    test('C/c.test', 'NOEXE'),
    test(long_name, 'PASS', exec_time=1.0),
]}
second_run = {'tests': [
    test('B/b.test', 'FAIL', compile_time=2.0, link_time=0.5, exec_time=1.5,
         size=100, score='not a number', hash=True, **{'size..text': 50}),
]}
rebuilt = {'tests': [
    test('B/b.test', 'PASS', compile_time=2.5, link_time=0.75, exec_time=2.0,
         size=100, **{'size..text': 50}),
]}

cc_info = {
    'cc_name': 'gcc', 'cc_build': 'PROD', 'cc_version_number': '12.2.0',
    'cc_version': 'Using built-in specs.\nCOLLECT_GCC=gcc\n'
                  'gcc version 12.2.0 (Debian 12.2.0-14)\n...',
    'cc_target': 'x86_64-pc-linux-gnu', 'cc_dumpmachine': 'x86_64-linux-gnu',
    'cc_exec_hash': 'aaaa', 'cc1_exec_hash': 'bbbb',
    'cc_as_version': 'GNU assembler 2.40',
    'inferred_run_order': '0',
}

submission = build_submission(
    '573af861-8303-4a5b-a643-b8321e0142c4',
    datetime.datetime(2026, 10, 27, 14, 2, 17, tzinfo=datetime.timezone.utc),
    'my-machine', 'abc123', None, cc_info,
    [(first_build, 1), (second_run, 1), (rebuilt, 2)])

EXPECTED = {
    'format_version': '5',
    'uuid': '573af861-8303-4a5b-a643-b8321e0142c4',
    'measured_at': '2026-10-27T14:02:17Z',
    'machine': {'name': 'my-machine'},
    'commit': {'value': 'abc123'},
    'run_parameters': {
        'compiler_version': 'gcc version 12.2.0 (Debian 12.2.0-14)',
        'target': 'x86_64-pc-linux-gnu',
        'compiler_hash': 'bbbb',
    },
    'tests': [
        # Invalid values are left out: a NaN, an empty hash, and a code size
        # that isn't a whole number.
        {'name': 'A/a', 'samples': [
            {'compile_time': 1.0, 'execution_time': 3.5, 'status': 'PASS'},
        ]},
        {'name': 'A/a.test:BM_A/8', 'samples': [
            {'execution_time': 0.25, 'status': 'PASS'},
        ]},
        # The second lit run did not rebuild the tests, so its measurements of
        # the build are left out. A peak memory of 0 was not measured.
        {'name': 'B/b', 'samples': [
            {'binary_size': 100, 'code_size': 50, 'compile_peak_memory': 4096,
             'compile_time': 2.0, 'execution_time': 1.0, 'link_time': 0.5,
             'status': 'PASS'},
            {'binary_size': 100, 'code_size': 50, 'execution_time': 1.5,
             'status': 'FAIL'},
            {'binary_size': 100, 'code_size': 50, 'compile_time': 2.5,
             'execution_time': 2.0, 'link_time': 0.75, 'status': 'PASS'},
        ]},
        {'name': 'C/c', 'samples': [{'status': 'NOEXE'}]},
        # The test whose name is too long is left out.
    ],
}

if submission != EXPECTED:
    raise AssertionError('unexpected submission:\n%s' %
                         json.dumps(submission, indent=2))
# Integer metrics are integers, so that their JSON has no fractional part.
assert type(submission['tests'][2]['samples'][0]['code_size']) is int
assert type(submission['tests'][2]['samples'][0]['execution_time']) is float

rendered = render(submission)
assert rendered.endswith('\n') and '\n' not in rendered[:-1], rendered
assert json.loads(rendered) == EXPECTED

# The ordinal is only there when it is given.
with_ordinal = build_submission(
    '573af861-8303-4a5b-a643-b8321e0142c4', datetime.datetime.now(),
    'my-machine', 'abc123', 42, {}, [])
assert with_ordinal['commit'] == {'value': 'abc123', 'ordinal': 42}
assert with_ordinal['run_parameters'] == {} and with_ordinal['tests'] == []
