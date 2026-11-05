"""The report written by `run-test-suite.py`.

The report is written in version 1 of LNT's report format.
"""
import json

# Sample values of the status metrics, by convention.
PASS = 0
FAIL = 1
XFAIL = 2


class Machine:
    """The machine the tests ran on."""

    def __init__(self, name):
        self.name = str(name)

    def render(self):
        return {'Name': self.name, 'Info': {}}


class Run:
    """The run of the tests: when it happened, and what was tested."""

    def __init__(self, start_time, end_time, info):
        self.start_time = start_time
        self.end_time = end_time
        self.info = dict((str(key), str(value)) for key, value in info.items())

    def render(self):
        info = dict(self.info)
        info['__report_version__'] = '1'
        return {'Start Time': self.start_time,
                'End Time': self.end_time,
                'Info': info}


class TestSamples:
    """The samples of one metric of one test. The metric is part of the name,
    e.g. nts.foo.exec."""

    def __init__(self, name, data, conv_f=float):
        self.name = str(name)
        self.data = list(map(conv_f, data))

    def render(self):
        return {'Name': self.name, 'Info': {}, 'Data': self.data}


class Report:
    """A machine, a run, and the samples collected during that run."""

    def __init__(self, machine, run, tests):
        self.machine = machine
        self.run = run
        self.tests = list(tests)

    def render(self):
        return json.dumps({'Machine': self.machine.render(),
                           'Run': self.run.render(),
                           'Tests': [t.render() for t in self.tests]},
                          sort_keys=True, indent=4)
