"""Test module that runs llvm-profdata merge after executing the benchmark."""
import os

from litsupport import shellcommand
from litsupport import testplan


def _mutateCommandline(context, commandline):
    """Adjust runscript to set a different value to the LLVM_PROFILE_FILE
    environment variable for each execution."""
    profilefile = context.tmpBase + ".profraw"
    context.profilefiles.append(profilefile)
    cmd = shellcommand.parse(commandline)
    cmd.envvars.update({"LLVM_PROFILE_FILE": profilefile})
    return cmd.toCommandline()


def _mutateScript(context, script):
    return testplan.mutateScript(context, script, _mutateCommandline)


def _profdataPath(context):
    """Return the path of the merged profile of the benchmark under test."""
    profile_dir = getattr(context.config, "profile_dir", "")
    if not profile_dir:
        return context.executable + ".profdata"
    relpath = os.path.relpath(context.executable, context.test.suite.exec_root)
    profdatafile = os.path.join(profile_dir, relpath + ".profdata")
    os.makedirs(os.path.dirname(profdatafile), exist_ok=True)
    return profdatafile


def mutatePlan(context, plan):
    context.profilefiles = []
    # Adjust run steps to set LLVM_PROFILE_FILE environment variable.
    plan.runscript = _mutateScript(context, plan.runscript)
    plan.profile_files += context.profilefiles

    # Run profdata merge at the end
    profdatafile = _profdataPath(context)
    args = ["merge", "-output=%s" % profdatafile] + context.profilefiles
    mergecmd = shellcommand.ShellCommand(context.config.llvm_profdata, args)
    plan.profilecollectscript += [mergecmd.toCommandline()]
