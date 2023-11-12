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
# assertion in flang.
file(GLOB UNIMPLEMENTED_FILES CONFIGURE_DEPENDS
  # unimplemented: BIND(C) module variable linkage
  bind_c-1_0.f90
  bind_c-2_0.f90
  bind_c-2b_0.f90
  bind_c-3_0.f90
  bind_c-4_0.f90
  bind_c-5_0.f90
  bind_c-6_0.f90
)

# These tests are disabled because they cause flang to crash
file(GLOB SKIPPED_FILES CONFIGURE_DEPENDS
  # error: Unexpected typeless constant value
  20100222-1_0.f03

  # --------------------------------------------------------------------------
  #
  # These tests are skipped because of "odd" reasons.

  # This test seems to depend on pr87689_1.f but that is not declared in the
  # main file, pr87689_0.f. Because of the missing dependency, attempting to
  # build it results in an undefined reference at link time.
  pr87689_0.f

  # pr41576_1.f90 seems to be the main file, but there are no dg directives in
  # it. Instead, there is a run directive in pr41576_0.f90 which consists of a
  # single subroutine foo that is called in pr41576_1.f90. Obviously, the dg
  # directive is in the wrong place and it ought to be fixed.
  pr41576_0.f90

  # This requires a module globalvar_mod which is defined in pr47839_0.f90.
  # But there is no explicit dependency declared between the two files, so
  # the test obviously fails.
  pr47839_1.f90
)

# These tests fail when they are expected to pass.
file(GLOB FAILING_FILES CONFIGURE_DEPENDS
  # These files fail to compile when compilation is expected to succeed.
  pr47839_1.f90
  bind-c-char_0.f90
)
