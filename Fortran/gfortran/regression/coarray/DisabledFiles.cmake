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
  # unimplemented: support for polymorphic types
  poly_run_3.f90

  # unimplemented: coarray allocation
  allocate_errgmsg.f90
  array_temporary.f90
  get_array.f90
  lock_2.f90
  move_alloc_1.f90
  send_array.f90
  send_char_array_1.f90
  sendget_array.f90

  # unimplemented: coarray reference
  get_to_indirect_array.f90

  # unimplemented: coarray in procedure interface
  dummy_1.f90
  dummy_2.f90
  poly_run_1.f90
  pr107441-caf.f90
  ptr_comp_1.f08
  ptr_comp_2.f08
  scalar_alloc_1.f90

  # unimplemented: intrinsic: '[SYM]'
  array_temporary-1.f90
  coindexed_1.f90
  collectives_1.f90
  collectives_2.f90
  cosubscript_1.f90
  failed_images_2.f08
  image_status_2.f08
  stopped_images_2.f08
  this_image_1.f90

  # unimplemented: EVENT POST runtime
  event_4.f08

  # unimplemented: LOCK runtime
  lock_1.f90

  # unimplemented: CriticalConstruct implementation
  sync_1.f90
  sync_3.f90
)

# Some tests in the suite may be unsupported for one reason or another.
file(GLOB SKIPPED_FILES CONFIGURE_DEPENDS
  # ------------------------------------------------------------------------
  #
  # These tests are skipped because they hit a 'not yet implemented' assertion
  # in flang. They should be removed from here when the corresponding feature
  # is implemented.


  # --------------------------------------------------------------------------
  #
  # These tests are skipped because they trigger internal compiler errors.
  #

  # error: Unexpected typeless constant value
  alloc_comp_4.f90
  coarray_allocated.f90
  collectives_3.f90
  get_to_indexed_array_1.f90
  lib_realloc_1.f90
  ptr_comp_3.f08
  scalar_alloc_2.f90

  # error: not a constant derived type expression
  alloc_comp_5.f90
  ptr_comp_4.f08

  # error: No explicit type declared for '[SYM]'
  image_index_1.f90
  image_index_2.f90
  image_index_3.f90
  this_image_2.f90

  # --------------------------------------------------------------------------
  #
  # These tests are skipped because they trigger semantic errors. It may be
  # because they use non-standard features that are currently not supported, or
  # it could be unimplemented features that are not tagged as such.
  #

  # error: 'coarray=' argument must have corank > 0 for intrinsic '[SYM]'
  alloc_comp_1.f90
  subobject_1.f90

  # error: 'atom=' argument must be a scalar coarray or coindexed object for
  # intrinsic '[SYM]'
  atomic_1.f90

  # error: '[SYM]' is not a known intrinsic procedure
  atomic_2.f90
  collectives_4.f90

  # error: Actual argument associated with coarray dummy argument must be
  # a coarray
  codimension.f90
  codimension_3.f90

  # error: Coarray argument requires an explicit interface
  event_1.f90
  event_3.f08

  # error: Keyword 'stat=' may not appear in a reference to a procedure with an
  # implicit interface
  event_2.f90

  # error: '[SYM]' is a non-ALLOCATABLE coarray and must have an explicit
  # coshape
  poly_run_2.f90

  # --------------------------------------------------------------------------
  #
  # These tests are skipped because they are intended to be additional sources
  # for codimension2.f90. Because of the way the test-suite is setup, it
  # tries to compile all the files - even those that do not have a do-compile
  # directive. These files are intended to be compiled together with
  # codimension2.f90 because they use a module that is created by the former.
  # If compiled separately, they do not find the module and fail to compile.
  codimension_2a.f90
  codimension_2b.f90

  # --------------------------------------------------------------------------
  #
  # This is a multi-file test, but cannot find the additional sources
  # codimension_2a.f90 and codimension_2b.f90. This is almost certainly a bug
  # in the build files in llvm-test-suite/Fortran/gfortran.
  codimension_2.f90
)

# These tests fail at runtime when they should pass.
file(GLOB FAILING_FILES CONFIGURE_DEPENDS
  fail_image_2.f08
)
