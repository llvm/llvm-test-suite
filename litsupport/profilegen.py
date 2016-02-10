import shellcommand
try:
    from shlex import quote  # python 3.3 and above
except:
    from pipes import quote  # python 3.2 and earlier


def wrapScript(context, script):
    """Adjust runscript to set a different value to the LLVM_PROFILE_FILE
    environment variable for each execution."""
    i = 0
    adjusted_script = []
    context.profilefiles = []
    for line in script:
        number = ""
        if len(script) > 1:
            number = "-%s" % (i,)
            i += 1
        profilefile = "%s%s.profraw" % (context.tmpBase, number)
        prefix = "LLVM_PROFILE_FILE=%s " % quote(profilefile)
        context.profilefiles.append(profilefile)
        adjusted_script.append(prefix + line)
    return adjusted_script


def getMergeProfilesScript(context):
    executable = shellcommand.getMainExecutable(context)
    if not executable:
        return None
    datafile = executable + ".profdata"
    mergecmd = [context.config.llvm_profdata, 'merge', '-output=%s' % datafile]
    mergecmd += context.profilefiles
    cmdline = " ".join(map(quote, mergecmd))
    return [cmdline]
