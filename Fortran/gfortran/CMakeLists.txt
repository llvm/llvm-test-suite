cmake_minimum_required(VERSION 3.24.0)

include(CheckFortranCompilerFlag)

# NOTE: flang does not currently (as of 2023/03/20) support the -w flag. If
# support for the flag is added, this should be removed.
remove_definitions(-w)

# This option is added because as of 2023/03/20, several tests in this
# directory have been disabled. Some of them exercise unsupported non-standard
# extensions, others trigger a "not yet implemented" assertion while some cause
# flang to crash. This option forces all the tests to build and can be used to
# determine if any of the disabled tests can be enabled.
option(TEST_SUITE_FORTRAN_FORCE_ALL_TESTS
  "Build and run all gfortran tests, including those in the 'unsupported', 'unimplemented', 'skipped', and 'failing' categories."
  OFF)

# Since the FORCE_ALL_TESTS option is a bit too blunt, there are some other
# options to force building some subsets of the disabled tests.

# The 'unsupported' tests exercise non-standard extensions that are not
# currently supported. But there is a chance some may be in the future, in which
# case, it may be worthwhile seeing if any can be removed from the list and
# enabled permanently.
option(TEST_SUITE_FORTRAN_FORCE_UNSUPPORTED_TESTS
  "Build and run all 'unsupported' gfortran tests. These usually test non-standard extensions."
  OFF)

# The 'unimplemented' tests trigger a "not yet implemented" assertion at
# compile-time. If those features are implemented, enabling those tests may help
# in identifying those that can be removed from the list and permanently enabled
# because the root cause has been addressed.
option(TEST_SUITE_FORTRAN_FORCE_UNIMPLEMENTED_TESTS
  "Build and run all 'unimplemented' gfortran tests. These are tests that fail at build-time because of unimplemented features in flang."
  OFF)

# The 'skipped' tests cause flang to crash at compile-time for "non-obvious"
# reasons. They could be related to unimplemented features, or they could be
# bugs in the compiler. In any case, enabling them may help identify those tests
# that can be removed from the list and permanently enabled because the root
# cause has been addressed.
option(TEST_SUITE_FORTRAN_FORCE_SKIPPED_TESTS
  "Build and run all 'skipped' gfortran tests. These are tests that cause flang to crash."
  OFF)

# The 'failing' tests fail to pass either because of a bug somewhere in the
# compiler or the runtime. Enabling these tests may help identify those tests
# that can be removed from the list and permanently enabled because the root
# cause has been addressed.
option(TEST_SUITE_FORTRAN_FORCE_FAILING_TESTS
  "Build and run all 'failing' tests. These tests failed at runtime, perhaps due to bugs in the code generator or bugs/unimplemented features in the runtime."
  OFF)

# The ISO_Fortran_binding.h file is required to run some of the tests. This
# header is copied to ${CMAKE_INSTALL_PREFIX}/include/flang at flang install
# time which can be found automatically. If the compiler being tested here is
# not installed, that file will not be found. In that case, the path to it must
# be provided explicitly.
set(TEST_SUITE_FORTRAN_ISO_C_HEADER_DIR "" CACHE STRING
  "Path to the directory containing ISO_Fortran_bindings.h header file.")

# The following cause errors if they are passed to flang via FFLAGS. This could
# be because they are currently unsupported and might eventually be supported
# or because they are GCC-specific and will never be supported.
set(FLANG_ERRORING_FFLAGS
  max-completely-peel-loop-nest-depth=1
  -fallow-invalid-boz
  -fcheck-array-temporaries
  -fcheck=bounds
  -fcheck=do
  -fcheck=recursion
  -fcoarray=lib
  -fcray-pointer
  -fdec
  -fdec-format-defaults
  -fdec-static
  -fdec-structure
  -frecord-marker=4
  -fbounds-check
  -fcheck-bounds
  -fcheck=all
  -fcheck=bits
  # Not sure if the -fdefault-* options will be supported. Maybe in a different
  # form in which case, this will have to be modified to accommodate those.
  -fdefault-real-10
  -fdefault-real-16
  -fdump-ipa-cp-details
  -fdump-ipa-fnsummary-details
  -fdump-ipa-inline-details
  -fdump-rtl-expand
  -fdump-tree-all
  -fdump-tree-cunroll-details
  -fdump-tree-cunrolli-details
  -fdump-tree-fre1
  -fdump-tree-gimple
  -fdump-tree-ifcvt
  -fdump-tree-lversion-details
  -fdump-tree-omplower
  -fdump-tree-optimized
  -fdump-tree-original
  -fdump-tree-pcom-details
  -fdump-tree-pre-details
  -fdump-tree-profile-estimate
  -fdump-tree-reassoc1
  -fdump-tree-vect-details
  -fexpensive-optimizations
  -ff2c
  -ffree-line-length-none
  -ffrontend-optimize
  -fgcse
  -finline-matmul-limit=0
  -finline-matmul-limit=10
  -finline-matmul-limit=100
  -finline-matmul-limit=1000
  -finline-matmul-limit=2
  -finline-matmul-limit=30
  -fipa-cp
  -fipa-cp-clone
  -fipa-pta
  -fipa-reference
  -fmodulo-sched
  -fno-align-commons
  -fno-asynchronous-unwind-tables
  -fno-backtrace
  -fno-bounds-check
  -fno-check-array-temporaries
  -fno-dec
  -fno-f2c
  -fno-frontend-optimize
  -fno-guess-branch-probability
  -fno-inline
  -fno-ipa-cp
  -fno-ipa-modref
  -fno-ipa-sra
  -fno-pad-source
  -fno-range-check
  -fno-realloc-lhs
  -fno-sign-zero
  -fno-strict-aliasing
  -fno-tree-ccp
  -fno-tree-forwprop
  -fno-tree-fre
  -fno-tree-loop-optimize
  -fno-tree-loop-vectorize
  -fpad-source
  -fpeel-loops
  -frecursive
  -fsanitize=undefined
  -fset-g77-defaults
  -fshort-enums
  -ftest-forall-temp
  -ftree-loop-distribution
  -ftree-loop-vectorize
  -ftree-pre
  -ftree-slp-vectorize
  -ftree-tail-merge
  -ftree-vectorize
  -ftree-vrp
  -funroll-loops
  -fwrapv
  -mdalign
  -mdejagnu-cpu=power4
  -mfpmath=387
  -mfpmath=sse
  -mtune=amdfam10
  # -Os might eventually be supported, so this might also need to be removed
  # at some point
  -Og
  -Os
  # At some point, if we ever support explicit standard flags, some of these
  # should be removed.
  -pedantic-errors
  -std=gnu
  -std=legacy
  -std=f95
  -std=f2003
  -std=f2008
  -std=f2008ts
  # At the time of writing, -W warnings are not supported. flang errors out
  # saying that only -Werror is supported.
  -Wall
  -Wampersand
  -Wanalyzer-too-complex
  -Warray-bounds
  -Warray-temporaries
  -Wconversion
  -Wconversion-extra
  -Werner
  -Werror
  -Wextra
  -Wfunction-elimination
  -Wimplicit-procedure
  -Wintrinsic-shadow
  -Wintrinsics-std
  -Wline-truncation
  -Wno-all
  -Wno-analyzer-null-dereference
  -Wno-analyzer-possible-null-dereference
  -Wno-analyzer-too-complex
  -Wno-analyzer-use-of-uninitialized-value
  -Wno-c-binding-type
  -Wno-complain-wrong-lang
  -Wno-error
  -Wno-intrinsic-shadow
  -Wno-intrinsics-std
  -Wno-lto-type-mismatch
  -Wno-tabs
  -Wno-underflow
  -Wrealloc-lhs
  -Wrealloc-lhs-all
  -Wreturn-type
  -Wstringop-overflow
  -Wsurprising
  -Wtabs
  -Wuninitialized
  -Wunused
  -Wunused-dummy-argument
  -Wunused-function
  -Wunused-parameter
  -Wunused-variable
  -Wzerotrip
  -w
  --param
)

# Find all the Fortran files in the current source directory that may be test
# files. This will filter out those files that have been explicitly disabled
# for any reason. The returned files will be consist of the main file for
# "execute" and "compile" tests as well as any dependencies for multi-file
# tests.
function(gfortran_find_test_files unsupported unimplemented skipped failing out)
  # This will just get all the Fortran source files in the directory. Since
  # the tests may be a mix of single-source and multi-source tests, this will
  # include files that are dependencies of some "main" test file as well.
  file(GLOB files CONFIGURE_DEPENDS LIST_DIRECTORIES false
    *.f*
    *.F*
  )

  set(ignore "")

  # There is still a chance that some of the unsupported tests may need to be
  # enabled, for instance if the non-standard extensions that they exercise are
  # supported due to user demand.
  if (NOT TEST_SUITE_FORTRAN_FORCE_ALL_TESTS AND
      NOT TEST_SUITE_FORTRAN_FORCE_UNSUPPORTED_TESTS)
    list(APPEND ignore ${unsupported})
  endif()

  # For the remaining tests, there is cause to build and run the skipped, failing
  # and unimplemented tests since some could be enabled once some feature is
  # implemented. Eventually, all the TEST_SUITE_FORTRAN_FORCE_* options (perhaps
  # with the exception of TEST_SUITE_FORTRAN_FORCE_UNSUPPORTED_TESTS) should
  # become redundant and removed.
  if (NOT TEST_SUITE_FORTRAN_FORCE_ALL_TESTS AND
      NOT TEST_SUITE_FORTRAN_FORCE_UNIMPLEMENTED_TESTS)
    list(APPEND ignore ${unimplemented})
  endif()

  if (NOT TEST_SUITE_FORTRAN_FORCE_ALL_TESTS AND
      NOT TEST_SUITE_FORTRAN_FORCE_SKIPPED_TESTS)
    list(APPEND ignore ${skipped})
  endif()

  if (NOT TEST_SUITE_FORTRAN_FORCE_ALL_TESTS AND
      NOT TEST_SUITE_FORTRAN_FORCE_FAILING_TESTS)
    list(APPEND ignore ${failing})
  endif()

  foreach(file ${ignore})
    list(REMOVE_ITEM files ${file})
  endforeach()

  set(${out} ${files} PARENT_SCOPE)
endfunction()

# Populate the tests from the files in the subdirectory. This macro will be
# called from each subdirectory containing tests. It is expected that the
# subdirectory will contain a file named "DisabledFiles.cmake" which will
# provide the list of files that are disabled in that subdirectory for various
# reasons. A list named TESTS is expected to be in scope before this macro is
# called.
macro(gfortran_populate_tests TESTS)
  string(REPLACE "${CMAKE_SOURCE_DIR}/" "" DIR "${CMAKE_CURRENT_SOURCE_DIR}")
  message(STATUS "Adding directory ${DIR}")

  set(UNSUPPORTED "")
  set(UNIMPLEMENTED "")
  set(SKIPPED "")
  set(FAILING "")

  # This will provide the lists of unsupported, unimplemented, skipped and
  # failing files.
  include(${CMAKE_CURRENT_SOURCE_DIR}/DisabledFiles.cmake)

  list(APPEND UNSUPPORTED ${UNSUPPORTED_FILES})
  list(APPEND UNIMPLEMENTED ${UNIMPLEMENTED_FILES})
  list(APPEND SKIPPED ${SKIPPED_FILES})
  list(APPEND FAILING ${FAILING_FILES})

  # do the same for any requested feature extentions
  foreach(feature ${TEST_SUITE_FORTRAN_FEATURES})
    set(UNSUPPORTED_FILES "")
    set(UNIMPLEMENTED_FILES "")
    set(SKIPPED_FILES "")
    set(FAILING_FILES "")
    include(${CMAKE_CURRENT_SOURCE_DIR}/DisabledFiles${feature}.cmake)
    list(APPEND UNSUPPORTED ${UNSUPPORTED_FILES})
    list(APPEND UNIMPLEMENTED ${UNIMPLEMENTED_FILES})
    list(APPEND SKIPPED ${SKIPPED_FILES})
    list(APPEND FAILING ${FAILING_FILES})

    # enable any tests that now pass for this feature
    set(SUPPORTED_FILES "")
    set(IMPLEMENTED_FILES "")
    set(UNSKIPPED_FILES "")
    set(PASSING_FILES "")
    include(${CMAKE_CURRENT_SOURCE_DIR}/EnabledFiles${feature}.cmake)
    list(REMOVE_ITEM UNSUPPORTED ${SUPPORTED_FILES})
    list(REMOVE_ITEM UNIMPLEMENTED ${IMPLEMENTED_FILES})
    list(REMOVE_ITEM SKIPPED ${UNSKIPPED_FILES})
    list(REMOVE_ITEM FAILING ${PASSING_FILES})
  endforeach()

  # The TESTS variable is expected to be set before the macro is called.
  gfortran_find_test_files(
    "${UNSUPPORTED}" "${UNIMPLEMENTED}" "${SKIPPED}" "${FAILING}" "${TESTS}")
endmacro()

# Generate a unique target name from the given base and prepend it with the
# given prefix.
function(gfortran_unique_target_name prefix base out)
  # There are a few tests - in different directories - with duplicate filenames.
  # CMake requires all target names to be unique, so we add a disambiguator. The
  # disambiguator uses the path of the file relative to the top-level directory
  # containing all the tests from the gfortran test suite to ensure that
  # targets in different directories will have distinct names.
  set(result "")

  # The ${base} argument is guaranteed to be the absolute path to a source file.
  string(REPLACE "${PROJECT_SOURCE_DIR}/Fortran/gfortran/" "" result "${base}")

  # Replace any '/' separators with 2 underscores. Just replacing it by a single
  # underscore results in conflicts. For instance, there is a conflict between
  # regression/coarray_ptr_comp_2.f08 and regression/coarray/ptr_comp_2.f08
  # which are unrelated tests. Other such conflicts are probably also unrelated.
  string(REPLACE "/" "__" result "${result}")

  # Retain the extension of the source file in the final target name because
  # there are cases where two source files with the same basename but different
  # extensions and they, too, represent completely different and unrelated
  # tests.
  string(REPLACE "." "_" result "${result}")

  set(${out} "${prefix}-${result}" PARENT_SCOPE)
endfunction()

# Several tests in the suite build modules with the same name at build-time.
# Others create/write/read files with the same name at test-time. In either
# case, these are race conditions which can lead to non-deterministic failures
# at build and/or test time. To work around this, have each test run in its
# own directory.
#
# This directory is also used as module directory at build-time.
#
# It may be "cleaner" to have separate directories - one that serves as the
# module directory and the other as the working directory, but that is
# probably unnecessary.
#
# Make a working directory for the given target and return the full path of
# the resulting directory.
function(gfortran_make_working_dir tgt out)
  set(working_dir "${CMAKE_CURRENT_BINARY_DIR}/${tgt}.wd")

  file(MAKE_DIRECTORY ${working_dir})

  set("${out}" "${working_dir}" PARENT_SCOPE)
endfunction()

# Setup a "compile" test. EXPECT_ERROR will be ON if the compile test is
# expected to fail, OFF otherwise. MAIN is the main test file. In the case of
# multi-file tests, OTHERS will be the remaining files needed by the test.
# FFLAGS are compiler flags needed by the test. LDFLAGS are linker flags needed
# by the test.
function(gfortran_add_compile_test expect_error main others fflags ldflags)
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

  # PREFIX_COMPILE will have been defined in the subdirectory from which this
  # function is called.
  gfortran_unique_target_name("${PREFIX_COMPILE}" "${main}" target)
  gfortran_make_working_dir("${target}" working_dir)

  # The output of the compilation of the test file. This may contain warnings
  # and error messages. If the compilation succeeded without any warnings or
  # other diagnostics, it will be empty.
  set(out ${target}.out)

  # Add the CMake-wide environment variable CMAKE_Fortran_FLAGS
  # CMake escapes spaces. To really get a space (between arguments) use a ;
  string(REPLACE " " ";" fflags ${fflags} ";" ${CMAKE_Fortran_FLAGS})

  add_custom_command(
    OUTPUT ${out}
    COMMAND ${CMAKE_COMMAND}
    -DCMD="${CMAKE_Fortran_COMPILER_LAUNCHER};${CMAKE_Fortran_COMPILER};-c;${fflags};${ldflags};${others};${main}"
    -DALWAYS_SAVE_DIAGS=OFF
    -DWORKING_DIRECTORY=${working_dir}
    -DOUTPUT_FILE=${out}
    -P ${COMPILE_SCRIPT_BIN}
    USES_TERMINAL
    COMMENT "Compiling ${main}")

  add_custom_target(${target}
    ALL
    DEPENDS ${out}
    SOURCES ${main} ${others})

  # The dummy and empty reference output files are in
  # ${CMAKE_BINARY_DIR}/Fortran/gfortran. This function could be called from
  # any of the subdirectories under ${CMAKE_BINARY_DIR}/Fortran/gfortran. The
  # tests need paths relative to the directory containing the test, so calculate
  # the relative path back to ${CMAKE_BINARY_DIR}/Fortran/gfortran.
  file(RELATIVE_PATH relpath
    ${CMAKE_CURRENT_BINARY_DIR}
    ${CMAKE_BINARY_DIR}/Fortran/gfortran)

  # The test suite expects an executable to run, so give it the dummy (see
  # comments above).
  llvm_test_run(EXECUTABLE %S/${relpath}/${DUMMY_EXE})

  # The verification compares the saved diagnostics file against what is
  # expected. For the test. The reference output may have been extracted from
  # the DejaGNU annotations in the test file, or it may be an empty file if the
  # compilation of the test file was expected to be successful and without any
  # diagnostics.
  if (expect_error)
    # Since we don't check for any particular error, we expect "some" error.
    # In that case, the compiler's diagnostic output will be non-empty.
    llvm_test_verify(${TESTCMD} -s %S/${out})
  else ()
    llvm_test_verify(${DIFFPROG} %S/${relpath}/${EMPTY_FILE} %S/${out})
  endif ()

  llvm_add_test(${target}.test %S/${relpath}/${DUMMY_EXE})
endfunction()

# Look for "compile" tests in TESTS and create a test for each "main" file that
# is found.
function(gfortran_add_compile_tests_from tests)
  cmake_parse_arguments(GFORTRAN "" "" "FFLAGS;LDFLAGS" ${ARGN})

  foreach (file ${tests})
    # Whether this test is expected to pass or fail.
    set(expect_error OFF)

    # For multi-file tests, these are the other files needed. For the "compile"
    # tests, there don't seem to be any multi-file tests at the time of writing,
    # but leave it general in case that ever changes.
    set(others "")

    set(fflags "")
    set(ldflags "")
    list(APPEND fflags ${GFORTRAN_FFLAGS})
    list(APPEND ldflags ${GFORTRAN_LDFLAGS})

    file(STRINGS ${file} lines)
    foreach (line ${lines})
      # The "compile" tests have a { dg-do compile } directive.
      if (line MATCHES "^.*[{][ ]*dg-do[ ]*compile(.*)[}].*$")
        # TODO: We completely ignore any target directives that may be attached
        # to the run directives. For now, it seems to be ok, but as these tests
        # are enabled on more platforms, the target directives might need to be
        # handled.
      elseif (line MATCHES "dg-additional-sources[ ]*[\"]?(.+)[\"]?[ ]*[}]")
        separate_arguments(others UNIX_COMMAND ${CMAKE_MATCH_1})
        list(TRANSFORM others STRIP)
      elseif (LINE MATCHES "dg-(additional-)?options [{]?[ ]*\"([^\"]*)\"[ ]*[}]?(.*)")
        # TODO: We completely ignore any target directives that may be attached
        # to the run directives. For now, it seems to be ok, but as these tests
        # are enabled on more platforms, the target directives might need to be
        # handled.
        separate_arguments(file_fflags UNIX_COMMAND ${CMAKE_MATCH_2})
        list(REMOVE_ITEM file_fflags ${FLANG_ERRORING_FFLAGS})
        list(APPEND fflags ${file_fflags})
      elseif (line MATCHES "[{][ ]*dg-error[ ]*")
        # Currently, we don't try to match gfortran's expected errors with
        # flang's expected error messages. Instead, if gfortran expects an
        # error, we test that flang produces "some" error.
        # TODO: It may be more useful to match gfortran's error messages to
        # flang's in which case we should do something more sophisticated here,
        # but as a first pass, the more basic approach should do.
        set(expect_error ON)
      endif()
    endforeach()

    # Some files look like they ought to be "compile" tests but they don't
    # contain a DejaGNU compile directive. Some have an error or other
    # directive that could be used to infer that they are actually compile tests
    # but for those that are intended to succeed, there may be no directives
    # at all. So just treat all files as if they were "compile" tests (even
    # those that are the main files of execute tests and ones that are
    # dependencies in multi-file tests).
    gfortran_add_compile_test(${expect_error} ${file} "${others}" "${fflags}" "${ldflags}")
  endforeach()
endfunction()

# Creates a "compile" test from each file in TESTS. It is assumed that the
# compilation is intended to succeed. Any compile/link flags that the test needs
# must be passed explicitly.
function(gfortran_add_compile_tests tests)
  cmake_parse_arguments(GFORTRAN "" "" "FFLAGS;LDFLAGS" ${ARGN})

  list(APPEND fflags ${GFORTRAN_FFLAGS})
  list(APPEND ldflags ${GFORTRAN_LDFLAGS})

  foreach (file ${tests})
    gfortran_add_compile_test(OFF ${file} "" "${fflags}" "${ldflags}")
  endforeach()
endfunction()

# Setup an "execute" test. In the case of multi-file tests, MAIN will be the
# main file. For multi-file tests, OTHERS will be the remaining files needed by
# the test. FFLAGS are additional compiler flags needed by the test. LDFLAGS
# are the other linker flags needed by the test.
function(gfortran_add_execute_test main others fflags ldflags)
  # PREFIX_EXECUTE will have been defined in the subdirectory from which this
  # function is called.
  gfortran_unique_target_name("${PREFIX_EXECUTE}" "${main}" target)
  gfortran_make_working_dir("${target}" working_dir)
  get_filename_component(working_dir_name "${working_dir}" NAME)

  llvm_test_executable_no_test(${target} ${main} ${others})
  llvm_test_run(WORKDIR "%S/${working_dir_name}")
  llvm_add_test_for_target(${target})

  target_include_directories(${target}
    PRIVATE ${ISO_FORTRAN_C_HEADER_DIR} ${working_dir})
  target_compile_options(${target} PRIVATE "${fflags}")
  target_link_options(${target} PRIVATE "${ldflags}")
  set_target_properties(${target} PROPERTIES
    Fortran_MODULE_DIRECTORY ${working_dir})

  # This is a workaround because cmake does not currently recognize the .f03
  # and .f08 extensions. A patch to fix cmake has been accepted and the fix
  # should be available in CMake 3.27. It might be better to check the CMake
  # version and do this conditionally.
  list(APPEND sources ${main})
  list(APPEND sources ${others})
  foreach(source ${sources})
    get_filename_component(ext ${source} LAST_EXT)
    if("${ext}" STREQUAL ".f03" OR
        "${ext}" STREQUAL ".F03" OR
        "${ext}" STREQUAL ".f08" OR
        "${ext}" STREQUAL ".F08")
      set_source_files_properties(${source} PROPERTIES LANGUAGE Fortran)
    endif()
  endforeach()

  set_target_properties(${target} PROPERTIES LINKER_LANGUAGE Fortran)
endfunction()

# Look for "execute" tests in TESTS and create a test for each "main" file that
# is found. In the case of multi-file tests, other files may be needed for the
# test. Those will be obtained by parsing the DejaGNU directives in the "main"
# file.
function(gfortran_add_execute_tests_from tests)
  cmake_parse_arguments(GFORTRAN "" "" "FFLAGS;LDFLAGS" ${ARGN})

  foreach(file ${tests})
    # The file containing the "run" directive will be the main file.
    set(main "")

    # For multi-file tests, these are the other files needed.
    set(others "")

    # Any flags needed to compile the test. These will be flang-specific flags.
    # Directives in the test files may specify additional flags needed by the
    # test. Those will be parsed in gfortran_add_execute_test.
    set(fflags "")
    set(ldflags "")
    list(APPEND fflags ${GFORTRAN_FFLAGS})
    list(APPEND ldflags ${GFORTRAN_LDFLAGS})

    file(STRINGS ${file} lines)
    foreach (line ${lines})
      # The "execute" tests have a { dg-do run }, or a { dg-lto-do run }
      # directive.
      if (line MATCHES "^.*[{][ ]*dg-(lto-)?do[ ]*run (.*)[}]$")
        # TODO: We completely ignore any target directives that may be attached
        # to the run directives. For now, it seems to be ok, but as these tests
        # are enabled on more platforms, the target directives might need to be
        # handled.
        set(main "${file}")
      elseif (line MATCHES "dg-additional-sources[ ]*[\"]?(.+)[\"]?[ ]*[}]")
        separate_arguments(others UNIX_COMMAND ${CMAKE_MATCH_1})
        list(TRANSFORM others STRIP)
      elseif (line MATCHES "dg-(additional-)?options [{]?[ ]*\"([^\"]*)\"[ ]*[}]?(.*)")
        # TODO: We completely ignore any target-specific options that may be
        # present. These are usually in the form of target directives. For now,
        # it seems to be ok, but as these tests are enabled on more platforms,
        # target directives might need to be handled.
        separate_arguments(file_fflags UNIX_COMMAND ${CMAKE_MATCH_2})
        list(REMOVE_ITEM file_fflags ${FLANG_ERRORING_FFLAGS})
        list(APPEND fflags ${file_fflags})
      endif()
    endforeach()

    # Since any dependent files could also be processed by this function, there
    # is no guarantee that main will have been set.
    if (main)
      gfortran_add_execute_test(${main} "${others}" "${fflags}" "${ldflags}")
    endif()
  endforeach()
endfunction()

# Creates an "execute" test from each file in TESTS. The tests are assumed to
# not contain any additional DejaGNU directives. Any compiler/linker flags
# needed by the test must be passed explicitly.
function(gfortran_add_execute_tests tests)
  cmake_parse_arguments(GFORTRAN "" "" "FFLAGS;LDFLAGS" ${ARGN})

  list(APPEND fflags ${GFORTRAN_FFLAGS})
  list(APPEND ldflags ${GFORTRAN_LDFLAGS})

  foreach(file ${tests})
    gfortran_add_execute_test(${file} "" "${fflags}" "${ldflags}")
  endforeach()
endfunction()

set(HEADER_SEARCH_PATH "${TEST_SUITE_FORTRAN_ISO_C_HEADER_DIR}")
if (NOT HEADER_SEARCH_PATH)
  get_filename_component(Fortran_BINDIR ${CMAKE_Fortran_COMPILER} DIRECTORY)
  get_filename_component(Fortran_PREFIX ${Fortran_BINDIR} DIRECTORY)

  set(HEADER_SEARCH_PATH "${Fortran_PREFIX}/include/flang")
endif()

find_file(ISO_FORTRAN_C_HEADER
  ISO_Fortran_binding.h
  PATHS ${HEADER_SEARCH_PATH}
  REQUIRED)

get_filename_component(ISO_FORTRAN_C_HEADER_DIR
  "${ISO_FORTRAN_C_HEADER}"
  DIRECTORY)

# The program to be used to verify the results. The programs here should take
# two files as arguments, return 0 if the files are identical, non-zero
# otherwise.
set(DIFFPROG)
if (WIN32)
  # Windows support has been disabled earlier anyway, but at some point, we
  # should find a way to check if a file is non-empty on windows.
  message(FATAL_ERROR "No way to check file size in Windows.")
  find_program(DIFFPROG
    NAMES fc.exe
    REQUIRED)
else ()
  # FIXME: For the moment, check if a file is not empty, by using the test
  # command/shell built-in on *nix. But it is not clear that all systems will
  # have this. What we really need is to invert the result of DIFFPROG. LLVM has
  # a not utility that will do just this. But it needs LLVM's build directory
  # to be present unless it is installed on the system already. It is not clear
  # if we can depend on this.
  find_program(TESTCMD
    NAMES test
    REQUIRED)
  find_program(DIFFPROG
    NAMES diff cmp
    REQUIRED)
endif ()

# The test suite expects to be able to run something at test-time. For the
# compile tests, there is nothing to be run. While a better solution will be
# to modify the test suite to allow for cases like this, for the moment, just
# create an empty executable that will be run for each test.
set(DUMMY_SRC ${CMAKE_CURRENT_BINARY_DIR}/dummy.f90)
file(WRITE ${DUMMY_SRC} "program test\nend program test")

set(DUMMY_EXE "dummy")
add_executable(${DUMMY_EXE} ${DUMMY_SRC})

# This script compiles the files that are "compile" tests. It may save the
# diagnostics to file as needed (see the options that the script accepts). There
# should be no dependence on the source files at test-time, so copy the compile
# script over to the build directory. For the moment, nothing is compiled at
# test-time, but that might change.
set(COMPILE_SCRIPT compile-save-diags.cmake)
set(COMPILE_SCRIPT_SRC ${CMAKE_CURRENT_SOURCE_DIR}/${COMPILE_SCRIPT})
set(COMPILE_SCRIPT_BIN ${CMAKE_CURRENT_BINARY_DIR}/${COMPILE_SCRIPT})

file(COPY
  ${CMAKE_CURRENT_SOURCE_DIR}/${COMPILE_SCRIPT}
  DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

# In some case, the "compile" tests are expected to pass. Since diagnostics are
# only saved on failure, the diagnostics file produced when compiling the test
# should be empty. An empty file can, therefore, be used as reference output.
set(EMPTY_FILE "gfortran-compile-empty.reference.out")
file(TOUCH ${CMAKE_CURRENT_BINARY_DIR}/${EMPTY_FILE})

add_subdirectory(regression)
add_subdirectory(torture)
