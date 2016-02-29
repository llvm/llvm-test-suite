import lit.Test
import hashlib
import logging
import subprocess
import shutil
import platform
import shellcommand

def collect(context, result):
    try:
        exename = shellcommand.getMainExecutable(context)
        
        # Darwin's "strip" doesn't support these arguments.
        if platform.system() != 'Darwin':
            stripped_exename = exename + '.stripped'
            shutil.copyfile(exename, stripped_exename)
            subprocess.check_call(['strip',
                                   '--remove-section=.comment',
                                   '--remove-section=.note',
                                   stripped_exename])
            exename = stripped_exename

        h = hashlib.md5()
        h.update(open(exename, 'rb').read())
        digest = h.hexdigest()

        result.addMetric('hash', lit.Test.toMetricValue(digest))

    except:
        logging.info('Could not calculate hash for %s' %
                     context.test.getFullName())
