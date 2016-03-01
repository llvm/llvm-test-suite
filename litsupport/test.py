import os
import lit
import lit.util
from lit.formats import FileBasedTest
from lit.TestRunner import executeScript, executeScriptInternal, \
    parseIntegratedTestScriptCommands, getDefaultSubstitutions, \
    applySubstitutions, getTempPaths
from lit import Test
from lit.util import to_bytes, to_string

import compiletime
import hash
import perf
import profilegen
import runsafely
import testscript
import timeit


class TestContext:
    """This class is used to hold data used while constructing a testrun.
    For example this can be used by modules modifying the commandline with
    extra instrumentation/measurement wrappers to pass the filenames of the
    results to a final data collection step."""
    def __init__(self, test, litConfig, original_runscript,
                 original_verifyscript, tmpDir, tmpBase):
        self.test = test
        self.config = test.config
        self.litConfig = litConfig
        self.original_runscript = original_runscript
        self.original_verifyscript = original_verifyscript
        self.tmpDir = tmpDir
        self.tmpBase = tmpBase


def runScript(context, script, useExternalSh=True):
    execdir = os.path.dirname(context.test.getExecPath())
    if useExternalSh:
        res = executeScript(context.test, context.litConfig, context.tmpBase,
                            script, execdir)
    else:
        res = executeScriptInternal(context.test, context.litConfig,
                                    context.tmpBase, script, execdir)
    return res


class TestSuiteTest(FileBasedTest):
    def __init__(self):
        super(TestSuiteTest, self).__init__()

    def execute(self, test, litConfig):
        config = test.config
        if config.unsupported:
            return lit.Test.Result(Test.UNSUPPORTED, 'Test is unsupported')

        # Parse benchmark script
        res = testscript.parse(test.getSourcePath())
        if litConfig.noExecute:
            return lit.Test.Result(Test.PASS)
        runscript, verifyscript, metricscripts = res

        # Apply the usual lit substitutions (%s, %S, %p, %T, ...)
        tmpDir, tmpBase = getTempPaths(test)
        outfile = tmpBase + ".out"
        substitutions = getDefaultSubstitutions(test, tmpDir, tmpBase)
        substitutions += [('%o', outfile)]
        runscript = applySubstitutions(runscript, substitutions)
        verifyscript = applySubstitutions(verifyscript, substitutions)
        metricscripts = {k: applySubstitutions(v, substitutions)
                         for k, v in metricscripts.items()}
        context = TestContext(test, litConfig, runscript, verifyscript, tmpDir,
                              tmpBase)

        runscript = runsafely.wrapScript(context, runscript, suffix=".out")

        if config.profile_generate:
            runscript = profilegen.wrapScript(context, runscript)

        # Create the output directory if it does not already exist.
        lit.util.mkdir_p(os.path.dirname(tmpBase))

        # Execute runscript (the "RUN:" part)
        output = ""
        n_runs = 1
        runtimes = []
        metrics = {}
        for n in range(n_runs):
            res = runScript(context, runscript)
            if isinstance(res, lit.Test.Result):
                return res

            output += "\n" + "\n".join(runscript)

            out, err, exitCode, timeoutInfo = res
            if exitCode == Test.FAIL:
                # Only show command output in case of errors
                output += "\n" + out
                output += "\n" + err
                return lit.Test.Result(Test.FAIL, output)

            # Execute metric extraction scripts.
            for metric, script in metricscripts.items():
                res = runScript(context, script)
                if isinstance(res, lit.Test.Result):
                    return res

                out, err, exitCode, timeoutInfo = res
                metrics.setdefault(metric, list()).append(float(out))

            try:
                runtime = runsafely.getTime(context)
                runtimes.append(runtime)
            except IOError:
                pass

        if litConfig.params.get('profile') == 'perf':
            profilescript = perf.wrapScript(context,
                                            context.original_runscript)
            profilescript = runsafely.wrapScript(context, profilescript,
                                                 suffix=".perf.out")
            runScript(context, context.profilescript)  # ignore result

        # Merge llvm profile data
        if config.profile_generate:
            mergescript = profilegen.getMergeProfilesScript(context)
            runScript(context, mergescript)  # ignore result

        # Run verification script (the "VERIFY:" part)
        if len(verifyscript) > 0:
            res = runScript(context, verifyscript)
            if isinstance(res, lit.Test.Result):
                return res
            out, err, exitCode, timeoutInfo = res

            output += "\n" + "\n".join(verifyscript)
            if exitCode != 0:
                output += "\n" + out
                output += "\n" + err
                return lit.Test.Result(Test.FAIL, output)

        # Put metrics into the test result.
        result = lit.Test.Result(Test.PASS, output)
        if len(runtimes) > 0:
            result.addMetric('exec_time', lit.Test.toMetricValue(runtimes[0]))
        for metric, values in metrics.items():
            result.addMetric(metric, lit.Test.toMetricValue(values[0]))
        compiletime.collect(context, result)
        hash.collect(context, result)

        return result
