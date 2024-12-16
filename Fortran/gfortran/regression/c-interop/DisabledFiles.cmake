#===------------------------------------------------------------------------===#
#
# Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
# See https://llvm.org/LICENSE.txt for license information.
# SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
#
#===------------------------------------------------------------------------===#

# There are currently no unsupported files.
set(UNSUPPORTED_FILES "")

# These tests trigger "not yet implemented" assertions in flang.
file(GLOB UNIMPLEMENTED_FILES CONFIGURE_DEPENDS
  c535a-1.f90
  cf-out-descriptor-6.f90
  contiguous-1.f90
  contiguous-2.f90
  contiguous-3.f90
  fc-descriptor-6.f90
  fc-out-descriptor-6.f90

  # unimplemented: BIND(C) internal procedures
  fc-out-descriptor-5.f90

  # unimplemented: support for polymorphic types
  c407a-1.f90
)

# These tests are skipped because they trigger internal compiler errors.
file(GLOB SKIPPED_FILES CONFIGURE_DEPENDS
  # error: Unexpected typeless constant value
  allocatable-dummy.f90
  allocate-errors.f90
  allocate.f90
  cf-descriptor-1.f90
  cf-descriptor-2.f90
  cf-descriptor-3.f90
  cf-descriptor-4.f90
  cf-descriptor-5.f90
  cf-descriptor-6.f90
  cf-descriptor-7.f90
  cf-descriptor-8.f90
  cf-out-descriptor-1.f90
  cf-out-descriptor-2.f90
  cf-out-descriptor-3.f90
  cf-out-descriptor-4.f90
  cf-out-descriptor-5.f90
  establish-errors.f90
  establish.f90
  fc-descriptor-1.f90
  fc-descriptor-2.f90
  fc-descriptor-3.f90
  fc-descriptor-4.f90
  fc-descriptor-5.f90
  fc-descriptor-8.f90
  fc-descriptor-9.f90
  fc-out-descriptor-1.f90
  fc-out-descriptor-2.f90
  fc-out-descriptor-3.f90
  fc-out-descriptor-4.f90
  fc-out-descriptor-7.f90
  optional.f90
  section-2.f90
  section-2p.f90
  section-3.f90
  section-3p.f90
  section-4.f90
  section-errors.f90
  select-errors.f90
  select.f90
  setpointer-errors.f90
  setpointer.f90
  typecodes-array-basic.f90
  typecodes-array-float128.f90
  typecodes-array-int128.f90
  typecodes-array-longdouble.f90
  typecodes-sanity.f90
  typecodes-scalar-basic.f90
  typecodes-scalar-float128.f90
  typecodes-scalar-int128.f90
  typecodes-scalar-longdouble.f90

  # error: '[SYM]' is an external procedure without the EXTERNAL attribute in a
  # scope with IMPLICIT NONE(EXTERNAL)
  fc-descriptor-7.f90

  # error: A BIND(C) object must have an interoperable type
  typecodes-array-char.f90

  # error: No explicit type declared for '[SYM]'
  section-1.f90
  section-1p.f90
)

# These tests fail when they are expected to pass.
file(GLOB FAILING_FILES CONFIGURE_DEPENDS
  # These files are expected to fail to compile, but succeed instead.
  c516.f90
  c524a.f90
  c535b-3.f90
)
