#===------------------------------------------------------------------------===#
#
# Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
# See https://llvm.org/LICENSE.txt for license information.
# SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
#
#===------------------------------------------------------------------------===#

set(UNSUPPORTED_FILES "")
set(UNIMPLEMENTED_FILES "")

file(GLOB SKIPPED_FILES CONFIGURE_DEPENDS
  # --------------------------------------------------------------------------
  #
  # These tests are skipped because flang cannot parse these files.
  generic_assumed_rank_1.f90
  generic_assumed_rank_3.f90
)

set(FAILING_FILES "")
