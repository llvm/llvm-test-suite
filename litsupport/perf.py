import shellcommand
import testplan
import run_under


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
    if context.config.run_under:
        script = testplan.mutateScript(context, context.original_runscript,
                                       run_under.mutateCommandLine)
    else:
        script = context.original_runscript
    script = testplan.mutateScript(context, script, mutateCommandLine)
    plan.profilescript += script
