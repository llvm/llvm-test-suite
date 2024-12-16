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

# These tests are disabled because they cause internal compiler errors.
file(GLOB SKIPPED_FILES CONFIGURE_DEPENDS
  # error: unexpected typeless constant value
  forall_5.f90
  forall_6.f90
  st_function.f90

  # --------------------------------------------------------------------------
  #
  # These tests are skipped because they trigger semantic errors. It may be
  # because they use non-standard features that are currently not supported, or
  # it could be unimplemented features that are not tagged as such.
  #

  # error: Result of ENTRY is not compatible with result of containing function
  entry_2.f90

  # error: '[SYM]' is not a known intrinsic procedure
  specifics.f90
)

# These tests are disabled because they fail at runtime when they should pass.
file(GLOB FAILING_FILES CONFIGURE_DEPENDS
  data_3.f90

  # This file creates a string of length 10 and populates it with the name of
  # the executable obtained from getarg(). The way the test suite is built,
  # the executable name of the test is larger than 10 characters causing the
  # test to fail when optimizations are enabled. This test could be re-enabled
  # if the build system is tweaked to special case this and generate an
  # executable whose name is 10 characters or less.
  #
  # This passes on some platforms and not others, but definitely should not be
  # enabled unless it is actually fixed.
  getarg_1.f90

  intrinsic_sr_kind.f90
  nan_inf_fmt.f90
  random_2.f90
)
