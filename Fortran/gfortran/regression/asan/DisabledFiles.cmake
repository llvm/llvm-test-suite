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

# These tests trigger internal compiler errors.
file(GLOB SKIPPED_FILES CONFIGURE_DEPENDS
  # error: unexpected typeless constant value
  pointer_assign_16.f90
)

# There are currently no failing files.
set(FAILING_FILES "")
