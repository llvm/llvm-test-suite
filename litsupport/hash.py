import lit.Test
import hashlib
import logging
import subprocess
import shutil
import platform

def collect(context, result):
    try:
        exename = context.test.getFilePath().rsplit('.test', 1)[0]
        backup_exename = exename + '.stripped'
        shutil.copyfile(exename, backup_exename)
        
        # Darwin's "strip" doesn't support these arguments.
        if platform.system() != 'Darwin':
            subprocess.check_call(['strip',
                                   '--remove-section=.comment',
                                   '--remove-section=.note',
                                   backup_exename])

        h = hashlib.md5()
        h.update(open(backup_exename).read())
        digest = h.hexdigest()

        result.addMetric('hash', lit.Test.toMetricValue(digest))

    except:
        logging.info('Could not calculate hash for %s' %
                     context.test.getFullName())
