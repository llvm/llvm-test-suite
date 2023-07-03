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
  # error: not a constant derived type expression
  der_init_2.f90
  der_init_3.f90
  der_init_4.f90
  der_init_5.f90
  der_type.f90

  # error: unexpected typeless constant value
  data.f90
  data_2.f90
  dep_fails.f90
  der_init.f90
  der_io.f90
  der_point.f90
  entry_8.f90
  equiv_3.f90
  forall_3.f90
  forall_5.f90
  forall_6.f90
  intrinsic_associated.f90
  intrinsic_len.f90
  iolength_2.f90
  pr32604.f90
  st_function.f90
  where_7.f90
  where_8.f90

  # error: failed to legalize operation 'math.ctlz' that was explicitly marked
  # illegal
  intrinsic_leadz.f90

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
  elemental.f90
  forall_7.f90
  intrinsic_fraction_exponent.f90
  intrinsic_nearest.f90
  intrinsic_sr_kind.f90
  nan_inf_fmt.f90
  random_2.f90
)
