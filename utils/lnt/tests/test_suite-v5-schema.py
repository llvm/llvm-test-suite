# Check that schema.json declares exactly the metrics the report for LNT v5
# can have, with the types of their values.
#
# RUN: %{python} %s %S/../schema.json

import json
import sys

from test_suite_runner.report_v5 import (BUILD_METRICS, METRICS,
                                        STATUS_METRIC, UNMEASURED_IF_ZERO)

TYPES = {float: 'real', int: 'integer', str: 'text'}

with open(sys.argv[1]) as f:
    schema = json.load(f)
assert schema['name'] == 'llvm_test_suite', schema['name']

declared = {metric['name']: metric['type'] for metric in schema['metrics']}
reported = {name: TYPES[kind] for name, kind in METRICS.values()}
reported[STATUS_METRIC] = 'text'
if declared != reported:
    raise AssertionError('schema.json declares %r, but the report has %r' %
                         (declared, reported))
assert BUILD_METRICS <= reported.keys(), BUILD_METRICS
assert UNMEASURED_IF_ZERO <= reported.keys(), UNMEASURED_IF_ZERO
