from litsupport import shellcommand
from litsupport import testplan
import lit.Test
import re


def mutateCommandLine(context, commandline):
    outfile = context.tmpBase + ".out"
    timefile = context.tmpBase + ".time"
    config = context.config
    cmd = shellcommand.parse(commandline)

    timeit = "%s/tools/timeit" % config.test_source_root
    if config.remote_host:
        timeit = "%s/tools/timeit-target" % config.test_source_root
    args = ["--limit-core", "0"]
    args += ["--limit-cpu", "7200"]
    args += ["--timeout", "7200"]
    args += ["--limit-file-size", "104857600"]
    args += ["--limit-rss-size", "838860800"]
    if cmd.workdir is not None:
        args += ["--chdir", cmd.workdir]
        cmd.workdir = None
    if not config.traditional_output:
        if cmd.stdout is not None:
            args += ["--redirect-stdout", cmd.stdout]
            cmd.stdout = None
        if cmd.stderr is not None:
            args += ["--redirect-stderr", cmd.stderr]
            cmd.stderr = None
    else:
        if cmd.stdout is not None or cmd.stderr is not None:
            raise Exception("Separate stdout/stderr redirection not " +
                            "possible with traditional output")
        args += ["--append-exitstatus"]
        args += ["--redirect-output", outfile]
    if cmd.stdin is not None:
        args += ["--redirect-input", cmd.stdin]
        cmd.stdin = None
    else:
        args += ["--redirect-input", "/dev/null"]
    args += ["--summary", timefile]
    # Remember timefilename for later
    context.timefiles.append(timefile)

    cmd.wrap(timeit, args)
    return cmd.toCommandline()


def mutateScript(context, script):
    if not hasattr(context, "timefiles"):
        context.timefiles = []
    return testplan.mutateScript(context, script, mutateCommandLine)


def _collectTime(context, timefiles, metric_name='exec_time'):
    time = 0.0
    for timefile in timefiles:
        time += getUserTime(timefile)
    return {metric_name: lit.Test.toMetricValue(time)}


def mutatePlan(context, plan):
    if len(plan.runscript) == 0:
        return
    context.timefiles = []
    plan.runscript = mutateScript(context, plan.runscript)
    plan.metric_collectors.append(
        lambda context: _collectTime(context, context.timefiles)
    )


def getUserTime(filename):
    """Extract the user time form a .time file produced by timeit"""
    with open(filename) as fd:
        l = [l for l in fd.readlines()
             if l.startswith('user')]
    assert len(l) == 1

    m = re.match(r'user\s+([0-9.]+)', l[0])
    return float(m.group(1))
