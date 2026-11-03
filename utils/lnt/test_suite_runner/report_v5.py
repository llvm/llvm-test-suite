"""The report written by `run-test-suite.py --report-format v5`.

The report is a run submission in the format of LNT v5, for the test suite
whose schema is `schema.json`, one level up. It is written on a single line, so
that the file can be given to `lnt v5 submit` as is.
"""
import json
import math

from .util import logger

# How each metric reported by lit becomes a metric of the report: its name in
# the report, and the Python type of its values. Metrics not listed here are
# left out.
METRICS = {
    'exec_time': ('execution_time', float),
    'compile_time': ('compile_time', float),
    'link_time': ('link_time', float),
    'compile_maxrss': ('compile_peak_memory', int),
    'link_maxrss': ('link_peak_memory', int),
    # The text section is named `.text` in ELF and `__text` in Mach-O.
    'size..text': ('code_size', int),
    'size.__text': ('code_size', int),
    'size': ('binary_size', int),
    'score': ('score', float),
    'hash': ('hash', str),
}

# Every sample also has the test's lit result code, e.g. PASS or NOEXE.
STATUS_METRIC = 'status'

# The metric of a lit test that holds the path of the profile gathered for it.
PROFILE_METRIC = 'profile'

# The metrics measured when building the tests. The tests are not rebuilt for
# every lit run, and each lit run reports the measurements of the last build,
# so they are kept only in the first sample of each build.
BUILD_METRICS = {'compile_time', 'link_time', 'compile_peak_memory',
                 'link_peak_memory'}

# The peak memory is only measured with TEST_SUITE_REPORT_COMPILE_MAX_RSS, and
# reported as 0 otherwise.
UNMEASURED_IF_ZERO = {'compile_peak_memory', 'link_peak_memory'}

# The run parameters taken from the compiler information, by their key in
# get_cc_info's results.
RUN_PARAMETERS = {
    'cc_version': 'compiler_version',
    'cc_target': 'target',
    'cc1_exec_hash': 'compiler_hash',
}

# The longest machine name, commit value or test name a v5 instance accepts.
MAX_NAME_LENGTH = 256

# The largest request a v5 instance accepts by default, in bytes. The limit is
# configurable, so a larger report is not necessarily refused.
DEFAULT_BODY_LIMIT = 128 * 1024 * 1024


def check_url_name(name, what):
    """Return why `name` cannot be a name that LNT v5 uses in URL paths, i.e.
    a machine name or a commit value, or None if it can."""
    if not name or len(name) > MAX_NAME_LENGTH:
        return '%s must be 1 to %d characters long' % (
            what, MAX_NAME_LENGTH)
    if '/' in name or '%' in name or name in ('.', '..'):
        return "%s cannot contain '/' or '%%', or be '.' or '..'" % what
    return None


def _test_name(lit_name):
    """The name of a test in the report: lit's name without the test suite's
    name and the `.test` suffix, as in the reports for LNT v4 (without
    `nts.`)."""
    name = lit_name.split(' :: ', 1)[-1]
    if name.endswith('.test'):
        name = name[:-len('.test')]
    return name


def profile_paths(report):
    """The paths of the profiles gathered by a lit run, whose JSON report is
    `report`, by the name of their test in the report."""
    return {_test_name(test['name']): test['metrics'][PROFILE_METRIC]
            for test in report['tests']
            if PROFILE_METRIC in test.get('metrics', {})}


def _value(value, kind):
    """`value` as a value of type `kind`, or None if it is not one."""
    if isinstance(value, bool):
        return None
    if kind is str:
        return value if isinstance(value, str) and value else None
    if not isinstance(value, (int, float)) or not math.isfinite(value):
        return None
    if kind is int:
        return int(value) if value == int(value) else None
    return float(value)


def _sample(test, keep_build_metrics):
    """The sample of one lit run of `test`, a test of lit's JSON report."""
    sample = {}
    for key, value in test.get('metrics', {}).items():
        if key not in METRICS:
            continue
        name, kind = METRICS[key]
        if name in BUILD_METRICS and not keep_build_metrics:
            continue
        converted = _value(value, kind)
        if converted is None:
            logger.warning('Leaving out %s of %s: %r is not a valid value' %
                           (name, test['name'], value))
            continue
        if name in UNMEASURED_IF_ZERO and converted == 0:
            continue
        sample[name] = converted
    sample = dict(sorted(sample.items()))
    sample[STATUS_METRIC] = test['code']
    return sample


def _version_line(cc_version):
    """The line of `cc -v` that says which version the compiler is."""
    lines = cc_version.splitlines()
    for line in lines:
        if ' version ' in line:
            return line
    return lines[0] if lines else ''


def build_submission(run_uuid, measured_at, machine, commit, ordinal, cc_info,
                     lit_runs, profiles):
    """Build the run submission of the lit runs `lit_runs`, a list of
    `(report, build)` pairs: lit's JSON report, and the build it ran the
    tests of, which is the same for the lit runs that did not rebuild the
    tests. Each lit run is one sample of each of its tests.

    `profiles` maps the name of a test in the report to its profile, in the
    form a test's profile has in a submission."""
    samples = {}
    seen_builds = set()
    for report, build in lit_runs:
        keep_build_metrics = build not in seen_builds
        seen_builds.add(build)
        for test in report['tests']:
            name = _test_name(test['name'])
            samples.setdefault(name, []).append(
                _sample(test, keep_build_metrics))

    tests = []
    for name, test_samples in sorted(samples.items()):
        # Unlike machine names and commit values, test names can contain '/'
        # and '%', since they never appear in URL paths.
        if not name or len(name) > MAX_NAME_LENGTH:
            logger.warning('Leaving out %r: test names must be 1 to %d '
                           'characters long' % (name, MAX_NAME_LENGTH))
            continue
        test = {'name': name, 'samples': test_samples}
        if name in profiles:
            test['profile'] = profiles[name]
        tests.append(test)

    run_parameters = {}
    for key, name in RUN_PARAMETERS.items():
        value = cc_info.get(key)
        if key == 'cc_version' and value:
            value = _version_line(value)
        if value:
            run_parameters[name] = value

    commit_object = {'value': commit}
    if ordinal is not None:
        commit_object['ordinal'] = ordinal

    return {
        'format_version': '5',
        'uuid': run_uuid,
        'measured_at': measured_at.strftime('%Y-%m-%dT%H:%M:%SZ'),
        'machine': {'name': machine},
        'commit': commit_object,
        'run_parameters': run_parameters,
        'tests': tests,
    }


def render(submission):
    """The report: `submission` as JSON, on a single line."""
    return json.dumps(submission, allow_nan=False,
                      separators=(',', ':')) + '\n'
