import lit.Test
import logging
import shellcommand
import os.path


def collect(context, result):
    try:
        size = os.path.getsize(context.executable)
        result.addMetric('size', lit.Test.toMetricValue(size))
    except:
        logging.info('Could not calculate filesize for %s' %
                     context.executable)
