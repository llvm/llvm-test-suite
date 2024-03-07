#===------------------------------------------------------------------------===#
#
# Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
# See https://llvm.org/LICENSE.txt for license information.
# SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
#
#===------------------------------------------------------------------------===#

# There are currently no unsupported files.
set(UNSUPPORTED_FILES "")

file(GLOB UNIMPLEMENTED_FILES CONFIGURE_DEPENDS
  # unimplemented: Unhandled block directive
  a.11.1.f90
  a.11.2.f90
  a.11.3.f90
  a.11.4.f90
  a.11.5.f90
  a.11.6.f90
  a.11.7.f90
)

file(GLOB SKIPPED_FILES CONFIGURE_DEPENDS
  #
  # These tests fail when they should pass.
  #

  # error: COMMON block must be declared in the same scoping unit in which the
  # OpenMP directive or clause appears
  a.23.2.f90

  # error: COPYPRIVATE variable is not PRIVATE or THREADPRIVATE in outer
  # context
  a.33.1.f90
  a.33.2.f90
  a.33.4.f90

  #
  # These tests pass when they should fail.
  #
  a.23.4.f90
  a.31.3.f90
)

# There are currently no failing files.
set(FAILING_FILES "")
