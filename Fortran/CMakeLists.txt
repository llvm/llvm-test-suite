# Fortran TestSuite Directory Structure (TENTATIVE):
#
# UnitTests    - Single source tests for language features
# Benchmarks   - Single source tests for benchmarking
# Applications - Multi-source tests for proxy apps, small apps, etc.
#
# This file should only contain add_subdirectory(...) one for each test
# directory
add_subdirectory(UnitTests)
add_subdirectory(SNAP)
