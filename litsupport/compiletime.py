import glob
import lit.Test
import logging
import os
import timeit


def collect(test, result):
    # TODO: This is not correct yet as the directory may contain .o.time files
    # of multiple benchmarks in the case of SingleSource tests.
    try:
        compile_time = 0.0
        basepath = os.path.dirname(test.getFilePath())
        for path, subdirs, files in os.walk(basepath):
            for file in files:
                if file.endswith('.o.time'):
                    fullpath = os.path.join(path, file)
                    compile_time += timeit.getUserTime(fullpath)
    except IOError:
        logging.info("Could not find compiletime for %s" % test.getFullName())
        return
    result.addMetric('compile_time', lit.Test.toMetricValue(compile_time))
