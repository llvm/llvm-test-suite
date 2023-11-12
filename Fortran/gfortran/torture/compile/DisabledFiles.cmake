#===------------------------------------------------------------------------===#
#
# Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
# See https://llvm.org/LICENSE.txt for license information.
# SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
#
#===------------------------------------------------------------------------===#

# There are currently no unsupported files.
set(UNSUPPORTED_FILES "")

# There are currently no unimplemented files.
set(UNIMPLEMENTED_FILES "")

# There are currently no skipped files.
set(SKIPPED_FILES "")

# These tests are disabled because they fail, when they should pass.
file(GLOB FAILING_FILES CONFIGURE_DEPENDS
  # For this, gfortran issues a warning while flang fails to compile. This is
  # potentially an "unsupported" test if the reason for this difference in
  # is because the standard allows for implementation-dependent behavior.
  pr37236.f
)
