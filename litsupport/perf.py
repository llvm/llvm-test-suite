import shellcommand
import testplan


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
    script = testplan.mutateScript(context, context.original_runscript,
                                   mutateCommandLine)
    plan.profilescript += script
