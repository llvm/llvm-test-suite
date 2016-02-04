import os
import lit
import lit.util
from lit.formats import FileBasedTest
from lit.TestRunner import executeScript, executeScriptInternal, \
    parseIntegratedTestScriptCommands, getDefaultSubstitutions, \
    applySubstitutions, getTempPaths
from lit import Test
from lit.util import to_bytes, to_string
import testscript
import runsafely
import perf
import compiletime
import timeit


def runScript(test, litConfig, script, tmpBase, useExternalSh=True):
    execdir = os.path.dirname(test.getExecPath())
    if useExternalSh:
        res = executeScript(test, litConfig, tmpBase, script, execdir)
    else:
        res = executeScriptInternal(test, litConfig, tmpBase, script, execdir)
    return res


class TestSuiteTest(FileBasedTest):
    def __init__(self):
        super(TestSuiteTest, self).__init__()

    def execute(self, test, litConfig):
        config = test.config
        if config.unsupported:
            return (Test.UNSUPPORTED, 'Test is unsupported')

        # Parse benchmark script
        res = testscript.parse(test.getSourcePath())
        if litConfig.noExecute:
            return lit.Test.Result(Test.PASS)
        runscript, verifyscript = res

        # Apply the usual lit substitutions (%s, %S, %p, %T, ...)
        tmpDir, tmpBase = getTempPaths(test)
        outfile = tmpBase + ".out"
        substitutions = getDefaultSubstitutions(test, tmpDir, tmpBase)
        substitutions += [('%o', outfile)]
        runscript = applySubstitutions(runscript, substitutions)
        verifyscript = applySubstitutions(verifyscript, substitutions)

        profilescript = None
        if litConfig.params.get('profile') == 'perf':
            profilescript = perf.wrapScript(config, runscript, tmpBase)
            profilescript = runsafely.wrapScript(config, profilescript,
                                                 outfile=tmpBase+".perf.out")

        runscript = runsafely.wrapScript(config, runscript, outfile)

        # Create the output directory if it does not already exist.
        lit.util.mkdir_p(os.path.dirname(tmpBase))

        # Execute runscript (the "RUN:" part)
        output = ""
        n_runs = 1
        runtimes = []
        for n in range(n_runs):
            res = runScript(test, litConfig, runscript, tmpBase)
            if isinstance(res, lit.Test.Result):
                return res

            output += "\n" + "\n".join(runscript)

            out, err, exitCode, timeoutInfo = res
            if exitCode == Test.FAIL:
                # Only show command output in case of errors
                output += "\n" + out
                output += "\n" + err
                return lit.Test.Result(Test.FAIL, output)

            timefile = "%s.time" % (outfile,)
            try:
                runtime = timeit.getUserTime(timefile)
                runtimes.append(runtime)
            except IOError:
                pass

        if profilescript:
            res = runScript(test, litConfig, profilescript, tmpBase)
            out, err, exitCode, timeoutInfo = res

        # Run verification script (the "VERIFY:" part)
        if len(verifyscript) > 0:
            res = runScript(test, litConfig, verifyscript, tmpBase)
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
        compiletime.collect(test, result)

        return result
