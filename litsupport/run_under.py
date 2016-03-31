from litsupport import shellcommand
from litsupport import testplan


def mutateCommandLine(context, commandline):
    return context.config.run_under + " " + commandline


def mutatePlan(context, plan):
    run_under = context.config.run_under
    if run_under:
        plan.runscript = testplan.mutateScript(context, plan.runscript,
                                               mutateCommandLine)
