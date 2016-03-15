import lit.Test
import shellcommand
import testplan
import timeit


def mutateCommandline(context, commandline):
    outfile = context.tmpBase + ".out"
    timefile = outfile + ".time"
    config = context.config
    cmd = shellcommand.parse(commandline)

    runsafely = "%s/RunSafely.sh" % config.test_suite_root
    runsafely_prefix = []
    if cmd.workdir is not None:
        runsafely_prefix += ["-d", cmd.workdir]
        cmd.workdir = None
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
            cmd.stdout = None
        if cmd.stderr is not None:
            runsafely_prefix += ["-e", cmd.stderr]
            cmd.stderr = None
    else:
        if cmd.stdout is not None or cmd.stderr is not None:
            raise Exception("Separate stdout/stderr redirection not " +
                            "possible with traditional output")
    timeout = "7200"
    if cmd.stdin is not None:
        stdin = cmd.stdin
        cmd.stdin = None
    else:
        stdin = "/dev/null"
    runsafely_prefix += ["-t", timeit, timeout, stdin, outfile]

    context.timefiles.append(outfile + ".time")

    cmd.wrap(runsafely, runsafely_prefix)
    return cmd.toCommandline()


def mutateScript(context, script):
    return testplan.mutateScript(context, script, mutateCommandline)


def _getTime(context, timefiles, metric_name='exec_time'):
    time = 0.0
    for timefile in timefiles:
        time += timeit.getUserTime(timefile)
    return {metric_name: lit.Test.toMetricValue(time)}


def mutatePlan(context, plan):
    context.timefiles = []
    plan.runscript = mutateScript(context, plan.runscript)
    plan.metric_collectors.append(
        lambda context: _getTime(context, context.timefiles)
    )
