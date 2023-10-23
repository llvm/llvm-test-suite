#===------------------------------------------------------------------------===#
#
# Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
# See https://llvm.org/LICENSE.txt for license information.
# SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
#
#===------------------------------------------------------------------------===#

# These are files which are skipped by default (see DisabledFiles.cmake) but
# are fixed by this feature
file(GLOB UNSKIPPED_FILES CONFIGURE_DEPENDS
  char_cast_2.f90
  deferred_character_8.f90
  dependency_23.f90
  interface_assignment_1.f90
  typebound_assignment_6.f90
  volatile10.f90
)

# These are files which fail by default (see DisabledFiles.cmake) but are fixed
# by this feature
file(GLOB PASSING_FILES CONFIGURE_DEPENDS
  advance_5.f90
  aliasing_dummy_5.f90
  dependency_45.f90
  elemental_dependency_1.f90
  elemental_dependency_5.f90
  elemental_dependency_6.f90
  forall_12.f90
  forall_17.f90
  inline_transpose_1.f90
  internal_pack_3.f90
  missing_optional_dummy_6.f90
  mvbits_4.f90
  pr50069_1.f90
  pr68227.f90
)
