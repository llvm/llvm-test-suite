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
# assertions.
file(GLOB UNIMPLEMENTED_FILES CONFIGURE_DEPENDS
  # unimplemented: allocatable components in derived type assignment
  pr93777.f90
)

# There are currently no skipped files.
set(SKIPPED_FILES "")

# There tests fail when they are expected to pass.
file(GLOB FAILING_FILES CONFIGURE_DEPENDS
  # These files fail to compile when compilation is expected to succeed.
  malloc.f90
  malloc-example.f90)
