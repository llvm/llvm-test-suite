#===------------------------------------------------------------------------===#
#
# Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
# See https://llvm.org/LICENSE.txt for license information.
# SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
#
#===------------------------------------------------------------------------===#

# The test-suite expects an executable to be produced at build time and for
# that executable to be run at test time. The result (in the form of the
# return code or the output written to stdout/stderr) is used to determine
# whether the test has succeeded. The "compile" tests are intended to exercise
# the behavior of the compiler itself. There isn't a clean way of having the
# compiler be executed at test time. Instead, the compiler is run at
# build time and the diagnostics/errors saved to a file as needed. This file is
# compared to a reference output at test time to determine success/failure of
# the test. A dummy executable is also built. This does nothing, but provides
# something that the test suite can "run" at test time.

# Creates a test from each valid test file in the current source directory. Each
# argument to a function is a list. If a test file is in any of the lists, a
# test will not be created from it.
function(add_tests UnsupportedTests UnimplementedTests SkippedTests FailingTests)
  # This will just get all the Fortran source files in the directory. The tests
  # in this directory are all single-source.
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

  # The program to be used to verify the results. The programs here should take
  # two files as arguments, return 0 if the files are identical, non-zero
  # otherwise.
  set(DIFFPROG)
  if (WIN32)
    find_program(DIFFPROG
      NAMES fc.exe
      REQUIRED)
  else ()
    find_program(DIFFPROG
      NAMES diff cmp
      REQUIRED)
  endif ()

  # The file prefix is needed because there are several tests with the same
  # file name across the gfortran test suite. cmake prefers all targets to be
  # unique, so they get prefixed with this.
  set(FilePrefix "gfortran-torture-compile")

  # The test suite expects to be able to run something at testing time. For the
  # compile tests, there is nothing to be run. While a better solution will be
  # to modify the test suite to allow for cases like this, as a temporary
  # measure, just create an empty executable that will be run for each test.
  set(DummySrc ${CMAKE_CURRENT_BINARY_DIR}/dummy.f90)
  set(Dummy "dummy")

  file(WRITE ${DummySrc} "program test\nend program test")
  add_executable(${Dummy} ${DummySrc})

  # All the "compile" tests in the gfortran torture tests are expected to
  # pass. Since diagnostics are only saved on failure, the diagnostics
  # file produced when compiling the test should be empty. An empty file can,
  # therefore, be used as reference output.
  set(Reference "${FilePrefix}-empty.reference.out")
  add_custom_command(
    OUTPUT ${Reference}
    COMMAND ${CMAKE_COMMAND} -E touch ${CMAKE_CURRENT_BINARY_DIR}/${Reference}
    VERBATIM
    USES_TERMINAL
    COMMENT "Creating reference output file"
  )

  # The compile script compiles the files and may save the diagnostics to file
  # as needed (see the options that the script accepts).
  set(COMPILE_SCRIPT
    ${CMAKE_SOURCE_DIR}/Fortran/gfortran/compile-save-diags.cmake)

  foreach(File ${AllFiles})
    get_filename_component(FileName ${File} NAME)

    set(Out ${FileName}.out)
    set(Obj ${FileName}.o)

    # ${Exe} is just used as a custom target name. Nevertheless, it needs to be
    # unique. There are multiple files with the same name but different
    # extensions in this directory. Retain the extension, but replace the
    # final '.' with an '_'.
    string(REPLACE "." "_" Exe "${FilePrefix}_${FileName}")

    set(Compiler -DCOMPILER=${CMAKE_Fortran_COMPILER})
    set(CompilerFlags -DCOMPILER_FLAGS=-c)
    set(InputFiles -DINPUT_FILES=${File})
    set(ObjFile -DOBJECT_FILE=${Obj})
    set(OutputFile -DOUTPUT_FILE=${Out})
    set(AlwaysSaveDiags -DALWAYS_SAVE_DIAGS=OFF)

    add_custom_command(
      OUTPUT ${Out}
      COMMAND ${CMAKE_COMMAND} ${Compiler} ${CompilerFlags} ${InputFiles} ${ObjFile} ${OutputFile} ${AlwaysSaveDiags} -P ${COMPILE_SCRIPT}
      VERBATIM
      USES_TERMINAL
      COMMENT "Compiling ${File}")

    add_custom_target(${Exe}
      ALL
      DEPENDS ${Out} ${Reference} ${Dummy}
      SOURCES ${File})

    llvm_test_run(EXECUTABLE %S/${Dummy})
    llvm_test_verify(${DIFFPROG} %S/${Reference} %S/${Out})
    llvm_add_test(${Exe}.test %S/${Dummy})
  endforeach()
endfunction()

# These tests are disabled because they fail, when they should pass.
file(GLOB Failing CONFIGURE_DEPENDS
  # For this, gfortran issues a warning while flang fails to compile. This is
  # potentially an "unsupported" test if the reason for this difference in
  # is because the standard allows for implementation-dependent behavior.
  pr37236.f
)

list(APPEND UnsupportedTests "")
list(APPEND UnimplementedTests "")
list(APPEND SkippedTests "")
list(APPEND FailingTests "${Failing}")

add_tests("${UnsupportedTests}" "${UnimplementedTests}" "${SkippedTests}" "${FailingTests}")
