#===------------------------------------------------------------------------===#
#
# Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
# See https://llvm.org/LICENSE.txt for license information.
# SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
#
#===------------------------------------------------------------------------===#

# These tests are disabled because they use unsupported extensions.
file(GLOB Unsupported CONFIGURE_DEPENDS
  dec_math_1.f90    # cotand, cotan
)

# These tests are disabled because they trigger "not yet implemented"
# assertions in flang.
file(GLOB Unimplemented CONFIGURE_DEPENDS
  # unimplemented: assumed rank in procedure interface
  ieee_1.F90
  large_3.F90
  modes_1.f90

  # unimplemented: intrinsic module procedure: [SYM]
  fma_1.f90
  ieee_11.F90
  ieee_12.f90
  ieee_2.f90
  ieee_3.f90
  ieee_4.f90
  large_2.f90
  rounding_1.f90
  rounding_2.f90
  rounding_3.f90
  signaling_1.f90
  signaling_2.f90
  signaling_3.f90
  signbit_1.f90

  # unimplemented: no math runtime available for 'sqrt(f80)'
  large_1.f90
)

# These tests are disabled because they cause flang to crash.
file(GLOB Skipped CONFIGURE_DEPENDS
  # error: No specific subroutine of generic '[SYM]' matches the actual
  # arguments
  ieee_6.f90

  # error: missing mandatory 'p=' argument
  ieee_7.f90

  # error: Must be a constant value
  ieee_8.f90

  # error: No specific subroutine of generic '[SYM]' matches the actual
  # arguments
  ieee_6.f90

  # error: missing mandatory 'p=' argument
  ieee_7.f90

  # error: Must be a constant value
  ieee_8.f90

  # error: unexpected typeless constant value
  ieee_10.f90
  ieee_5.f90
  ieee_9.f90
  intrinsics_1.f90
  intrinsics_2.F90
  large_4.f90
  underflow_1.f90
)

list(APPEND UnsupportedTests "${Unsupported}")
list(APPEND UnimplementedTests "${Unimplemented}")
list(APPEND SkippedTests "${Skipped}")
list(APPEND FailingTests "")

add_tests("${UnsupportedTests}" "${UnimplementedTests}" "${SkippedTests}" "${FailingTests}")
