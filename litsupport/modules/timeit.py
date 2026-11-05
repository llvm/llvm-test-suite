from litsupport import shellcommand
from litsupport import testplan
import hashlib
import lit.Test
import os
import re


def _mutateCommandLine(context, commandline):
    timefile = os.path.normpath(context.tmpBase + ".time")
    config = context.config
    cmd = shellcommand.parse(commandline)

    if config.user_mode_emulation:
        # user_mode_emulation should be true if tests are being run via
        # user-mode emulation (e.g. Qemu) and thus the host version of timeit
        # should be used.
        timeit_name = "timeit"
    else:
        timeit_name = "timeit-target"

    timeit = os.path.normpath("%s/tools/%s" % (config.test_source_root, timeit_name))
    args = ["--timeout", "7200"]
    if os.name != 'nt':
        args += ["--limit-core", "0"]
        args += ["--limit-cpu", "7200"]
        args += ["--limit-file-size", "209715200"]
        args += ["--limit-rss-size", "838860800"]

    workdir = os.path.normpath(cmd.workdir) if cmd.workdir is not None else None

    if not config.traditional_output:
        stdout = cmd.stdout
        if cmd.stdout is not None:
            if not os.path.isabs(stdout) and workdir is not None:
                stdout = os.path.join(workdir, os.path.normpath(stdout))
            args += ["--redirect-stdout", stdout]
            cmd.stdout = None
        stderr = cmd.stderr
        if stderr is not None:
            if not os.path.isabs(stderr) and workdir is not None:
                stderr = os.path.join(workdir, os.path.normpath(stderr))
            args += ["--redirect-stderr", stderr]
            cmd.stderr = None
    else:
        if cmd.stdout is not None or cmd.stderr is not None:
            raise Exception(
                "Separate stdout/stderr redirection not "
                + "possible with traditional output"
            )
        outfile = os.path.normpath(context.tmpBase + ".out")
        args += ["--append-exitstatus"]
        args += ["--redirect-output", outfile]
    stdin = cmd.stdin
    if stdin is not None:
        if not os.path.isabs(stdin) and workdir is not None:
            stdin = os.path.join(workdir, os.path.normpath(stdin))
        args += ["--redirect-input", stdin]
        cmd.stdin = None
    else:
        if os.name != 'nt':
            args += ["--redirect-input", "/dev/null"]
    if workdir is not None:
        args += ["--chdir", workdir]
        cmd.workdir = None
    args += ["--summary", timefile]
    # Remember timefilename for later
    context.timefiles.append(timefile)

    cmd.wrap(timeit, args)
    return cmd.toCommandline()


def _mutateScript(context, script):
    if not hasattr(context, "timefiles"):
        context.timefiles = []
    return testplan.mutateScript(context, script, _mutateCommandLine)


def _runLineHash(line):
    """Short hash of a RUN line, so that per-RUN-line results don't silently
    get attributed to a different RUN line when lines are inserted, removed or
    reordered in the test file."""
    return hashlib.sha256(line.encode("utf-8")).hexdigest()[:8]


def _collectTime(context, timefiles, metric_name="exec_time"):
    total_time = 0.0
    assert len(timefiles) == len(context.raw_runscript)
    for i, (timefile, runline) in enumerate(zip(timefiles, context.raw_runscript)):
        filecontent = context.read_result_file(context, timefile)
        time = getUserTimeFromContents(filecontent)
        # Report each RUN line of a multi-RUN-line test as a micro-test result,
        # e.g. "mytest.test:run0-1a2b3c4d".
        if len(timefiles) > 1:
            result = lit.Test.Result(lit.Test.PASS)
            result.addMetric(metric_name, lit.Test.toMetricValue(time))
            context.micro_results[f"run{i}-{_runLineHash(runline)}"] = result
        total_time += time
    return {metric_name: total_time}


def mutatePlan(context, plan):
    if len(plan.runscript) == 0:
        return
    context.timefiles = []
    plan.runscript = _mutateScript(context, plan.runscript)
    plan.metric_collectors.append(
        lambda context: _collectTime(context, context.timefiles)
    )


def getUserTimeFromContents(contents):
    from_bytes = lambda s: s.decode("utf-8") if type(s) == bytes else s
    lines = [from_bytes(l) for l in contents.splitlines()]
    line = [line for line in lines if line.startswith("user")]
    assert len(line) == 1

    m = re.match(r"user\s+([0-9.]+)", line[0])
    return float(m.group(1))


def getMaxRSSFromContents(contents):
    from_bytes = lambda s: s.decode("utf-8") if type(s) == bytes else s
    lines = [from_bytes(l) for l in contents.splitlines()]
    line = [line for line in lines if line.startswith("maxrss")]
    if len(line) == 0:
        return 0
    m = re.match(r"maxrss\s+([0-9]+)", line[0])
    return int(m.group(1))
