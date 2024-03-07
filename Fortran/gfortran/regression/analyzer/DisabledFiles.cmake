#===------------------------------------------------------------------------===#
#
# Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
# See https://llvm.org/LICENSE.txt for license information.
# SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
#
#===------------------------------------------------------------------------===#

set(UNSUPPORTED_FILES "")
set(UNIMPLEMENTED_FILES "")
set(SKIPPED_FILES "")

# There tests fail when they are expected to pass.
file(GLOB FAILING_FILES CONFIGURE_DEPENDS
  # These files fail to compile when compilation is expected to succeed.
  malloc-example.f90)
