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

# The gfortran subdirectory contains tests imported as-is from gfortran's
# test suite. These have not been widely tested, so they are only enabled for
# certain combinations of platforms and architectures.
if (NOT WIN32 AND NOT APPLE)
  if (ARCH MATCHES "x86" OR ARCH MATCHES "AArch64")
    add_subdirectory(gfortran)
  endif()
endif()
