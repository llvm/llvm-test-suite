#===------------------------------------------------------------------------===#
#
# Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
# See https://llvm.org/LICENSE.txt for license information.
# SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
#
#===------------------------------------------------------------------------===#

# There are currently no unsupported files.
set(UNSUPPORTED_FILES "")

# These tests are disabled because they trigger "not yet implemented"
# assertions in flang.
file(GLOB UNIMPLEMENTED_FILES CONFIGURE_DEPENDS
  # not yet implemented: assumed-rank variable in procedure
  missing_optional_dummy_8.f90
)

# There are currently no skipped files.
set(SKIPPED_FILES "")

# There are currently no failing files.
set(FAILING_FILES "")
