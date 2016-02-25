# Code to parse .test files
from lit.TestRunner import parseIntegratedTestScriptCommands
import lit.Test


def _parseShellCommand(script, ln):
    # Trim trailing whitespace.
    ln = ln.rstrip()

    # Collapse lines with trailing '\\'.
    if script and script[-1][-1] == '\\':
        script[-1] = script[-1][:-1] + ln
    else:
        script.append(ln)


def parse(filename):
    """Parse a .test file as used in the llvm test-suite.
    The file comporises of a number of lines starting with RUN: and VERIFY:
    specifying shell commands to run the benchmark and verifying the result.
    Returns a tuple with two arrays for the run and verify commands."""
    # Collect the test lines from the script.
    runscript = []
    verifyscript = []
    metricscripts = {}
    keywords = ['RUN:', 'VERIFY:', 'METRIC:']
    for line_number, command_type, ln in \
            parseIntegratedTestScriptCommands(filename, keywords):
        if command_type == 'RUN':
            _parseShellCommand(runscript, ln)
        elif command_type == 'VERIFY':
            _parseShellCommand(verifyscript, ln)
        elif command_type == 'METRIC':
            metric, ln = ln.split(':', 1)
            metricscript = metricscripts.setdefault(metric.strip(), list())
            _parseShellCommand(metricscript, ln)
        else:
            raise ValueError("unknown script command type: %r" % (
                             command_type,))

    # Verify the script contains a run line.
    if runscript == []:
        raise ValueError("Test has no RUN: line!")

    # Check for unterminated run lines.
    for script in runscript, verifyscript:
        if script and script[-1][-1] == '\\':
            raise ValueError("Test has unterminated RUN/VERIFY lines " +
                             "(ending with '\\')")

    return runscript, verifyscript, metricscripts
