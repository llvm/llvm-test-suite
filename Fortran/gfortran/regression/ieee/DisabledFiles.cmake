#===------------------------------------------------------------------------===#
#
# Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
# See https://llvm.org/LICENSE.txt for license information.
# SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
#
#===------------------------------------------------------------------------===#

# These tests are disabled because they use unsupported extensions.
file(GLOB UNSUPPORTED_FILES CONFIGURE_DEPENDS
  dec_math_1.f90    # cotand, cotan
)

# These tests are disabled because they trigger "not yet implemented"
# assertions in flang.
file(GLOB UNIMPLEMENTED_FILES CONFIGURE_DEPENDS
  # unimplemented: assumed rank in procedure interface
  large_3.F90

  # unimplemented: intrinsic module procedure: [SYM]
  fma_1.f90
  ieee_2.f90
  ieee_3.f90
  large_2.f90
  rounding_1.f90
  rounding_3.f90

  # unimplemented: no math runtime available for 'sqrt(f80)'
  large_1.f90
)

# These tests are disabled because they cause flang to crash.
file(GLOB SKIPPED_FILES CONFIGURE_DEPENDS
  # error: missing mandatory 'p=' argument
  ieee_7.f90

  # error: Must be a constant value
  ieee_8.f90

  # error: unexpected typeless constant value
  ieee_10.f90

  # error: Actual argument for 'mold=' has bad type 'UNSIGNED'
  out_of_range.f90

  # --------------------------------------------------------------------------
  #
  # These tests require libquadmath which is not built by default. They are
  # disabled until the test suite's configure script is fixed to allow
  # conditionally enabling them if libquadmath is available.

  ieee_9.f90
)

# There are currently no failing files.
set(FAILING_FILES "")
