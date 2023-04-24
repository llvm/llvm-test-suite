#===------------------------------------------------------------------------===#
#
# Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
# See https://llvm.org/LICENSE.txt for license information.
# SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
#
#===------------------------------------------------------------------------===#

# These tests fail at runtime.
file(GLOB Failing CONFIGURE_DEPENDS
  pr60510.f
)

list(APPEND UnsupportedTests "")
list(APPEND UnimplementedTests "")
list(APPEND SkippedTests "")
list(APPEND FailingTests "${Failing}")

add_tests("${UnsupportedTests}" "${UnimplementedTests}" "${SkippedTests}" "${FailingTests}")
