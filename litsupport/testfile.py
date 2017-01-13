"""
Parse a .test file
"""
from lit.TestRunner import parseIntegratedTestScriptCommands, \
        getDefaultSubstitutions, applySubstitutions
from litsupport import shellcommand


def _parseShellCommand(script, ln):
    # Trim trailing whitespace.
    ln = ln.rstrip()

    # Collapse lines with trailing '\\'.
    if script and script[-1][-1] == '\\':
        script[-1] = script[-1][:-1] + ln
    else:
        script.append(ln)


def parse(context, filename):
    """Parse a .test file as used in the llvm test-suite.
    The file comporises of a number of lines starting with RUN: and VERIFY:
    specifying shell commands to run the benchmark and verifying the result.
    Returns a tuple with two arrays for the run and verify commands."""
    # Collect the test lines from the script.
    preparescript = []
    runscript = []
    verifyscript = []
    metricscripts = {}
    # Note that we keep both "RUN" and "RUN:" in the list to stay compatible
    # with older lit versions.
    keywords = ['PREPARE:', 'PREPARE', 'RUN:', 'RUN', 'VERIFY:', 'VERIFY',
                'METRIC:', 'METRIC']
    for line_number, command_type, ln in \
            parseIntegratedTestScriptCommands(filename, keywords):
        if command_type.startswith('PREPARE'):
            _parseShellCommand(preparescript, ln)
        elif command_type.startswith('RUN'):
            _parseShellCommand(runscript, ln)
        elif command_type.startswith('VERIFY'):
            _parseShellCommand(verifyscript, ln)
        elif command_type.startswith('METRIC'):
            metric, ln = ln.split(':', 1)
            metricscript = metricscripts.setdefault(metric.strip(), list())
            _parseShellCommand(metricscript, ln)
        else:
            raise ValueError("unknown script command type: %r" % (
                             command_type,))

    # Verify the script contains a run line.
    if runscript == []:
        raise ValueError("Test has no RUN: line!")

    # Check for unterminated run lines.
    for script in preparescript, runscript, verifyscript:
        if script and script[-1][-1] == '\\':
            raise ValueError("Test has unterminated RUN/VERIFY lines " +
                             "(ending with '\\')")

    # Apply the usual lit substitutions (%s, %S, %p, %T, ...)
    outfile = context.tmpBase + ".out"
    substitutions = getDefaultSubstitutions(context.test, context.tmpDir,
                                            context.tmpBase)
    substitutions += [('%o', outfile)]
    preparescript = applySubstitutions(preparescript, substitutions)
    runscript = applySubstitutions(runscript, substitutions)
    verifyscript = applySubstitutions(verifyscript, substitutions)
    metricscripts = {k: applySubstitutions(v, substitutions)
                     for k, v in metricscripts.items()}

    # Put things into the context
    context.parsed_preparescript = preparescript
    context.parsed_runscript = runscript
    context.parsed_verifyscript = verifyscript
    context.parsed_metricscripts = metricscripts
    context.executable = shellcommand.getMainExecutable(context)
    if not context.executable:
        logging.error("Could not determine executable name in %s" % filename)
