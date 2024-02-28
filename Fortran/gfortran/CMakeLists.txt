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
#
# FIXME: The flags here necessarily include the value as well, not just the
# flag itself. For instance, in the list are -fcheck=all, -fcheck=bits etc. In
# principle, one only needs the -fcheck. The argument should not matter. The
# problem is that the annotation parser currently does not parse the flag into
# `flag-name` and `flag-value`. Once this is fixed, we need only have the
# flag name here.
set(FLANG_ERRORING_FFLAGS
  # The "flags" that do not start with a hyphen (-) are actually arguments to
  # some other flag but use the "-flag value" syntax (as opposed to the
  # "-flag=value" syntax). Since we don't actually parse the command line, they
  # are treated as if they were "flags" .
  analyzer-max-svalue-depth=0
  ggc-min-expand=0
  ggc-min-heapsize=0
  iv-max-considered-uses=2
  large-stack-frame=4000
  max-completely-peel-loop-nest-depth=1
  max-completely-peeled-insns=0
  max-completely-peeled-insns=200
  max-cse-insns=0
  max-inline-insns-auto=0
  max-inline-insns-single=0
  parloops-chunk-size=2
  parloops-min-per-thread=5
  sccvn-max-alias-queries-per-access=1
  vect-epilogues-nomask=0
  vect-max-peeling-for-alignment=0

  # This is an argument that should go with -idirafter which is not correctly
  # handled right now. Once that is fixed, this can be removed.
  fdaf
  "/fdaf/"

  -dA
  -dH
  -dirafter
  -dp
  -faggressive-function-elimination
  -fall-intrinsics
  -fallow-argument-mismatch
  -fallow-invalid-boz
  -fautomatic
  -fblas-matmul-limit=1
  -fbounds-check
  -fcheck-array-temporaries
  -fcheck=all
  -fcheck=bits
  -fcheck=bounds
  -fcheck=do
  -fcheck=mem
  -fcheck=pointer
  -fcheck=recursion
  -fcompare-debug
  -fcoarray=lib
  -fcoarray=single
  -fcray-pointer
  -fd-lines-as-code
  -fd-lines-as-comments
  -fdec
  -fdec-format-defaults
  -fdec-static
  -fdec-structure
  -fdollar-ok
  -frecord-marker=4
  -fbounds-check
  -fcheck-bounds
  -fcheck=all
  -fcheck=bits
  # Not sure if the -fdefault-* options will be supported. Maybe in a different
  # form in which case, this will have to be modified to accommodate those.
  -fdefault-real-10
  -fdefault-real-16
  -fdiagnostics-format=json
  -fdiagnostics-show-option
  -fdollar-ok
  -fdump-ipa-cp-details
  -fdump-ipa-fnsummary-details
  -fdump-ipa-inline-details
  -fdump-ipa-sra-details
  -fdump-rtl-combine
  -fdump-rtl-expand
  -fdump-tree-all
  -fdump-tree-cunroll-details
  -fdump-tree-cunrolli-details
  -fdump-tree-dom2
  -fdump-tree-dom2-details
  -fdump-tree-forwprop2
  -fdump-tree-fre1
  -fdump-tree-gimple
  -fdump-tree-ifcvt
  -fdump-tree-ldist-all
  -fdump-tree-ldist-details
  -fdump-tree-lim2
  -fdump-tree-lim2-details
  -fdump-tree-linterchange-details
  -fdump-tree-lversion-details
  -fdump-tree-omplower
  -fdump-tree-optimized
  -fdump-tree-optimized-raw
  -fdump-tree-original
  -fdump-tree-original-lineno
  -fdump-tree-parloops2-details
  -fdump-tree-pcom-details
  -fdump-tree-pre
  -fdump-tree-pre-details
  -fdump-tree-profile_estimate
  -fdump-tree-reassoc1
  -fdump-tree-slp-details
  -fdump-tree-slp2-details
  -fdump-tree-vect-details
  -fexceptions
  -fexpensive-optimizations
  -fexternal-blas
  -ff2c
  -ffixed-xmm1
  -ffixed-xmm10
  -ffixed-xmm11
  -ffixed-xmm12
  -ffixed-xmm13
  -ffixed-xmm14
  -ffixed-xmm15
  -ffixed-xmm2
  -ffixed-xmm3
  -ffixed-xmm4
  -ffixed-xmm5
  -ffixed-xmm6
  -ffixed-xmm7
  -ffixed-xmm8
  -ffixed-xmm9
  -ffloat-store
  -ffree-line-length-none
  -ffrontend-optimize
  -fgcse
  -fgcse-after-reload
  -fgnu-tm
  -findirect-inlining
  -finit-character=32
  -finit-derived
  -finit-local-zero
  -finit-integer=42
  -finit-integer=12345678
  -finit-logical=0
  -finit-logical=true
  -finit-real=inf
  -finline-functions
  -finline-matmul-limit=0
  -finline-matmul-limit=10
  -finline-matmul-limit=100
  -finline-matmul-limit=1000
  -finline-matmul-limit=2
  -finline-matmul-limit=30
  -finline-small-functions
  -finstrument-functions
  -fipa-cp
  -fipa-cp-clone
  -fipa-pta
  -fipa-reference
  -flinker-output=nolto-rel
  -floop-interchange
  -fmax-array-constructor=100000
  -fmax-stack-var-size=8
  -fmax-stack-var-size=100
  -fmodule-private
  -fmodulo-sched
  -fno-align-commons
  -fno-asynchronous-unwind-tables
  -fno-backtrace
  -fno-bounds-check
  -fno-check-array-temporaries
  -fno-code-hoisting
  -fno-dec
  -fno-dse
  -fno-early-inlining
  -fno-f2c
  -fno-frontend-loop-interchange
  -fno-frontend-optimize
  -fno-guess-branch-probability
  -fno-init-local-zero
  -fno-inline
  -fno-inline-arg-packing
  -fno-inline-functions-called-once
  -fno-ipa-cp
  -fno-ipa-icf
  -fno-ipa-modref
  -fno-ipa-sra
  -fno-move-loop-stores
  -fno-openacc
  -fno-openmp
  -fno-pad-source
  -fno-protect-parens
  -fno-range-check
  -fno-realloc-lhs
  -fno-schedule-insns
  -fno-sign-zero
  -fno-strict-aliasing
  -fno-trapping-math
  -fno-tree-ccp
  -fno-tree-ch
  -fno-tree-copy-prop
  -fno-tree-dce
  -fno-tree-dominator-opts
  -fno-tree-forwprop
  -fno-tree-fre
  -fno-tree-loop-ch
  -fno-tree-loop-distribute-patterns
  -fno-tree-loop-im
  -fno-tree-loop-ivcanon
  -fno-tree-loop-optimize
  -fno-tree-loop-vectorize
  -fno-tree-pre
  -fno-tree-scev-cprop
  -fno-tree-sink
  -fno-tree-slp-vectorize
  -fno-tree-vectorize
  -fno-tree-vrp
  -fnon-call-exceptions
  -fopenmp-simd
  -fopt-info-vec-optimized
  -fpad-source
  -fpeel-loops
  -fpre-include=simd-builtins-1.h
  -fpre-include=simd-builtins-3.h
  -fpre-include=simd-builtins-4.h
  -fpre-include=simd-builtins-7.h
  -fpre-include=simd-builtins-8.h
  -fpreprocessed
  -fpredictive-commoning
  -fprefetch-loop-arrays
  -fprofile-arcs
  -fprofile-generate
  -frecord-marker=4
  -frecursive
  -frepack-arrays
  -frounding-math
  -fsanitize=float-cast-overflow
  -fsanitize=null
  -fsanitize=signed-integer-overflow
  -fsanitize=undefined
  -fschedule-insns
  -fsecond-underscore
  -fsel-sched-pipelining
  -fsel-sched-pipelining-outer-loops
  -fselective-scheduling
  -fselective-scheduling2
  -fset-g77-defaults
  -fshort-enums
  -fstrict-aliasing
  -fsplit-loops
  -ftest-forall-temp
  -ftest-coverage
  -ftracer
  -ftrapv
  -ftree-loop-distribution
  -ftree-loop-if-convert
  -ftree-loop-vectorize
  -ftree-parallelize-loops
  -ftree-parallelize-loops=2
  -ftree-pre
  -ftree-slp-vectorize
  -ftree-tail-merge
  -ftree-vectorize
  -ftree-vrp
  -funconstrained-commons
  -funroll-all-loops
  -funroll-loops
  -funsafe-math-optimizations
  -fvect-cost-model=dynamic
  -fwhole-program
  -fwrapv
  -gno-strict-dwarf
  -idirafter
  -mavx
  -mavx2
  -mavx512f
  -mcmodel=medium
  -mdalign
  -mdejagnu-cpu=power4
  -mdejagnu-cpu=power7
  -mdejagnu-cpu=power10
  -mfpmath=387
  -mfpmath=sse
  -mlow-precision-sqrt
  -mno-avx
  -mno-power8-vector
  -mno-power9-vector
  -mprefer-avx128
  -msse
  -msse2
  -msse3
  -msse4.1
  -mtune=amdfam10
  -mtune=generic
  -mveclibabi=mass
  -mveclibabi=svml
  -mvsx
  -mvzeroupper
  -mzarch
  -nostdinc
  -nostdlib
  # -Os might eventually be supported, so this might also need to be removed
  # at some point
  -Og
  -Os
  -pedantic-errors
  # -pthread should be supported at some point.
  -pthread
  -r
  # At some point, if we ever support explicit standard flags, some of these
  # should be removed.
  -pedantic-errors
  -std=gnu
  -std=legacy
  -std=f95
  --std=f95
  -std=f2003
  -std=f2008
  -std=f2008ts
  # At the time of writing, -W warnings are not supported. flang errors out
  # saying that only -Werror is supported.
  -W
  -Waliasing
  -Wall
  -Wampersand
  -Wanalyzer-too-complex
  -Warray-bounds
  -Warray-temporaries
  -Wc-binding-type
  -Wcharacter-truncation
  -Wcompare-reals
  -Wconversion
  -Wconversion-extra
  -Wdate-time
  -Wdo-subscript
  -Werror
  -Wextra
  -Wfunction-elimination
  -Wimplicit-interface
  -Wimplicit-procedure
  -Winteger-division
  -Wintrinsic-shadow
  -Wintrinsics-std
  -Wline-truncation
  -Wmaybe-uninitialized
  -Wmissing-include-dirs
  -Wno-all
  -Wno-analyzer-malloc-leak
  -Wno-analyzer-memory-leak
  -Wno-analyzer-null-dereference
  -Wno-analyzer-possible-null-dereference
  -Wno-analyzer-too-complex
  -Wno-analyzer-use-of-uninitialized-value
  -Wno-c-binding-type
  -Wno-complain-wrong-lang
  -Wno-cpp
  -Wno-error
  -Wno-error=cpp
  -Wno-intrinsic-shadow
  -Wno-intrinsics-std
  -Wno-line-truncation
  -Wno-lto-type-mismatch
  -Wno-missing-include-dirs
  -Wno-overwrite-recursive
  -Wno-pedantic
  -Wno-tabs
  -Wno-underflow
  -Wno-uninitialized
  -Wno-unused-dummy-argument
  -Wno-zerotrip
  -Wopenacc-parallelism
  -Wpadded
  -Wrealloc-lhs
  -Wrealloc-lhs-all
  -Wreturn-type
  -Wstringop-overflow
  -Wsurprising
  -Wtabs
  -Wtarget-lifetime
  -Wundefined-do-loop
  -Wuninitialized
  -Wunused
  -Wunused-dummy-argument
  -Wunused-function
  -Wunused-label
  -Wunused-parameter
  -Wunused-variable
  -Wzerotrip
  -w
  --param
)

# Determine disabled tests for this directory and return them via the OUT
# parameter.
function(gfortran_populate_disabled_tests out)
  set(unsupported "")
  set(unimplemented "")
  set(skipped "")
  set(failing "")

  # This will provide the lists of unsupported, unimplemented, skipped and
  # failing files.
  include(${CMAKE_CURRENT_SOURCE_DIR}/DisabledFiles.cmake)

  list(APPEND unsupported ${UNSUPPORTED_FILES})
  list(APPEND unimplemented ${UNIMPLEMENTED_FILES})
  list(APPEND skipped ${SKIPPED_FILES})
  list(APPEND failing ${FAILING_FILES})

  # do the same for any requested feature extentions
  foreach(feature ${TEST_SUITE_FORTRAN_FEATURES})
    set(UNSUPPORTED_FILES "")
    set(UNIMPLEMENTED_FILES "")
    set(SKIPPED_FILES "")
    set(FAILING_FILES "")
    include(${CMAKE_CURRENT_SOURCE_DIR}/DisabledFiles${feature}.cmake)
    list(APPEND unsupported ${UNSUPPORTED_FILES})
    list(APPEND unimplemented ${UNIMPLEMENTED_FILES})
    list(APPEND skipped ${SKIPPED_FILES})
    list(APPEND failing ${FAILING_FILES})

    # enable any tests that now pass for this feature
    set(SUPPORTED_FILES "")
    set(IMPLEMENTED_FILES "")
    set(UNSKIPPED_FILES "")
    set(PASSING_FILES "")
    include(${CMAKE_CURRENT_SOURCE_DIR}/EnabledFiles${feature}.cmake)
    list(REMOVE_ITEM unsupported ${SUPPORTED_FILES})
    list(REMOVE_ITEM unimplemented ${IMPLEMENTED_FILES})
    list(REMOVE_ITEM skipped ${UNSKIPPED_FILES})
    list(REMOVE_ITEM failing ${PASSING_FILES})
  endforeach()

  set(disabled "")

  # There is still a chance that some of the unsupported tests may need to be
  # enabled, for instance if the non-standard extensions that they exercise are
  # supported due to user demand.
  if (NOT TEST_SUITE_FORTRAN_FORCE_ALL_TESTS AND
      NOT TEST_SUITE_FORTRAN_FORCE_UNSUPPORTED_TESTS)
    list(APPEND disabled ${unsupported})
  endif()

  # For the remaining tests, there is cause to build and run the skipped, failing
  # and unimplemented tests since some could be enabled once some feature is
  # implemented. Eventually, all the TEST_SUITE_FORTRAN_FORCE_* options (perhaps
  # with the exception of TEST_SUITE_FORTRAN_FORCE_UNSUPPORTED_TESTS) should
  # become redundant and removed.
  if (NOT TEST_SUITE_FORTRAN_FORCE_ALL_TESTS AND
      NOT TEST_SUITE_FORTRAN_FORCE_UNIMPLEMENTED_TESTS)
    list(APPEND disabled ${unimplemented})
  endif()

  if (NOT TEST_SUITE_FORTRAN_FORCE_ALL_TESTS AND
      NOT TEST_SUITE_FORTRAN_FORCE_SKIPPED_TESTS)
    list(APPEND disabled ${skipped})
  endif()

  if (NOT TEST_SUITE_FORTRAN_FORCE_ALL_TESTS AND
      NOT TEST_SUITE_FORTRAN_FORCE_FAILING_TESTS)
    list(APPEND disabled ${failing})
  endif()

  set(${out} ${disabled} PARENT_SCOPE)
endfunction()

# Check the test configuration to make sure that it is not out of date.
# USED_FORT is the list of Fortran files that are used in the tests. USED_OTHER
# is the list of non-Fortran files that are used. This is intended be a sanity
# check in case the test suite is updated without updating the static test
# configuration. In particular, we want to catch situations where failing to
# update the test configuration results in the new new tests being skipped
# silently.
function(gfortran_check_test_config used_fort used_other)
  list(SORT used_fort)
  list(REMOVE_DUPLICATES used_fort)

  list(SORT used_other)
  list(REMOVE_DUPLICATES used_other)

  # All the Fortran files in the current directory.
  file(GLOB files CONFIGURE_DEPENDS LIST_DIRECTORIES false
    *.f*
    *.F*
  )
  list(SORT files)

  set(msg_unused "File not used in any test configuration")
  set(msg_missing "File used in test configuration not found")
  set(msg_rerun "You may need to run utils/update-test-config.py")

  # Now that files and used_fort are both sorted and without any duplicates,
  # they should be identical. If they are not, it suggests that some Fortran
  # files have been added or removed.
  foreach (f u IN ZIP_LISTS files used_fort)
    if (NOT f STREQUAL u)
      list(FIND used ${f} idx)
      if (idx EQUAL -1)
        message(FATAL_ERROR "${msg_unused}\n  ${f}\n${msg_rerun}\n")
      else ()
        message(FATAL_ERROR "${msg_missing}\n  ${u}\n${msg_rerun}\n")
      endif ()
    endif ()
  endforeach ()

  # It is highly likely that any non-Fortran files will be dependents of tests.
  # They are most likely to be .c files, but we cannot guarantee that. Just
  # check if the files in the test configuration exist. If any dependent files
  # are added and they are missing from the test configuration, it will most
  # likely result in a build-time error, so it won't pass by silently.
  foreach (f ${used_other})
    if (NOT EXISTS ${f})
      message(FATAL_ERROR "${msg_missing}\n  ${f}\n${msg_rerun}\n")
    endif ()
  endforeach()
endfunction()

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
  string(REPLACE " " ";" fflags "${fflags};${CMAKE_Fortran_FLAGS}")

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
    llvm_test_verify(%b/not ${DIFFPROG} %S/${relpath}/${EMPTY_FILE} %S/${out})
  else ()
    llvm_test_verify(${DIFFPROG} %S/${relpath}/${EMPTY_FILE} %S/${out})
  endif ()

  llvm_add_test(${target}.test %S/${relpath}/${DUMMY_EXE})
endfunction()

# Setup an "execute" test. In the case of multi-file tests, MAIN will be the
# main file. For multi-file tests, OTHERS will be the remaining files needed by
# the test. FFLAGS are additional compiler flags needed by the test. LDFLAGS
# are the other linker flags needed by the test. If EXPECT_ERROR evaluates to
# true, the test is expected to fail.
function(gfortran_add_execute_test expect_error main others fflags ldflags)
  # PREFIX_EXECUTE will have been defined in the subdirectory from which this
  # function is called.
  gfortran_unique_target_name("${PREFIX_EXECUTE}" "${main}" target)
  gfortran_make_working_dir("${target}" working_dir)
  get_filename_component(working_dir_name "${working_dir}" NAME)

  llvm_test_executable_no_test(${target} ${main} ${others})
  if (expect_error)
    llvm_test_run(
      EXECUTABLE "%b/not --crash %S/${target}"
      WORKDIR "%S/${working_dir_name}")
  else ()
    llvm_test_run(WORKDIR "%S/${working_dir_name}")
  endif ()
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

# The main entry point to populate the tests in the current source directory.
# This parses the static test configuration file, filters out the disabled
# tests, sets up the tests and performs some sanity checks. The keyword FFLAGS
# and LDFLAGS arguments can be used to force specific compile-time and link-time
# flags to be used when building the tests.
function(gfortran_populate_tests)
  cmake_parse_arguments(GFORTRAN "" "" "FFLAGS;LDFLAGS" ${ARGN})

  # These are used to collect the list of source files that are used in at
  # least one test. This is used as a sanity check to ensure that all the
  # source files are accounted for. This is necessary to alert the user in case
  # the tests were updated by upstream gfortran but the static test
  # configuration was not re-generated.
  set(used_fort)
  set(used_other)

  string(REPLACE "${CMAKE_SOURCE_DIR}/" "" pwd "${CMAKE_CURRENT_SOURCE_DIR}")
  message(STATUS "Adding directory ${pwd}")

  # The target triple is roughly of the form ${arch}-${vendor}-${sys}. Cmake
  # has no concept of a vendor, so we set it to "unknown". The targets
  # specification in the tests generally ignores the vendor and only matches
  # against either the architecture or the system, so this is ok.
  string(TOLOWER "${CMAKE_SYSTEM_PROCESSOR}" arch)
  string(TOLOWER "${CMAKE_SYSTEM_NAME}" sys)
  set(triple "${arch}-unknown-${sys}")

  set(disabled)
  gfortran_populate_disabled_tests(disabled)

  file(STRINGS ${CMAKE_CURRENT_SOURCE_DIR}/tests.cmake lines)
  foreach (line ${lines})
    # Skip comment lines where the first non-whitespace character is a #.
    if (line MATCHES "^[ ]*#")
      continue()
    endif()

    list(GET line 1 sources_t)
    string(REPLACE " " ";" sources "${sources_t}")
    list(TRANSFORM sources PREPEND ${CMAKE_CURRENT_SOURCE_DIR}/)

    # The tests in the configuration must be added to the used list even if the
    # test is disabled because the sanity check will expect that the list of
    # Fortran files in the directory exactly matches the list of used Fortran
    # files.
    set(rest)
    list(LENGTH sources nsources)
    math(EXPR iend "${nsources} - 1")
    foreach (i RANGE ${iend})
      list(GET sources ${i} source)
      if (source MATCHES "^.+[.][Ff].*$")
        list(APPEND used_fort ${source})
      else ()
        list(APPEND used_other ${source})
      endif ()
      if (${i} GREATER 0)
        list(APPEND rest ${source})
      endif ()
    endforeach()

    # If the test is only allowed to run on certain targets, process those.
    list(GET line 4 incl_t)
    if (incl_t)
      # If there are any explicit include targets, then we should assume that
      # we cannot run the test on the current platform unless there is at
      # least one match.
      set(exclude ON)
      string(REPLACE " " ";" includes ${incl_t})
      foreach (incl ${includes})
        string(REGEX MATCH ${incl} m ${triple})
        if (m)
          set(exclude OFF)
        endif ()
      endforeach()

      # The current platform was not matched, so we should not run the test.
      if (exclude)
        continue()
      endif ()
    endif ()

    # If the test is explicitly disabled on certain targets, process those.
    list(GET line 5 excl_t)
    if (excl_t)
      # If there are any targets to explicitly exclude, then we should assume
      # that we can run the test on this platform unless there is at least
      # one match.
      set(exclude OFF)
      string(REPLACE " " ";" excludes ${excl_t})
      foreach (excl ${excludes})
        string(REGEX MATCH ${excl} m ${triple})
        if (m)
          set(exclude ON)
        endif ()
      endforeach ()

      # The current platform was matched, so we should not run the test.
      if (exclude)
        continue ()
      endif()
    endif ()

    # Only the main file will be in the list of disabled tests. If it is, move
    # on to the next test in the configuration.
    list(GET sources 0 main)
    list(FIND disabled ${main} i)
    if (NOT i EQUAL -1)
      continue ()
    endif()

    # The test was not excluded and not disabled. Now we can process the other
    # parameters and set up the test.
    set(xfail OFF)
    list(GET line 2 xfail_t)
    if (xfail_t STREQUAL "xfail")
      set(xfail ON)
    endif ()

    set(fflags)
    list(GET line 3 options_t)
    string(REPLACE " " ";" file_fflags "${options_t}")
    list(REMOVE_ITEM file_fflags ${FLANG_ERRORING_FFLAGS})
    list(APPEND fflags ${GFORTRAN_FFLAGS})
    list(APPEND fflags ${file_fflags})

    set(ldflags)
    list(APPEND ldflags ${GFORTRAN_LDFLAGS})

    list(GET line 0 kind)
    if (kind STREQUAL "run")
      gfortran_add_execute_test(${xfail} ${main} "${rest}" "${fflags}" "${ldflags}")
    else()
      # FIXME: For now, we treat all non-execute tests as compile tests, but we
      # probably should do something more sensible for the "preprocess",
      # "assemble", and "link" tests.
      gfortran_add_compile_test(${xfail} ${main} "${rest}" "${fflags}" "${ldflags}")
    endif()
  endforeach()

  # It would be nice to do the sanity check early, but that would complicate
  # this code since cmake is not the nicest programming language.
  gfortran_check_test_config("${used_fort}" "${used_other}")
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
  find_program(DIFFPROG
    NAMES fc.exe
    REQUIRED)
else ()
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
