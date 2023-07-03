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
  # This will just get all the Fortran source files in the directory. Since
  # the tests here are a mix of single-source and multi-source tests, this will
  # include files that are dependencies of some "main" test file as well. Those
  # will be filtered out later.
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

  # For now, only the execute tests are supported. Those have a "{ dg-do run }"
  # or a "{ dg-lto-do run }" directive.
  foreach(File ${AllFiles})
    set(MAIN)
    set(ADDITIONAL_SOURCES)
    set(ADDITIONAL_FFLAGS)
    set(ADDITIONAL_LDFLAGS)

    file(STRINGS ${File} FileLines)
    foreach(FileLine ${FileLines})
      if(FileLine MATCHES "^.*[{][ ]*dg-(lto-)?do[ ]*([A-Za-z0-9]+).*[}].*$")
        # If this is not a main file for an execute test, just move on to the
        # next file.
        if (NOT ${CMAKE_MATCH_2} MATCHES "run")
          break()
        else()
          set(MAIN "${File}")
        endif()
      elseif(FileLine MATCHES "dg-additional-sources[ ]*[\"]?(.+)[\"]?[ ]*[}]")
        separate_arguments(ADDITIONAL_SOURCES UNIX_COMMAND ${CMAKE_MATCH_1})
        list(TRANSFORM ADDITIONAL_SOURCES STRIP)
      endif()
    endforeach()

    if (MAIN)
      gfortran_execute_test(${MAIN}
        PREFIX "gfortran-regression-execute"
        FFLAGS ${ADDITIONAL_FFLAGS}
        LDFLAGS ${ADDITIONAL_LDFLAGS}
        DEPFILES ${ADDITIONAL_SOURCES})
    endif()
  endforeach()
endfunction()

set(TESTS)
gfortran_populate_tests(TESTS)

add_subdirectory(analyzer)
add_subdirectory(asan)
add_subdirectory(c-interop)
add_subdirectory(coarray)
add_subdirectory(debug)
add_subdirectory(g77)
add_subdirectory(goacc)
add_subdirectory(goacc-gomp)
add_subdirectory(gomp)
add_subdirectory(gomp/appendix-a)
add_subdirectory(graphite)
add_subdirectory(guality)
add_subdirectory(ieee)
add_subdirectory(lto)
add_subdirectory(prof)
add_subdirectory(ubsan)
add_subdirectory(vect)

file(COPY lit.local.cfg DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")
