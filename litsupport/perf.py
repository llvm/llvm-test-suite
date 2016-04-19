from litsupport import shellcommand
from litsupport import testplan
from litsupport import run_under


def mutateCommandLine(context, commandline):
    profilefile = context.tmpBase + ".perf_data"
    cmd = shellcommand.parse(commandline)
    cmd.wrap('perf', [
        'record',
        '-e', 'cycles,cache-misses,branch-misses',
        '-o', profilefile
    ])
    return cmd.toCommandline()


def mutatePlan(context, plan):
    script = context.parsed_runscript
    if context.config.run_under:
        script = testplan.mutateScript(context, script,
                                       run_under.mutateCommandLine)
    script = testplan.mutateScript(context, script, mutateCommandLine)
    plan.profilescript += script
