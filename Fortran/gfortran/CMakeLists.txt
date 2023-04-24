cmake_minimum_required(VERSION 3.24.0)

include(CheckFortranCompilerFlag)

# NOTE: flang does not currently (as of 2023/03/20) support the -w flag. If
# support for the flag is added, this should be removed.
remove_definitions(-w)

# If the test suite was configured by adding -flang-experimental-exec, remove
# that flag from the default compilation flags. It is only needed at link-time
# anyway, and for that it is explicitly added to those targets that need it.
#
# NOTE: This should be removed once the -flang-experimental-exec flag is no
# longer needed.
string(REPLACE "-flang-experimental-exec" "" TMP_FFLAGS "${CMAKE_Fortran_FLAGS}")
set(CMAKE_Fortran_FLAGS "${TMP_FFLAGS}")

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

# The following cause errors if they are passed to flang via FFLAGS
set(FLANG_ERRORING_FFLAGS
  -fallow-invalid-boz
  -fdec
  -fdec-format-defaults
  -fdec-static
  -fdec-structure
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
  -ff2c
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
  -fno-dec
  -fno-guess-branch-probability
  -fno-ipa-cp
  -fno-ipa-modref
  -fno-ipa-sra
  -fno-pad-source
  -fno-tree-ccp
  -fno-tree-forwprop
  -fno-tree-fre
  -fno-tree-loop-optimize
  -fno-tree-loop-vectorize
  -fpad-source
  -fset-g77-defaults
  -ftest-forall-temp
  -ftree-loop-distribution
  -ftree-loop-vectorize
  -ftree-pre
  -ftree-slp-vectorize
  -ftree-tail-merge
  -ftree-vectorize
  -ftree-vrp
  -mdejagnu-cpu=power4
  # -Os might eventually be supported, so this might also need to be removed
  # at some point
  -Og
  -Os
  # At some point, if we ever support explicit standard flags, some of these
  # should be removed.
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
)

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

# This pulls out options in dg-options into `${Variable}`
function(gfortran_dg_options_fflags Variable File)
  # Some files have dg-options which we need to pick up. These should be in
  # the first line but often aren't.
  #
  # We also need to be careful not to pick up target-specific dg-options.
  set(DG_FFLAGS)

  file(STRINGS ${File} FileLines)
  foreach(FileLine ${FileLines})
    # Looking for `dg-options "..."` or `dg-additional-options "..."` without
    # `{ target` afterwards (ignoring spaces).
    if(FileLine MATCHES "dg-(additional-)?options [{]?[ ]*\"([^\"]*)\"[ ]*[}]?(.*)")
      # This is needed to turn the string into a list of FFLAGS
      separate_arguments(FILE_FFLAGS UNIX_COMMAND ${CMAKE_MATCH_2})
      # This does the negative lookahead for `{ target` anywhere in the rest of
      # the line
      if(NOT "${CMAKE_MATCH_3}" MATCHES "{ +target")
        list(APPEND DG_FFLAGS ${FILE_FFLAGS})
      endif()
    endif()
  endforeach()

  # Remove any flags that will cause flang to raise an error.
  if (DG_FFLAGS)
    list(REMOVE_ITEM DG_FFLAGS ${FLANG_ERRORING_FFLAGS})
  endif()

  # Set the parent scope variable
  set(${Variable} ${DG_FFLAGS} PARENT_SCOPE)
endfunction()

function(gfortran_execute_test File)
  cmake_parse_arguments(GFORTRAN "" "PREFIX" "FFLAGS;LDFLAGS;DEPFILES" ${ARGN})
  # There are a few tests with duplicate filenames, and CMake wants all target
  # names to be unique, so we add a disambiguator to the target name. The
  # disambiguator uses the path of the file relative to the top-level directory
  # containing all the tests from the gfortran test suite.

  # The ${File} argument is guaranteed to be the absolute path to the source
  # file.
  string(REPLACE "${PROJECT_SOURCE_DIR}/Fortran/gfortran/" "" Name "${File}")

  # Replace any '/' separators with 2 underscores. Just replacing it by a single
  # underscore results in conflicts. For instance, there is a conflict between
  # regression/coarray_ptr_comp_2.f08 and regression/coarray/ptr_comp_2.f08
  # which are unrelated tests. Other such conflicts are probably also unrelated.
  string(REPLACE "/" "__" Name "${Name}")

  # Retain the extension of the source file in the final target name because
  # there are cases where two source files with the same basename but different
  # extensions and they, too, represent completely different and unrelated
  # tests.
  string(REPLACE "." "_" Name "${Name}")

  set(_target "${GFORTRAN_PREFIX}-${Name}")

  gfortran_dg_options_fflags(DG_FFLAGS ${File})

  # Add any flags that were requested
  list(APPEND FFLAGS ${DG_FFLAGS} ${GFORTRAN_FFLAGS})
  list(APPEND LDFLAGS ${GFORTRAN_LDFLAGS})

  llvm_test_executable_no_test(${_target} ${File} ${GFORTRAN_DEPFILES})
  llvm_test_run()

  llvm_add_test_for_target(${_target})
  target_include_directories(${_target} PRIVATE ${ISO_FORTRAN_C_HEADER_DIR})

  # This is a workaround because cmake does not currently recognize the .f03
  # and .f08 extensions. A patch to fix cmake has been accepted and the fix
  # should be available in CMake 3.27. It might be better to check the CMake
  # CMake version and do this conditionally.
  list(APPEND SOURCES ${File})
  list(APPEND SOURCES ${GFORTRAN_DEPFILES})
  foreach(Source ${SOURCES})
    get_filename_component(Ext ${Source} LAST_EXT)
    if("${Ext}" STREQUAL ".f03" OR
        "${Ext}" STREQUAL ".F03" OR
        "${Ext}" STREQUAL ".f08" OR
        "${Ext}" STREQUAL ".F08")
      set_source_files_properties(${Source} PROPERTIES LANGUAGE Fortran)
    endif()
  endforeach()

  # NOTE: This should be removed when the -flang-experimental-exec flag is no
  # longer needed.
  target_link_options(${_target} PRIVATE -flang-experimental-exec)
  set_target_properties(${_target} PROPERTIES LINKER_LANGUAGE Fortran)
endfunction()

add_subdirectory(regression)
add_subdirectory(torture)
