#===------------------------------------------------------------------------===#
#
# Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
# See https://llvm.org/LICENSE.txt for license information.
# SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
#
#===------------------------------------------------------------------------===#

# There are currently no unsupported files.
set(UNSUPPORTED_FILES "")

# These tests are disabled because they trigger a "not yet implemented"
# assertion.
file(GLOB UNIMPLEMENTED_FILES CONFIGURE_DEPENDS
  # unimplemented: OpenMPRequiresConstruct
  atomic.f90
)

# There are currently no skipped files.
set(SKIPPED_FILES "")

# These tests fail when they are expected to pass.
file(GLOB FAILING_FILES CONFIGURE_DEPENDS
  # These tests fail to compile when compilation is expected to succeed. This
  # is likely because some directives/syntactic constructs are not yet
  # implemented, but there is no assertion to trigger these as "not yet
  # implemented".
  fixed-1.f
  free-1.f90
  pr102330-1.f90
)
