#===------------------------------------------------------------------------===#
#
# Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
# See https://llvm.org/LICENSE.txt for license information.
# SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
#
#===------------------------------------------------------------------------===#

# These tests trigger internal compiler errors.
file(GLOB Skipped CONFIGURE_DEPENDS
  # error: unexpected typeless constant value
  pointer_assign_16.f90
)

list(APPEND UnsupportedTests "")
list(APPEND UnimplementedTests "")
list(APPEND SkippedTests "${Skipped}")
list(APPEND FailingTests "")

add_tests("${UnsupportedTests}" "${UnimplementedTests}" "${SkippedTests}" "${FailingTests}")
