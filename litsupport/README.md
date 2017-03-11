Introduction
============

This is the benchmark runner for llvm test-suite. It is only available when the
test-suite was built with cmake. It runs benchmarks, check the results and
collect various metrics such as runtime, compiletime or code size.

The runner is implemented as a custom test format for the llvm-lit tool.

.test Files
===========

.test files specify how to run a benchmark and check the results.

Each line in a .test file may specify a PREPARE:, RUN: or VERIFY: command as a
shell command. Each command kind can be specified multiple times to execute
multiple commands. A benchmark run will first execute all prepare commands,
then all run commands and finally all verify commands. Metrics like runtime or
profile data is collected during the RUN: commands.

The lit runner accepts the most common posix shell commands like assigning
environment variables, redirecting input and outputs and changing the directory
before starting a benchmark (see shellcommand.py for details).

Example:

    RUN: ./mybenchmark --size 500 --verbose > run0.txt
    VERIFY: diff reference_results0.txt run0.txt
    RUN: ./mybenchmark --size 300 --seed 5555 --verbose > run1.txt
    VERIFY: diff reference_results1.txt run1.txt

Usage
=====

Running cmake on the test-suite creates a `lit.site.cfg` and .test files for each bechmark. llvm-lit can then be used as usual. Some examples:

    # Run all benchmark in the current directory an subdirecories one at a time.
    $ llvm-lit -j1 .

    # Run a single benchmark and show executed commands and collected metrics.
    $ llvm-lit -a SingleSource/Benchmarks/Misc/pi.test

    # Run benchmarks with reduced lit output but save collected metrics to json
    # file. This format is used by LNT or viewable by test-suite/utils/compare.py.
    $ llvm-lit . -o result.json -s
