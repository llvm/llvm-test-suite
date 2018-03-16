'''Test module to collect google benchmark results.'''
from litsupport import shellcommand
from litsupport import testplan
import csv
import lit.Test


def _mutateCommandLine(context, commandline):
    cmd = shellcommand.parse(commandline)
    cmd.arguments.append("--benchmark_format=csv")
    # We need stdout outself to get the benchmark csv data.
    if cmd.stdout is not None:
        raise Exception("Rerouting stdout not allowed for microbenchmarks")
    benchfile = context.tmpBase + '.bench.csv'
    cmd.stdout = benchfile
    context.microbenchfiles.append(benchfile)

    return cmd.toCommandline()


def _mutateScript(context, script):
    return testplan.mutateScript(context, script, _mutateCommandLine)


def _collectMicrobenchmarkTime(context, microbenchfiles):
    for f in microbenchfiles:
        with open(f) as inp:
            lines = csv.reader(inp)
            # First line: "name,iterations,real_time,cpu_time,time_unit..."
            for line in lines:
                if line[0] == 'name':
                    continue
                # Name for MicroBenchmark
                name = line[0]
                # Create Result object with PASS
                microBenchmark = lit.Test.Result(lit.Test.PASS)

                # Index 3 is cpu_time
                microBenchmark.addMetric('exec_time', lit.Test.toMetricValue(float(line[3])))
              
                # Add Micro Result 
                context.micro_results[name] = microBenchmark

    # returning the number of microbenchmarks collected as a metric for the base test
    return ({'MicroBenchmarks': lit.Test.toMetricValue(len(context.micro_results))})


def mutatePlan(context, plan):
    context.microbenchfiles = []
    plan.runscript = _mutateScript(context, plan.runscript)
    plan.metric_collectors.append(
        lambda context: _collectMicrobenchmarkTime(context,
                                                   context.microbenchfiles)
    )
