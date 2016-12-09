Compile Time Mark
=================

This is a collection of applications used for compiler performance testing. It
currently features a selection of larger applications from the test-suite.

This is typically used with the following cmake flags:
$ cmake -DTEST_SUITE_SUBDIRS=CTMark -DTEST_SUITE_RUN_BENCHMARKS=0 ...
(followed by the usual make, llvm-lit invocations, see the test-suite tutorial)

See also:

- http://lab.llvm.org:8080/green/view/Compile%20Time/
- http://lists.llvm.org/pipermail/llvm-dev/2016-November/107087.html
