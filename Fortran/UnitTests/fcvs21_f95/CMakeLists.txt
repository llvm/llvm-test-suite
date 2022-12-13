# NIST Fortran 77 Test Suite
# http://www.fortran-2000.com/ArnaudRecipes/fcvs21_f95.html
#
# Reference results generated with gfortran -v:
# Using built-in specs.
# COLLECT_GCC=gfortran
# COLLECT_LTO_WRAPPER=/usr/lib/gcc/x86_64-linux-gnu/7/lto-wrapper
# OFFLOAD_TARGET_NAMES=nvptx-none
# OFFLOAD_TARGET_DEFAULT=1
# Target: x86_64-linux-gnu
# Configured with: ../src/configure -v --with-pkgversion='Ubuntu 7.5.0-3ubuntu1~18.04' --with-bugurl=file:///usr/share/doc/gcc-7/README.Bugs --enable-languages=c,ada,c++,go,brig,d,fortran,objc,obj-c++ --prefix=/usr --with-gcc-major-version-only --program-suffix=-7 --program-prefix=x86_64-linux-gnu- --enable-shared --enable-linker-build-id --libexecdir=/usr/lib --without-included-gettext --enable-threads=posix --libdir=/usr/lib --enable-nls --enable-bootstrap --enable-clocale=gnu --enable-libstdcxx-debug --enable-libstdcxx-time=yes --with-default-libstdcxx-abi=new --enable-gnu-unique-object --disable-vtable-verify --enable-libmpx --enable-plugin --enable-default-pie --with-system-zlib --with-target-system-zlib --enable-objc-gc=auto --enable-multiarch --disable-werror --with-arch-32=i686 --with-abi=m64 --with-multilib-list=m32,m64,mx32 --enable-multilib --with-tune=generic --enable-offload-targets=nvptx-none --without-cuda-driver --enable-checking=release --build=x86_64-linux-gnu --host=x86_64-linux-gnu --target=x86_64-linux-gnu
# Thread model: posix
# gcc version 7.5.0 (Ubuntu 7.5.0-3ubuntu1~18.04)
#
# Reference results for tests 905 and 907 generated with flang ~15.0.0 on
# Ubuntu 20.04 (aarch64-unknown-linux-gnu).
#
# See additional comments in `driver_run` script should reference
# results ever need to be updated.
#
# Following test have been intentionally ommitted due to feature
# deletion in Fortran 95 standard:
# F95: 103, 111, 252, 253, 255, 257, 259, 260, 719
#
# We omit these tests because they never pass with any recent
# compiler:
# 001, 406, 923
# 
# Tests make use of arithmetic IF which is now a deleted feature
# in Fortran 2008
# 
# Note that the NIST license allows redistribution but requires
# explicit acknowledgement of what has been changed. Please
# amend README file if you modify the tests.

# clean-up fort.* files otherwise one of the tests will fail
llvm_test_prepare(rm -f %S/fort.*)

# Different compilers or different compiler options may produce slightly
# different but still valid outputs for some of these tests. By default, we will
# check that the outputs match the reference outputs exactly. However, when this
# option is set, we will check less strictly.
option(FCVS_ALLOW_FLEXIBLE_OUTPUT "Don't match the output of FCVS tests exactly")

# Group 1:
# Tests 905 and 907 use list-directed output, for which the standard allows some
# flexibility, e.g., with regards to how many white space characters or
# floating point decimals to print. Treat them separately.
set(SPECIAL_CASES "FM905.f" "FM907.f")
set(Source ${SPECIAL_CASES})
if (FCVS_ALLOW_FLEXIBLE_OUTPUT)
  set(FP_IGNOREWHITESPACE ON)

  # FM905 needs a higher relative tolerance than the rest. The reference output
  # contains 2.5E-11, but gfortran (reasonably) prints 2.50000003E-11. Both
  # should be accepted.
  set(FP_TOLERANCE 1.0e-7)
endif()
llvm_singlesource()
set(Source)

# Group 2:
# Generic case. Make sure to exclude the special cases which have already been
# added as part of Group 1.
file(GLOB Source CONFIGURE_DEPENDS *.f)
foreach (SPECIAL_CASE ${SPECIAL_CASES})
  list(FILTER Source EXCLUDE REGEX ${SPECIAL_CASE})
endforeach()

# Test 509 requires this flag in more recent versions of GCC.
# If this flag is not supported, the test should be excluded.
check_fortran_compiler_flag("-std=legacy" SUPPORTS_LEGACY)
if (SUPPORTS_LEGACY)
  add_compile_options(-std=legacy)
else()
  # Regex because the GLOB returns the full path to each file
  list(FILTER Source EXCLUDE REGEX "FM509\.f$")
endif()

# Skip some tests that currently fail with flang on AArch64 when using libpgmath.
# FIXME: Reenable these tests after libpgmath is fixed or after we no longer
# depend on it.
if (CMAKE_Fortran_COMPILER_ID STREQUAL "LLVMFlang" AND ARCH STREQUAL "AArch64")
  # Regex because the GLOB returns the full path to each file
  list(FILTER Source EXCLUDE REGEX "FM813\.f$")
  list(FILTER Source EXCLUDE REGEX "FM815\.f$")
  list(FILTER Source EXCLUDE REGEX "FM817\.f$")
  list(FILTER Source EXCLUDE REGEX "FM820\.f$")
  list(FILTER Source EXCLUDE REGEX "FM828\.f$")
  list(FILTER Source EXCLUDE REGEX "FM831\.f$")
  list(FILTER Source EXCLUDE REGEX "FM833\.f$")
endif()

set(FP_TOLERANCE 1.0e-11) # set by the most sensitive numerical test
set(FP_IGNOREWHITESPACE OFF)
llvm_singlesource()

file(COPY lit.local.cfg DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")
