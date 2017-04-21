"""Test Module to perform an extra execution of the benchmark in the linux
perf tool."""
from litsupport import shellcommand
from litsupport import testplan
from litsupport import run_under
import lit.Test


def mutateCommandLine(context, commandline):
    profilefile = context.tmpBase + ".perf_data"
    cmd = shellcommand.parse(commandline)
    cmd.wrap('perf', [
        'record',
        '-e', context.config.perf_profile_events,
        '-o', profilefile,
        '--'
    ])
    if cmd.stdout is None:
        cmd.stdout = "/dev/null"
    else:
        cmd.stdout += ".perfrecord"
    if cmd.stderr is None:
        cmd.stderr = "/dev/null"
    else:
        cmd.stderr += ".perfrecord"
    return cmd.toCommandline()


def mutatePlan(context, plan):
    script = context.parsed_runscript
    if context.config.run_under:
        script = testplan.mutateScript(context, script,
                                       run_under.mutateCommandLine)
    script = testplan.mutateScript(context, script, mutateCommandLine)
    plan.profilescript += script
    plan.metric_collectors.append(
        lambda context: {
            'profile': lit.Test.toMetricValue(context.tmpBase + '.perf_data')})
