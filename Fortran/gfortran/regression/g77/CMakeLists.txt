#===------------------------------------------------------------------------===#
#
# Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
# See https://llvm.org/LICENSE.txt for license information.
# SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
#
#===------------------------------------------------------------------------===#

# These tests use (currently) unsupported GNU extensions.
file(GLOB Unsupported CONFIGURE_DEPENDS
  intrinsic-unix-bessel.f  # bes(j|y)(0|1|n),
  intrinsic-unix-erf.f     # derf
)

# These tests are skipped because they cause flang to crash
file(GLOB Skipped CONFIGURE_DEPENDS
  # error: 64-bit code requested on a subtarget that doesn't support it!
  20010216-1.f
)

# These tests fail at runtime.
file(GLOB Failing CONFIGURE_DEPENDS
  complex_1.f
)

list(APPEND UnsupportedTests "${Unsupported}")
list(APPEND UnimplementedTests "")
list(APPEND SkippedTests "${Skipped}")
list(APPEND FailingTests "${Failing}")

add_tests("${UnsupportedTests}" "${UnimplementedTests}" "${SkippedTests}" "${FailingTests}")
