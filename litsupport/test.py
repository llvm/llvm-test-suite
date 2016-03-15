import os
import lit
import lit.util
import logging
from lit.formats import FileBasedTest
from lit.TestRunner import getDefaultSubstitutions, applySubstitutions, \
    getTempPaths
from lit import Test
from lit.util import to_bytes, to_string

import codesize
import compiletime
import hash
import perf
import profilegen
import remote
import run_under
import shellcommand
import testplan
import timeit


SKIPPED = lit.Test.ResultCode('SKIPPED', False)


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



class TestSuiteTest(FileBasedTest):
    def __init__(self):
        super(TestSuiteTest, self).__init__()

    def execute(self, test, litConfig):
        config = test.config
        if config.unsupported:
            return lit.Test.Result(Test.UNSUPPORTED, 'Test is unsupported')

        # Parse benchmark script
        plan = testplan.parse(test.getSourcePath())
        if litConfig.noExecute:
            return lit.Test.Result(Test.PASS)

        # Apply the usual lit substitutions (%s, %S, %p, %T, ...)
        tmpDir, tmpBase = getTempPaths(test)
        outfile = tmpBase + ".out"
        substitutions = getDefaultSubstitutions(test, tmpDir, tmpBase)
        substitutions += [('%o', outfile)]
        plan.runscript = applySubstitutions(plan.runscript, substitutions)
        plan.verifyscript = applySubstitutions(plan.verifyscript, substitutions)
        plan.metricscripts = {k: applySubstitutions(v, substitutions)
                         for k, v in plan.metricscripts.items()}
        context = TestContext(test, litConfig, plan.runscript,
                              plan.verifyscript, tmpDir, tmpBase)
        context.executable = shellcommand.getMainExecutable(context)
        if context.executable is None:
            return lit.Test.Result(Test.UNSUPPORTED,
                                   'Could not determine executable name')
        hash.compute(context)
        if hash.same_as_previous(context):
            return lit.Test.Result(SKIPPED,
                                   'Executable identical to previous run')

        # Create the output directory if it does not already exist.
        lit.util.mkdir_p(os.path.dirname(tmpBase))

        # Prepare test plan
        run_under.mutatePlan(context, plan)
        timeit.mutatePlan(context, plan)
        compiletime.mutatePlan(context, plan)
        codesize.mutatePlan(context, plan)
        hash.mutatePlan(context, plan)
        if config.profile_generate:
            profilegen.mutatePlan(context, plan)
        if config.remote_host:
            remote.mutatePlan(context, plan)
        if litConfig.params.get('profile') == 'perf':
            perf.mutatePlan(context, plan)

        # Execute Test plan
        result = testplan.executePlanTestResult(context, plan)

        return result
