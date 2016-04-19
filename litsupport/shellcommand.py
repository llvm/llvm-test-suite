import shlex
import logging
import re
try:
        from shlex import quote  # python 3.3 and above
except:
        from pipes import quote  # python 3.2 and earlier


class ShellCommand:
    '''This class represents a parsed shell command (a subset, we do not support
    arbitrary shell commands yet). The parsed form allows direct access to
    information like the executable name, working directory or the file
    to which stdin/stdout/stderr is redirected.'''
    def __init__(self, executable=None, arguments=None):
        self.stdin = None
        self.stdout = None
        self.stderr = None
        self.executable = executable
        if arguments is None:
            arguments = []
        self.arguments = arguments
        self.workdir = None
        self.envvars = {}

    def toCommandline(self):
        result = ""

        if self.workdir is not None:
            result += "cd %s && " % quote(self.workdir)

        res_list = [self.executable] + self.arguments
        result += " ".join(map(quote, res_list))

        envlist = []
        for key, value in self.envvars.items():
            result += "%s=%s " % (key, quote(value))

        if self.stdin is not None:
            result += " < %s" % quote(self.stdin)
        if self.stdout is not None:
            result += " > %s" % quote(self.stdout)
        if self.stderr is not None:
            result += " 2> %s" % quote(self.stderr)
        return result

    def wrap(self, new_executable, args):
        self.arguments = args + [self.executable] + self.arguments
        self.executable = new_executable


# Tokens/keywords for shell command parsing, loosely modeled after posix
# specification for sh.
reserved_words = ['!', '{', '}', 'case', 'do', 'done', 'elif', 'else', 'esac',
                  'fi', 'for', 'if', 'in', 'then', 'until', 'while']

chaining_tokens = set([';', '&&', '||', '|', '&'])
unhandled_tokens = set([';;', '<<', '>>', '<&', '>&', '<>', '<<-', '>|', '(',
                        ')'])


def parse(commandline):
    previous_commands = []
    result = ShellCommand()
    tokens = shlex.split(commandline)
    i = 0
    first_word = True
    while i < len(tokens):
        token = tokens[i]
        i += 1
        if token == '<' and i < len(tokens):
            result.stdin = tokens[i]
            i += 1
            continue
        if token == '>' and i < len(tokens):
            result.stdout = tokens[i]
            i += 1
            continue
        if token == '2>' and i < len(tokens):
            result.stderr = tokens[i]
            i += 1
            continue

        if first_word:
            # Is it an environment variable assignment?
            assignment = re.match('([A-Za-z_][A-Za-z_0-9]*)=(.*)', token)
            if assignment:
                result.envvars[assignment.group(1)] = assignment.group(2)
                continue
            # A reserved word?
            if token in reserved_words or token in unhandled_tokens:
                raise Exception("Reserved word '%s' not supported" % token)
            result.executable = token
            first_word = False
        else:
            if token in chaining_tokens:
                # Currently we only allow the special case of 'cd DIR ;'
                if (token == ';' or token == '&&') and \
                        result.executable == 'cd' and \
                        len(result.arguments) == 1:
                    newresult = ShellCommand()
                    newresult.workdir = result.arguments[0]
                    result = newresult
                    first_word = True
                    continue
                raise Exception("Command chaining not supported yet")
            if token in unhandled_tokens or token in reserved_words:
                raise Exception("Commandline with '%s' not supported yet" %
                                token)
            result.arguments.append(token)
    return result


# Some executables are just used to cleanup/prepare for a test run, ignore them
# here.
_ignore_executables = set(['cd', 'rm', 'cp'])


def getMainExecutable(context):
    """Collect md5sum of tested executable"""
    if hasattr(context, 'executable'):
        return context.executable

    executable = None
    for line in context.parsed_runscript:
        cmd = parse(line)
        if cmd.executable in _ignore_executables:
            continue
        # We only support one executable yet for collecting md5sums
        if cmd.executable != executable and executable is not None:
            logging.warning("More than one executable used in test %s",
                            context.test.getFullName())
        executable = cmd.executable
    if executable is None:
        logging.warning("No executable found for test %s",
                        context.test.getFullName())
    context.executable = executable
    return executable
