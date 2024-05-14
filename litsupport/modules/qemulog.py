"""test-suite/lit plugin to collect metrics from QEMU logs.

If you are running the test suite under QEMU and are generating logs
that contain metrics (typically from a plugin), you can use this
module to:

1. save the logs to a file
2. parse any colon (:) separated metrics and collect them in the
metrics

For example, the example plugin libinsn.so outputs dynamic instruction
counts in the following format:

cpu 0 insns: 42
total insns: 1024

If you enable the plugin and tell QEMU to log it:

-DTEST_SUITE_RUN_UNDER='qemu -plugin libinsn.so -d plugin'
-DTEST_SUITE_EXTRA_LIT_MODULES=qemulog

You can then compare those instruction counts later:

./compare.py results.json -m 'total insns'

"""

from litsupport import shellcommand
from litsupport import testplan
from litsupport.modules import run_under


def _mutateCommandLine(context, commandline):
    context.qemulog = context.tmpBase + ".qemulog"
    cmd = shellcommand.parse(commandline)
    cmd.envvars.update({"QEMU_LOG_FILENAME": context.qemulog})
    return cmd.toCommandline()


def _getOutput(context):
    with open(context.qemulog, "r") as f:
        result = dict()
        for line in f.read().splitlines():
            [name, count] = line.split(":")
            result[name] = int(count)
        return result


def mutatePlan(context, plan):
    plan.runscript = testplan.mutateScript(context, plan.runscript, _mutateCommandLine)
    plan.metric_collectors.append(_getOutput)
