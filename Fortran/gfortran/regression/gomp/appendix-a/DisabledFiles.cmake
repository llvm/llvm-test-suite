#===------------------------------------------------------------------------===#
#
# Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
# See https://llvm.org/LICENSE.txt for license information.
# SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
#
#===------------------------------------------------------------------------===#

# There are currently no unsupported files.
set(UNSUPPORTED_FILES "")

# There are currently no files with unimplemented festures
set(UNIMPLEMENTED_FILES "")

file(GLOB SKIPPED_FILES CONFIGURE_DEPENDS
  #
  # These tests pass when they should fail.
  #
  a.6.2.f90
  a.23.4.f90
  a.31.3.f90
)

# There are currently no failing files.
set(FAILING_FILES "")
