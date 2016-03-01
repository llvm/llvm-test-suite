import shlex
import timeit
import shellcommand
try:
    from shlex import quote  # python 3.3 and above
except:
    from pipes import quote  # python 3.2 and earlier


def prepareRunSafely(context, commandline, outfile):
    config = context.config
    cmd = shellcommand.parse(commandline)

    runsafely = "%s/RunSafely.sh" % config.test_suite_root
    runsafely_prefix = [runsafely]
    if cmd.workdir is not None:
        runsafely_prefix += ["-d", cmd.workdir]
    timeit = "%s/tools/timeit" % config.test_source_root
    if config.remote_host:
        timeit = "%s/tools/timeit-target" % config.test_source_root
        runsafely_prefix += ["-r", config.remote_host]
        if config.remote_user:
            runsafely_prefix += ["-l", config.remote_user]
        if config.remote_client:
            runsafely_prefix += ["-rc", config.remote_client]
        if config.remote_port:
            runsafely_prefix += ["-rp", config.remote_port]
    if config.run_under:
        runsafely_prefix += ["-u", config.run_under]
    if not config.traditional_output:
        runsafely_prefix += ["-n"]
        if cmd.stdout is not None:
            runsafely_prefix += ["-o", cmd.stdout]
        if cmd.stderr is not None:
            runsafely_prefix += ["-e", cmd.stderr]
    else:
        if cmd.stdout is not None or cmd.stderr is not None:
            raise Exception("Separate stdout/stderr redirection not " +
                            "possible with traditional output")
    timeout = "7200"
    if cmd.stdin is not None:
        stdin = cmd.stdin
    else:
        stdin = "/dev/null"
    runsafely_prefix += ["-t", timeit, timeout, stdin, outfile]

    complete_command = runsafely_prefix + [cmd.executable] + cmd.arguments
    new_commandline = " ".join(map(quote, complete_command))
    return new_commandline


def wrapScript(context, script, suffix):
    adjusted_script = []
    outfile = context.tmpBase + suffix
    # Set name of timefile so getTime() can use it
    context.timefiles = []
    i = 0
    for line in script:
        number = ""
        if len(script) > 1:
            number = "-%s" % (i,)
            i += 1
        outfile = context.tmpBase + number + suffix
        context.timefiles.append(outfile + ".time")

        line = prepareRunSafely(context, line, outfile)
        adjusted_script.append(line)
    return adjusted_script


def getTime(context):
    time = 0.0
    for timefile in context.timefiles:
        time += timeit.getUserTime(timefile)
    return time
