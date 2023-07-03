#===------------------------------------------------------------------------===#
#
# Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
# See https://llvm.org/LICENSE.txt for license information.
# SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
#
#===------------------------------------------------------------------------===#

# Creates a test from each valid test file in the current source directory. Each
# argument to a function is a list. If a test file is in any of the lists, a
# test will not be created from it.
function(add_tests UnsupportedTests UnimplementedTests SkippedTests FailingTests)
  # All the tests here are single-source.
  file(GLOB AllFiles CONFIGURE_DEPENDS LIST_DIRECTORIES false
    *.f*
    *.F*
  )

  set(TestsToSkip)

  # There is still a chance that some of the unsupported tests may need to be
  # enabled, for instance if the non-standard extensions that they exercise are
  # supported due to user demand.
  if (NOT TEST_SUITE_FORTRAN_FORCE_ALL_TESTS AND
      NOT TEST_SUITE_FORTRAN_FORCE_UNSUPPORTED_TESTS)
    list(APPEND TestsToSkip ${UnsupportedTests})
  endif()

  # For the remaining tests, there is cause to build and run the skipped, failing
  # and unimplemented tests since some could be enabled once some feature is
  # implemented. Eventually, all the TEST_SUITE_FORTRAN_FORCE_* options (perhaps
  # with the exception of TEST_SUITE_FORTRAN_FORCE_UNSUPPORTED_TESTS) should
  # become redundant and removed.
  if (NOT TEST_SUITE_FORTRAN_FORCE_ALL_TESTS AND
      NOT TEST_SUITE_FORTRAN_FORCE_UNIMPLEMENTED_TESTS)
    list(APPEND TestsToSkip ${UnimplementedTests})
  endif()

  if (NOT TEST_SUITE_FORTRAN_FORCE_ALL_TESTS AND
      NOT TEST_SUITE_FORTRAN_FORCE_FAILING_TESTS)
    list(APPEND TestsToSkip ${FailingTests})
  endif()

  if (NOT TEST_SUITE_FORTRAN_FORCE_ALL_TESTS AND
      NOT TEST_SUITE_FORTRAN_FORCE_SKIPPED_TESTS)
    list(APPEND TestsToSkip ${SkippedTests})
  endif()

  foreach(TestToSkip ${TestsToSkip})
    list(REMOVE_ITEM AllFiles ${TestToSkip})
  endforeach()

  foreach(File ${AllFiles})
    gfortran_execute_test(${File}
      PREFIX "gfortran-torture-execute"
      FFLAGS ""
      LDFLAGS ""
      DEPFILES "")
  endforeach()
endfunction()

set(TESTS)
gfortran_populate_tests(TESTS)
