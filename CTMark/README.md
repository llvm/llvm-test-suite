# CTMark (Compile Time Mark)

This is a collection of applications used for compile-time performance testing. It currently features a selection of the larger applications from the test-suite.

## Usage

Configure llvm-test-suite such that the benchmarks would not be run, so that llvm-lit would only collect the build statistics:

```bash
cmake -G Ninja \
      -S /path/to/llvm-test-suite \
      -B build \
      -DTEST_SUITE_SUBDIRS=/path/to/llvm-test-suite/CTMark \
      -DTEST_SUITE_RUN_BENCHMARKS=0
ninja -C build -j 1
llvm-lit build
```

Note: the build command (`ninja`) should execute a single thread to make the measurements consistent and comparable across different systems with different parallelism capabilities, and reduce noise (resource pressure, thermal throttling etc).

## Additional Resources

- [llvm-test-suite documentation](https://llvm.org/docs/TestSuiteGuide.html)
- [LLVM Compile Time Tracking](https://green.lab.llvm.org/job/llvm.org/)
- [CTMark Introduction (LLVM-dev)](http://lists.llvm.org/pipermail/llvm-dev/2016-November/107087.html)
