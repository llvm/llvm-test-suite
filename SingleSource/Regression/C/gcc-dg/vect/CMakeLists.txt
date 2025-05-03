include(${CMAKE_CURRENT_SOURCE_DIR}/../../../DgOptions.txt)
include(${CMAKE_CURRENT_SOURCE_DIR}/DgVectTestList.txt)

set(TestsToSkip)

##
## Main Test Blacklist for Clang
##

# Tests with features unsupported by Clang (usually GCC extensions)
# (Big list of naughty tests)
set(UnsupportedTests
  # Unsupported flags
  pr48765.c
  pr63530.c
  
  # `#pragma GCC unroll 0` is invalid in Clang
  pr97832-4.c
  pr97832-2.c
  pr97832-3.c
  vect-93.c
  pr79920.c
  vect-double-reduc-6.c
  fast-math-vect-pr29925.c
  no-vfa-vect-101.c
  no-vfa-vect-102.c
  vect-105.c

  # requires -mpowerpc64
  vect-82_64.c
  vect-83_64.c

  # unknown argument: '-finline-stringops'
  pr113002.c

  # Requires cosf
  tsvc/vect-tsvc-s451.c

  # Variable array in sturcture
  pr111882.c

  # "ssa" attributes are invalid in Clang
  slp-reduc-10a.c
  slp-reduc-10b.c
  slp-reduc-10c.c
  slp-reduc-10d.c
  slp-reduc-10e.c
  bb-slp-48.c
  vect-cond-arith-2.c
  vect-ifcvt-19.c

  # Unknown flag '-fno-delete-dead-exceptions'
  pr103253.c

  # We don't have `long long` vect
  pr101145_3.c

  # Needs libm
  fast-math-bb-slp-call-1.c
  fast-math-bb-slp-call-2.c
  fast-math-bb-slp-call-3.c
  fast-math-vect-call-1.c
  fast-math-vect-call-2.c

  # error: address of vector element requested
  bb-slp-pr54400.c

  # The rest
  fast-math-vect-pr29925.c
  # no-vfa-vect-101.c
  no-vfa-vect-102.c
  pr51581-1.c
  pr51581-2.c
  pr59651.c
  pr63530.c
  pr79920.c
  vect-105.c
  vect-93.c
  vect-cond-arith-3.c
  vect-cond-arith-7.c
  vect-double-reduc-6.c
  vect-fma-1.c
  vect-reduc-mul_1.c
  vect-reduc-mul_2.c
  vect-reduc-or_1.c
  vect-reduc-or_2.c
  vect-simd-16.c
  vect-simd-clone-16.c
  vect-simd-clone-16b.c
  vect-simd-clone-16c.c
  vect-simd-clone-16d.c
  vect-simd-clone-16e.c
  vect-simd-clone-16f.c
  vect-simd-clone-17.c
  vect-simd-clone-17b.c
  vect-simd-clone-17c.c
  vect-simd-clone-17d.c
  vect-simd-clone-17e.c
  vect-simd-clone-17f.c
  vect-simd-clone-18.c
  vect-simd-clone-18b.c
  vect-simd-clone-18c.c
  vect-simd-clone-18d.c
  vect-simd-clone-18e.c
  vect-simd-clone-18f.c
  vect-simd-clone-20.c
)
list(APPEND TestsToSkip ${UnsupportedTests})

set(TestFiles ${VECT_EXP_TESTS})

foreach(TestToSkip ${TestsToSkip})
  list(REMOVE_ITEM TestFiles ${TestToSkip})
endforeach()

foreach(File ${TestFiles})
  set(MaybeCFlags)
  set(MaybeLDFlags)

  # Add Test-specific CFLAGS/LDFLAGS here

  if(${File} IN_LIST TestRequiresLibM)
    list(APPEND MaybeLDFlags "-lm")
  endif()

  if(${File} IN_LIST TestRequiresWNoReturnType)
    list(APPEND MaybeCFlags "-Wno-return-type")
  endif()

  if(${File} IN_LIST TestRequiresFWrapV)
    list(APPEND MaybeCFlags "-fwrapv")
  endif()

  gcc_torture_execute_test(${File}
                           DG_DO_DEFAULT "run"
                           PREFIX "GCC-DG-VECT"
                           CFLAGS ${MaybeCFlags}
                           LDFLAGS ${MaybeLDFlags})
endforeach()
