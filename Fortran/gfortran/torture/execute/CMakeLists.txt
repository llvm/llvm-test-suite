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

# These tests are disabled because they cause internal compiler errors.
file(GLOB Skipped CONFIGURE_DEPENDS
  # error: not a constant derived type expression
  der_init_2.f90
  der_init_3.f90
  der_init_4.f90
  der_init_5.f90
  der_type.f90

  # error: unexpected typeless constant value
  data.f90
  data_2.f90
  dep_fails.f90
  der_init.f90
  der_io.f90
  der_point.f90
  entry_8.f90
  equiv_3.f90
  forall_3.f90
  forall_5.f90
  forall_6.f90
  intrinsic_associated.f90
  intrinsic_len.f90
  iolength_2.f90
  pr32604.f90
  st_function.f90
  where_7.f90
  where_8.f90

  # error: failed to legalize operation 'math.ctlz' that was explicitly marked
  # illegal
  intrinsic_leadz.f90

  # --------------------------------------------------------------------------
  #
  # These tests are skipped because they trigger semantic errors. It may be
  # because they use non-standard features that are currently not supported, or
  # it could be unimplemented features that are not tagged as such.
  #

  # error: Result of ENTRY is not compatible with result of containing function
  entry_2.f90

  # error: '[SYM]' is not a known intrinsic procedure
  specifics.f90
)

# These tests are disabled because they fail at runtime when they should pass.
file(GLOB Failing CONFIGURE_DEPENDS
  data_3.f90
  elemental.f90
  forall_7.f90
  intrinsic_fraction_exponent.f90
  intrinsic_nearest.f90
  intrinsic_sr_kind.f90
  nan_inf_fmt.f90
  random_2.f90
)

list(APPEND UnsupportedTests "")
list(APPEND UnimplementedTests "")
list(APPEND SkippedTests "${Skipped}")
list(APPEND FailingTests "${Failing}")

add_tests("${UnsupportedTests}" "${UnimplementedTests}" "${SkippedTests}" "${FailingTests}")
