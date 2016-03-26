import lit.Test
import os
import timeit


def _getCompileTime(context):
    basepath = os.path.dirname(context.test.getFilePath())
    dirs = [basepath]
    # Single source .o/.o.time files are placed in a different directory.
    name = os.path.basename(basepath)
    alternate_dir = "%s/../CMakeFiles/%s.dir" % (basepath, name)
    dirs.append(alternate_dir)

    # TODO: This is not correct yet as the directory may contain .o.time files
    # of multiple benchmarks in the case of SingleSource tests.
    compile_time = 0.0
    link_time = 0.0
    for dir in dirs:
        for path, subdirs, files in os.walk(dir):
            for file in files:
                if file.endswith('.o.time'):
                    fullpath = os.path.join(path, file)
                    compile_time += timeit.getUserTime(fullpath)
                if file.endswith('.link.time'):
                    fullpath = os.path.join(path, file)
                    link_time += timeit.getUserTime(fullpath)
    return {
        'compile_time': lit.Test.toMetricValue(compile_time),
        'link_time': lit.Test.toMetricValue(link_time),
    }


def mutatePlan(context, plan):
    plan.metric_collectors.append(_getCompileTime)
