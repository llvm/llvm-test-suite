import os
import lit
import lit.util
import logging
from lit.formats import FileBasedTest
from lit.TestRunner import getTempPaths
from lit import Test
from lit.util import to_bytes, to_string

from litsupport import codesize
from litsupport import compiletime
from litsupport import hash
from litsupport import perf
from litsupport import profilegen
from litsupport import remote
from litsupport import run
from litsupport import run_under
from litsupport import testfile
from litsupport import testplan
from litsupport import timeit


SKIPPED = lit.Test.ResultCode('SKIPPED', False)


class TestContext:
    """This class is used to hold data used while constructing a testrun.
    For example this can be used by modules modifying the commandline with
    extra instrumentation/measurement wrappers to pass the filenames of the
    results to a final data collection step."""
    def __init__(self, test, litConfig, tmpDir, tmpBase):
        self.test = test
        self.config = test.config
        self.litConfig = litConfig
        self.tmpDir = tmpDir
        self.tmpBase = tmpBase


class TestSuiteTest(FileBasedTest):
    def __init__(self):
        super(TestSuiteTest, self).__init__()

    def execute(self, test, litConfig):
        config = test.config
        if config.unsupported:
            return lit.Test.Result(Test.UNSUPPORTED, 'Test is unsupported')
        if litConfig.noExecute:
            return lit.Test.Result(Test.PASS)

        # Parse .test file and initialize context
        tmpDir, tmpBase = getTempPaths(test)
        lit.util.mkdir_p(os.path.dirname(tmpBase))
        context = TestContext(test, litConfig, tmpDir, tmpBase)
        testfile.parse(context, test.getSourcePath())
        plan = testplan.TestPlan()

        # Skip unchanged tests
        if config.previous_results:
            hash.compute(context)
            if hash.same_as_previous(context):
                result = lit.Test.Result(
                        SKIPPED, 'Executable identical to previous run')
                val = lit.Test.toMetricValue(context.executable_hash)
                result.addMetric('hash', val)
                return result

        # Prepare test plan
        run.mutatePlan(context, plan)
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
