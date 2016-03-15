"""
Datastructures for test plans; Parsing of .test files; Executing test plans.
"""
from lit.TestRunner import parseIntegratedTestScriptCommands
import lit.Test
import lit.TestRunner
import logging
import os
import shellcommand


class TestPlan(object):
    def __init__(self, runscript, verifyscript, metricscripts):
        self.runscript = runscript
        self.verifyscript = verifyscript
        self.metricscripts = metricscripts
        self.metric_collectors = []
        self.profilescript = []


def mutateScript(context, script, mutator):
    previous_tmpbase = context.tmpBase
    i = 0
    mutated_script = []
    for line in script:
        number = ""
        if len(script) > 1:
            number = "-%s" % (i,)
            i += 1
        context.tmpBase = previous_tmpbase + number

        mutated_line = mutator(context, line)
        mutated_script.append(mutated_line)
    return mutated_script


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

    return TestPlan(runscript, verifyscript, metricscripts)


def executeScript(context, script, useExternalSh=True):
    if len(script) == 0:
        return "", "", 0, None

    execdir = os.path.dirname(context.test.getExecPath())
    executeFunc = lit.TestRunner.executeScriptInternal
    if useExternalSh:
        executeFunc = lit.TestRunner.executeScript

    res = executeFunc(context.test, context.litConfig, context.tmpBase, script,
                      execdir)
    # The executeScript() functions return lit.Test.Result in some error
    # conditions instead of the normal tuples. Having different return types is
    # really annoying so we transform it back to the usual tuple.
    if isinstance(res, lit.Test.Result):
        out = ""
        err = res.output
        exitCode = 1
        timeoutInfo = None
    else:
        (out, err, exitCode, timeoutInfo) = res

    # Log script in test output
    context.result_output += "\n" + "\n".join(script)
    # In case of an exitCode != 0 also log stdout/stderr
    if exitCode != 0:
        context.result_output += "\n" + out
        context.result_output += "\n" + err

    return (out, err, exitCode, timeoutInfo)


def executePlan(context, plan):
    """This is the main driver for executing a benchmark."""
    # Execute RUN: part of the test file.
    _, _, exitCode, _ = executeScript(context, plan.runscript)
    if exitCode != 0:
        return lit.Test.FAIL

    # Execute VERIFY: part of the test file.
    _, _, exitCode, _ = executeScript(context, plan.verifyscript)
    if exitCode != 0:
        # The question here is whether to still collects metrics if the
        # benchmark results are invalid. I choose to avoid getting potentially
        # broken metric values as well for a broken test.
        return lit.Test.FAIL

    # Perform various metric extraction steps setup by testing modules.
    for metric_collector in plan.metric_collectors:
        try:
            additional_metrics = metric_collector(context)
            for metric, value in additional_metrics.items():
                context.result_metrics[metric] = value
        except Exception as e:
            logging.error("Could not collect metric with %s", metric_collector,
                          exc_info=e)

    # Execute the METRIC: part of the test file.
    for metric, metricscript in plan.metricscripts.items():
        out, err, exitCode, timeoutInfo = executeScript(context, metricscript)
        if exitCode != 0:
            logging.warning("Metric script for '%s' failed", metric)
            continue
        try:
            value = float(out)
            context.result_metrics[metric] = value
        except ValueError:
            logging.warning("Metric reported for '%s' is not a float: '%s'",
                            metric, out)

    # Execute additional profile gathering actions setup by testing modules.
    _, _, exitCode, _ = executeScript(context, plan.profilescript) 
    if exitCode != 0:
        logging.warning("Profile script '%s' failed", plan.profilescript)

    return lit.Test.PASS


def executePlanTestResult(context, testplan):
    """Convenience function to invoke executePlan() and construct a
    lit.test.Result() object for the results."""
    context.result_output = ""
    context.result_metrics = {}

    result_code = executePlan(context, testplan)

    # Build test result object
    result = lit.Test.Result(result_code, context.result_output)
    for key, value in context.result_metrics.items():
        result.addMetric(key, value)
    return result
