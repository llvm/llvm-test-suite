#===------------------------------------------------------------------------===#
#
# Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
# See https://llvm.org/LICENSE.txt for license information.
# SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
#
#===------------------------------------------------------------------------===#

# These tests use (currently) unsupported GNU extensions.
file(GLOB UNSUPPORTED_FILES CONFIGURE_DEPENDS
  intrinsic-unix-bessel.f  # bes(j|y)(0|1|n),
  intrinsic-unix-erf.f     # derf
)

# There are currently no unimplemented files.
set(UNIMPLEMENTED_FILES "")

# These tests are skipped because they cause flang to crash
file(GLOB SKIPPED_FILES CONFIGURE_DEPENDS
  # error: 64-bit code requested on a subtarget that doesn't support it!
  20010216-1.f

  # These tests fail because gfortran expects the compilation to succeed but
  # with a warning being issued. flang, however, fails to compile and issues an
  # error instead.
  12632.f
)

# These tests fail when they are expected to pass.
file(GLOB FAILING_FILES CONFIGURE_DEPENDS
  # These tests are expected to fail to compile, but compilation succeeds.
  19990218-0.f
  970625-2.f
  980615-0.f
)
