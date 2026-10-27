# Check that `run-test-suite.py` renders its report exactly as before:
# downstream tools read and rewrite report.json, so its contents must not
# change.
#
# RUN: %{python} %s

from test_suite_runner.report import FAIL, Machine, Report, Run, TestSamples

machine = Machine('my-machine')
run = Run('2026-10-19 12:00:00', '2026-10-19 12:30:05',
          info={'tag': 'nts', 'run_order': '154331', 'no_errors': False,
                'cc_version_number': 3.1})
tests = [TestSamples('nts.foo.exec', ['1.4', 2], float),
         TestSamples('nts.foo.hash', ['xyz'], str),
         TestSamples('nts.bar.exec.status', [FAIL]),
         TestSamples('nts.foo.profile', ['eJxLz8/PSQEABk4CLA=='], str)]

EXPECTED = """\
{
    "Machine": {
        "Info": {},
        "Name": "my-machine"
    },
    "Run": {
        "End Time": "2026-10-19 12:30:05",
        "Info": {
            "__report_version__": "1",
            "cc_version_number": "3.1",
            "no_errors": "False",
            "run_order": "154331",
            "tag": "nts"
        },
        "Start Time": "2026-10-19 12:00:00"
    },
    "Tests": [
        {
            "Data": [
                1.4,
                2.0
            ],
            "Info": {},
            "Name": "nts.foo.exec"
        },
        {
            "Data": [
                "xyz"
            ],
            "Info": {},
            "Name": "nts.foo.hash"
        },
        {
            "Data": [
                1.0
            ],
            "Info": {},
            "Name": "nts.bar.exec.status"
        },
        {
            "Data": [
                "eJxLz8/PSQEABk4CLA=="
            ],
            "Info": {},
            "Name": "nts.foo.profile"
        }
    ]
}"""

actual = Report(machine, run, tests).render()
assert actual == EXPECTED, actual
