Benchmarks for the Clang Static Analyzer
----------------------------------------

This directory specifies the projects and build commands used to
benchmark and test the clang static analyzer and its associated build-system
interposition tools on real-world codebases. The source code for
these projects is not checked into version control. Instead, for each project
we check in (1) scripts to download and build the project and (2) expected
reference results from running the analyzer.

The utils/analyzer/SATestBuild.py script in the clang repository can then be
used to analyze the projects and compare the results with the expected
reference results to find unexpected regressions in the analyzer. The
utils/analyzer/SATestAdd.py script can be used to add projects. The
documentation in that script describes the expected layout of benchmarks in this
directory.
