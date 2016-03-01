import lit.Test
import hashlib
import logging
import subprocess
import shutil
import platform
import shellcommand


def collect(context, result):
    executable = context.executable
    try:
        # Darwin's "strip" doesn't support these arguments.
        if platform.system() != 'Darwin':
            stripped_executable = executable + '.stripped'
            shutil.copyfile(executable, stripped_executable)
            subprocess.check_call(['strip',
                                   '--remove-section=.comment',
                                   '--remove-section=.note',
                                   stripped_executable])
            executable = stripped_executable

        h = hashlib.md5()
        h.update(open(executable, 'rb').read())
        digest = h.hexdigest()

        result.addMetric('hash', lit.Test.toMetricValue(digest))

    except:
        logging.info('Could not calculate hash for %s' % executable)
