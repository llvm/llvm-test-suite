"""
Datastructures for test plans; Parsing of .test files; Executing test plans.
"""
from litsupport import shellcommand
import lit.Test
import lit.TestRunner
import logging
import os
import subprocess


class TestPlan(object):
    def __init__(self):
        self.runscript = []
        self.verifyscript = []
        self.metricscripts = {}
        self.metric_collectors = []
        self.preparescript = []
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


def executeScript(context, script, scriptBaseName, useExternalSh=True):
    if len(script) == 0:
        return "", "", 0, None

    if useExternalSh:
        execdir = None
        executeFunc = lit.TestRunner.executeScript
    else:
        execdir = os.getcwd()
        executeFunc = lit.TestRunner.executeScriptInternal

    logging.info("\n".join(script))
    res = executeFunc(context.test, context.litConfig,
                      context.tmpBase + "_" + scriptBaseName, script, execdir)
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

    logging.info(out)
    logging.info(err)
    if exitCode != 0:
        logging.info("ExitCode: %s" % exitCode)
    return (out, err, exitCode, timeoutInfo)


def check_output(commandline, *aargs, **dargs):
    """Wrapper around subprocess.check_output that logs the command."""
    logging.info(" ".join(commandline))
    return subprocess.check_output(commandline, *aargs, **dargs)


def check_call(commandline, *aargs, **dargs):
    """Wrapper around subprocess.check_call that logs the command."""
    logging.info(" ".join(commandline))
    return subprocess.check_call(commandline, *aargs, **dargs)


def executePlan(context, plan):
    """This is the main driver for executing a benchmark."""
    # Execute PREPARE: part of the test.
    _, _, exitCode, _ = executeScript(context, plan.preparescript, "prepare")
    if exitCode != 0:
        return lit.Test.FAIL

    # Execute RUN: part of the test.
    _, _, exitCode, _ = executeScript(context, plan.runscript, "run")
    if exitCode != 0:
        return lit.Test.FAIL

    # Execute VERIFY: part of the test.
    _, _, exitCode, _ = executeScript(context, plan.verifyscript, "verify")
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

    # Execute the METRIC: part of the test.
    for metric, metricscript in plan.metricscripts.items():
        out, err, exitCode, timeoutInfo = executeScript(context, metricscript,
                                                        "metric")
        if exitCode != 0:
            logging.warning("Metric script for '%s' failed", metric)
            continue
        try:
            value = lit.Test.toMetricValue(float(out))
            context.result_metrics[metric] = value
        except ValueError:
            logging.warning("Metric reported for '%s' is not a float: '%s'",
                            metric, out)

    # Execute additional profile gathering actions setup by testing modules.
    _, _, exitCode, _ = executeScript(context, plan.profilescript, "profile")
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
