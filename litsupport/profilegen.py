from litsupport import shellcommand
from litsupport import testplan


def mutateCommandline(context, commandline):
    """Adjust runscript to set a different value to the LLVM_PROFILE_FILE
    environment variable for each execution."""
    profilefile = context.tmpBase + ".profraw"
    prefix = "env LLVM_PROFILE_FILE=%s " % profilefile
    context.profilefiles.append(profilefile)
    return prefix + commandline


def mutateScript(context, script):
    return testplan.mutateScript(context, script, mutateCommandline)


def mutatePlan(context, plan):
    context.profilefiles = []
    # Adjust run steps to set LLVM_PROFILE_FILE
    plan.runscript = mutateScript(context, plan.runscript)
    # Run profdata merge at the end
    profdatafile = context.executable + ".profdata"
    args = ['merge', '-output=%s' % profdatafile] + context.profilefiles
    mergecmd = shellcommand.ShellCommand(context.config.llvm_profdata, args)
    plan.profilescript += [mergecmd.toCommandline()]
