import shlex
import logging

# Loosely modeled after posix specification for sh
reserved_words = [ '!', '{', '}', 'case', 'do', 'done', 'elif', 'else', 'esac',
                   'fi', 'for', 'if', 'in', 'then', 'until', 'while' ]

chaining_tokens = set([';', '&&', '||', '|', '&'])
unhandled_tokens = set([';;', '<<', '>>', '<&', '>&', '<>', '<<-', '>|', '(',
                        ')'])

class ShellCommand:
    def __init__(self):
        self.stdin = None
        self.stdout = None
        self.stderr = None
        self.executable = None
        self.arguments = []
        self.modifiers = None
        self.workdir = None

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
            i+=1
            continue
        if token == '>' and i < len(tokens):
            result.stdout = tokens[i]
            i+=1
            continue
        if token == '2>' and i < len(tokens):
            result.stderr = tokens[i]
            i+=1
            continue
        if first_word:
            if token in reserved_words or token in unhandled_tokens:
                raise Exception("Reserved word '%s' not supported" % token)
            result.executable = token
            first_word = False
        else:
            if token in chaining_tokens:
                # Currently we only allow the special case of 'cd DIR ;'
                if token == ';' and result.executable == 'cd' and \
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
_ignore_executables = set(['cd', 'rm'])


def getMainExecutable(context):
    """Collect md5sum of tested executable"""
    if hasattr(context, 'executable'):
        return context.executable

    executable = None
    for line in context.original_runscript:
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
