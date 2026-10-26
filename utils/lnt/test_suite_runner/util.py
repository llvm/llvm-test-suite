"""Helpers used throughout `run-test-suite.py`."""
import datetime
import errno
import logging
import os
import subprocess
import sys

logger = logging.getLogger(__package__)


def init_logging():
    """Log to stderr, with timestamps."""
    handler = logging.StreamHandler()
    handler.setLevel(logging.INFO)
    handler.setFormatter(logging.Formatter(
        '%(asctime)s %(levelname)s: %(message)s', datefmt='%Y-%m-%d %H:%M:%S'))
    logger.addHandler(handler)
    logger.setLevel(logging.INFO)


def fatal(message):
    logger.critical(message)
    sys.exit(1)


def capture(args, include_stderr=False):
    """capture(command) - Run the given argv list and return its standard
    output as text, with its standard error merged in if include_stderr is
    set. Its exit status is ignored."""
    stderr = subprocess.STDOUT if include_stderr else subprocess.PIPE
    try:
        return subprocess.run(args, stdout=subprocess.PIPE, stderr=stderr,
                              universal_newlines=True).stdout
    except FileNotFoundError:
        fatal('no such file or directory: %r when running %s.' %
              (args[0], ' '.join(args)))


def mkdir_p(path):
    """mkdir_p(path) - Make the "path" directory, if it does not exist; this
    will also make directories for any missing parent directories."""
    try:
        os.makedirs(path)
    except OSError as e:
        # Ignore EEXIST, which may occur during a race condition.
        if e.errno != errno.EEXIST:
            raise


def which(command, paths=None):
    """which(command, [paths]) - Look up the given command in the paths string
    (or the PATH environment variable, if unspecified)."""

    if paths is None:
        paths = os.environ.get('PATH', '')

    # Check for absolute match first.
    if os.path.exists(command):
        return command

    # Would be nice if Python had a lib function for this.
    if not paths:
        paths = os.defpath

    # Get suffixes to search.
    pathext = os.environ.get('PATHEXT', '').split(os.pathsep)

    # Search the paths...
    for path in paths.split(os.pathsep):
        for ext in pathext:
            p = os.path.join(path, command + ext)
            if os.path.exists(p):
                return p

    return None


def resolve_command_path(name):
    """Try to make the name/path given into an absolute path to an
    executable.

    """
    name = os.path.expanduser(name)

    # If the given name exists (or is a path), make it absolute.
    if os.path.exists(name):
        return os.path.abspath(name)

    # Otherwise we most likely have a command name, try to look it up.
    path = which(name)
    if path is not None:
        logger.info("resolved command %r to path %r" % (name, path))
        return path

    # If that failed just return the original name.
    return name


def isexecfile(path):
    """Does this path point to a valid executable?

    """
    return os.path.isfile(path) and os.access(path, os.X_OK)


def timestamp():
    return datetime.datetime.utcnow().strftime('%Y-%m-%d %H:%M:%S')
