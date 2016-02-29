import lit.Test
import hashlib
import logging

def collect(context, result):
    try:
        exename = context.test.getFilePath().rsplit('.test', 1)[0]

        h = hashlib.md5()
        h.update(open(exename).read())
        digest = h.hexdigest()

        result.addMetric('hash', lit.Test.toMetricValue(digest))

    except:
        logging.info('Could not calculate hash for %s' %
                     context.test.getFullName())
