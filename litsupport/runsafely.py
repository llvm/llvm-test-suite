import shlex
try:
    from shlex import quote  # python 3.3 and above
except:
    from pipes import quote  # python 3.2 and earlier


def prepareRunSafely(config, commandline, outfile):
    stdin = None
    stdout = None
    stderr = None
    workdir = None
    tokens = shlex.split(commandline)
    # Parse "< INPUTFILE", "> OUTFILE", "2> OUTFILE" patterns
    i = 0
    while i < len(tokens):
        if tokens[i] == "<" and i+1 < len(tokens):
            stdin = tokens[i+1]
            del tokens[i+1]
            del tokens[i]
            continue
        elif tokens[i] == ">" and i+1 < len(tokens):
            stdout = tokens[i+1]
            del tokens[i+1]
            del tokens[i]
            continue
        elif tokens[i] == "2>" and i+1 < len(tokens):
            stderr = tokens[i+1]
            del tokens[i+1]
            del tokens[i]
            continue
        if i+2 < len(tokens) and tokens[i] == "cd" and tokens[i+2] == ";":
            workdir = tokens[i+1]
            del tokens[i+2]
            del tokens[i+1]
            del tokens[i]
            continue
        i += 1

    runsafely = "%s/RunSafely.sh" % config.test_suite_root
    runsafely_prefix = [runsafely]
    if workdir is not None:
        runsafely_prefix += ["-d", workdir]
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
        if stdout is not None:
            runsafely_prefix += ["-o", stdout]
        if stderr is not None:
            runsafely_prefix += ["-e", stderr]
    else:
        if stdout is not None or stderr is not None:
            raise Exception("separate stdout/stderr redirection not possible with traditional output")
    timeout = "7200"
    if stdin is None:
        stdin = "/dev/null"
    runsafely_prefix += ["-t", timeit, timeout, stdin, outfile]

    new_commandline = " ".join(map(quote, runsafely_prefix + tokens))
    return new_commandline


def wrapScript(config, script, outfile):
    adjusted_script = []
    for line in script:
        line = prepareRunSafely(config, line, outfile)
        adjusted_script.append(line)
    return adjusted_script
