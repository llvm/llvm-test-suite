#===------------------------------------------------------------------------===#
#
# Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
# See https://llvm.org/LICENSE.txt for license information.
# SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
#
#===------------------------------------------------------------------------===#

# Creates a test from each valid test file in the current source directory. Each
# argument to a function is a list. If a test file is in any of the lists, a
# test will not be created from it.
function(add_tests UnsupportedTests UnimplementedTests SkippedTests FailingTests)
  # This will just get all the Fortran source files in the directory. Since
  # the tests here are a mix of single-source and multi-source tests, this will
  # include files that are dependencies of some "main" test file as well. Those
  # will be filtered out later.
  file(GLOB AllFiles CONFIGURE_DEPENDS LIST_DIRECTORIES false
    *.f*
    *.F*
  )

  set(TestsToSkip)

  # There is still a chance that some of the unsupported tests may need to be
  # enabled, for instance if the non-standard extensions that they exercise are
  # supported due to user demand.
  if (NOT TEST_SUITE_FORTRAN_FORCE_ALL_TESTS AND
      NOT TEST_SUITE_FORTRAN_FORCE_UNSUPPORTED_TESTS)
    list(APPEND TestsToSkip ${UnsupportedTests})
  endif()

  # For the remaining tests, there is cause to build and run the skipped, failing
  # and unimplemented tests since some could be enabled once some feature is
  # implemented. Eventually, all the TEST_SUITE_FORTRAN_FORCE_* options (perhaps
  # with the exception of TEST_SUITE_FORTRAN_FORCE_UNSUPPORTED_TESTS) should
  # become redundant and removed.
  if (NOT TEST_SUITE_FORTRAN_FORCE_ALL_TESTS AND
      NOT TEST_SUITE_FORTRAN_FORCE_UNIMPLEMENTED_TESTS)
    list(APPEND TestsToSkip ${UnimplementedTests})
  endif()

  if (NOT TEST_SUITE_FORTRAN_FORCE_ALL_TESTS AND
      NOT TEST_SUITE_FORTRAN_FORCE_FAILING_TESTS)
    list(APPEND TestsToSkip ${FailingTests})
  endif()

  if (NOT TEST_SUITE_FORTRAN_FORCE_ALL_TESTS AND
      NOT TEST_SUITE_FORTRAN_FORCE_SKIPPED_TESTS)
    list(APPEND TestsToSkip ${SkippedTests})
  endif()

  foreach(TestToSkip ${TestsToSkip})
    list(REMOVE_ITEM AllFiles ${TestToSkip})
  endforeach()

  # For now, only the execute tests are supported. Those have a "{ dg-do run }"
  # or a "{ dg-lto-do run }" directive.
  foreach(File ${AllFiles})
    set(MAIN)
    set(ADDITIONAL_SOURCES)
    set(ADDITIONAL_FFLAGS)
    set(ADDITIONAL_LDFLAGS)

    file(STRINGS ${File} FileLines)
    foreach(FileLine ${FileLines})
      if(FileLine MATCHES "^.*[{][ ]*dg-(lto-)?do[ ]*([A-Za-z0-9]+).*[}].*$")
        # If this is not a main file for an execute test, just move on to the
        # next file.
        if (NOT ${CMAKE_MATCH_2} MATCHES "run")
          break()
        else()
          set(MAIN "${File}")
        endif()
      elseif(FileLine MATCHES "dg-additional-sources[ ]*[\"]?(.+)[\"]?[ ]*[}]")
        separate_arguments(ADDITIONAL_SOURCES UNIX_COMMAND ${CMAKE_MATCH_1})
        list(TRANSFORM ADDITIONAL_SOURCES STRIP)
      endif()
    endforeach()

    if (MAIN)
      gfortran_execute_test(${MAIN}
        PREFIX "gfortran-regression-execute"
        FFLAGS ${ADDITIONAL_FFLAGS}
        LDFLAGS ${ADDITIONAL_LDFLAGS}
        DEPFILES ${ADDITIONAL_SOURCES})
    endif()
  endforeach()
endfunction()

# Some tests in the suite use non-standard features that are supported in
# gfortran but are not (and might never be) supported by flang. But if they are,
# they should be moved out of here.
file(GLOB Unsupported CONFIGURE_DEPENDS
  # --------------------------------------------------------------------------
  #
  # This tests the ability of gfortran to emit code with calling conventions
  # compatible with g77 and f2c. These will probably never be relevant to
  # flang.
  f2c_4.f90
  value_4.f90

  # --------------------------------------------------------------------------
  #
  # These test/use GNU extensions that are not currently supported by Flang.
  #
  # TODO: Some of the tests may actually just use a GNU intrinsic during the
  # process of testing some other functionality. It may be worthwhile to
  # include a version elsewhere in this repo which tests that same functionality
  # but without using any GNU extensions.
  #
  backtrace_1.f90                 # backtrace
  complex_intrinsic_1.f90         # complex
  dec_io_2.f90                    # fseek
  dec_io_2a.f90                   # fseek
  fgetc_1.f90                     # fgetc, fputc
  fgetc_2.f90                     # fgetc, fputc
  fseek.f90                       # fseek
  ftell_1.f90                     # ftell
  ftell_2.f90                     # ftell
  ftell_3.f90                     # ftell
  inquire_10.f90                  # getcwd
  int_conv_1.f90                  # int2, int8
  itime_idate_1.f                 # itime, idate
  itime_idate_2.f                 # itime, idate
  list_read_9.f90                 # fputc
  ltime_gmtime_1.f90              # time, ltime, gmtime
  ltime_gmtime_2.f90              # time, ltime, gmtime
  malloc_free_1.f90               # malloc, free
  mclock.f90                      # mclock, mclock8
  open_errors.f90                 # chmod, getuid
  open_new.f90                    # unlink
  secnds.f                        # secnds
  secnds-1.f                      # secnds
  stat_1.f90                      # stat, fstat, lstat, getuid, getgid
  stat_2.f90                      # stat, fstat, lstat, getuid, getgid
  transfer_array_intrinsic_2.f90  # rand
)

# These tests are skipped because they hit a 'not yet implemented' assertion
# in flang and thus fail to compile. They should be removed from here when the
# corresponding feature is implemented. Eventually, this variable should be
# removed altogether once all the missing features are implemented.
file(GLOB Unimplemented CONFIGURE_DEPENDS
  # unimplemented: assumed rank in procedure interface.
  ISO_Fortran_binding_1.f90
  ISO_Fortran_binding_13.f90
  ISO_Fortran_binding_14.f90
  ISO_Fortran_binding_16.f90
  ISO_Fortran_binding_3.f90
  ISO_Fortran_binding_6.f90
  ISO_Fortran_binding_9.f90
  PR100029.f90
  PR100097.f90
  PR100098.f90
  PR100915.f90
  PR93963.f90
  PR94022.f90
  PR95196.f90
  PR96726.f90
  PR96727.f90
  PR96728.f90
  PR97046.f90
  assumed_rank_12.f90
  assumed_rank_18.f90
  assumed_rank_19.f90
  assumed_rank_20.f90
  assumed_type_9.f90
  interface_49.f90
  is_contiguous_2.f90
  pr84088.f90
  select_rank_5.f90
  sizeof_4.f90
  sizeof_6.f90

  # unimplemented: procedure pointers
  dummy_procedure_7.f90
  elemental_dependency_4.f90
  internal_dummy_3.f08
  optional_absent_7.f90
  optional_absent_8.f90
  pointer_check_1.f90
  pointer_check_2.f90
  pointer_check_3.f90
  pointer_check_4.f90
  pointer_init_10.f90
  pointer_init_4.f90
  pointer_init_5.f90
  pr78719_1.f90
  proc_ptr_1.f90
  proc_ptr_18.f90
  proc_ptr_21.f90
  proc_ptr_22.f90
  proc_ptr_23.f90
  proc_ptr_25.f90
  proc_ptr_26.f90
  proc_ptr_3.f90
  proc_ptr_5.f90
  proc_ptr_51.f90
  proc_ptr_comp_8.f90
  proc_ptr_comp_9.f90
  proc_ptr_result_3.f90

  # unimplemented: procedure pointer results
  pointer_check_5.f90
  proc_ptr_12.f90
  proc_ptr_result_7.f90

  # unimplemented: procedure pointer arguments
  proc_ptr_10.f90
  proc_ptr_19.f90
  proc_ptr_20.f90
  proc_ptr_36.f90
  proc_ptr_6.f90
  proc_ptr_7.f90
  proc_ptr_comp_2.f90
  submodule_30.f08

  # unimplemented: procedure components
  proc_ptr_48.f90
  proc_ptr_comp_1.f90
  proc_ptr_comp_11.f90
  proc_ptr_comp_13.f90
  proc_ptr_comp_14.f90
  proc_ptr_comp_18.f90
  proc_ptr_comp_19.f90
  proc_ptr_comp_29.f90
  proc_ptr_comp_34.f90
  proc_ptr_comp_5.f90
  structure_constructor_11.f90

  # unimplemented: support for polymorphic types.
  ISO_Fortran_binding_17.f90
  PR100120.f90
  PR100245.f90
  PR95331.f90
  alloc_comp_deep_copy_1.f03
  allocate_with_source_18.f03
  allocate_with_source_8.f08
  associate_18.f08
  associate_20.f03
  associate_8.f03
  alloc_comp_class_2.f90
  allocate_alloc_opt_10.f90
  allocate_with_source_26.f90
  associate_13.f90
  associate_48.f90
  associated_6.f90
  associated_target_4.f90
  character_workout_1.f90
  character_workout_4.f90
  class_1.f03
  class_18.f03
  class_26.f03  class_35.f90
  class_48.f90
  class_46.f03
  class_6.f03
  class_62.f90
  class_63.f90
  class_66.f90
  class_allocate_1.f03
  class_allocate_13.f90
  class_allocate_18.f90
  class_allocate_19.f03
  class_allocate_21.f90
  class_allocate_22.f90
  class_allocate_23.f08
  class_allocate_25.f90
  class_allocate_3.f03
  class_allocate_4.f03
  class_allocate_5.f90
  class_allocate_6.f03
  class_array_1.f03
  class_array_15.f03
  class_array_14.f90
  class_array_2.f03
  class_array_20.f03
  class_array_3.f03
  class_array_8.f03
  class_dummy_1.f03
  class_nameclash.f90
  class_result_5.f90
  class_result_6.f90
  class_to_type_1.f03
  class_to_type_4.f90
  coarray_allocate_2.f08
  coarray_allocate_3.f08
  coarray_allocate_5.f08
  dependency_53.f90
  dependency_60.f90
  dynamic_dispatch_10.f03
  elemental_optional_args_5.f03
  exit_3.f08
  extends_type_of_1.f03
  extends_type_of_2.f03
  finalize_37.f90
  implicit_class_1.f90
  move_alloc_13.f90
  move_alloc_14.f90
  move_alloc_2.f90
  move_alloc_5.f90
  pointer_array_5.f90
  pointer_array_8.f90
  pointer_array_component_3.f90
  pointer_check_14.f90
  pointer_intent_4.f90
  pr100551.f90
  pr108010.f90
  pr48958.f90
  pr78092.f90
  pr86328.f90
  pr86760.f90
  pr94397.F90
  proc_ptr_52.f90
  proc_ptr_comp_pass_3.f90
  realloc_on_assign_27.f08
  realloc_on_assign_31.f90
  same_type_as_2.f03
  select_type_13.f03
  select_type_14.f03
  select_type_19.f03
  select_type_2.f03
  select_type_26.f03
  select_type_27.f03
  select_type_3.f03
  select_type_35.f03
  select_type_37.f03
  select_type_39.f03
  select_type_5.f03
  select_type_6.f03
  select_type_7.f03
  select_type_8.f03
  select_type_4.f90
  select_type_42.f90
  select_type_44.f90
  select_type_48.f90
  select_type_49.f90
  select_type_50.f90
  storage_size_1.f08
  storage_size_3.f08
  structure_constructor_13.f03
  transfer_class_3.f90
  type_to_class_1.f03
  type_to_class_2.f03
  type_to_class_3.f03
  type_to_class_5.f03
  unlimited_polymorphic_14.f90
  unlimited_polymorphic_17.f90
  unlimited_polymorphic_20.f90
  unlimited_polymorphic_21.f90
  unlimited_polymorphic_22.f90
  unlimited_polymorphic_24.f03
  unlimited_polymorphic_3.f03
  unlimited_polymorphic_30.f03
  unlimited_polymorphic_32.f03
  unlimited_polymorphic_5.f90
  unlimited_polymorphic_6.f90

  # unimplemented: BIND (C) internal procedure.
  ISO_Fortran_binding_19.f90
  PR93308.f90
  array_reference_3.f90
  bind_c_char_2.f90
  bind_c_char_3.f90
  bind_c_char_4.f90
  bind_c_char_5.f90
  internal_dummy_4.f08

  # unimplemented: BIND(C) module variable linkage
  bind_c_dts.f90
  bind_c_vars.f90
  global_vars_c_init.f90
  implicit_pure_5.f90
  proc_ptr_8.f90

  # unimplemented: character array expression temp with dynamic length.
  actual_array_constructor_2.f90
  array_constructor_17.f90
  associate_35.f90
  assumed_charlen_arg_1.f90
  assumed_charlen_sharing.f90
  char_length_7.f90
  char_result_13.f90
  deferred_character_36.f90
  mapping_3.f90
  transfer_resolve_1.f90

  # unimplemented: allocatable component in structure constructor
  alloc_comp_constructor_7.f90

  # unimplemented: gather rhs LEN parameters in assignment to allocatable
  allocate_assumed_charlen_4.f90
  allocate_error_5.f90
  char_length_20.f90
  char_length_21.f90
  deferred_character_1.f90
  deferred_character_14.f90
  deferred_character_2.f90
  deferred_character_22.f90
  deferred_character_34.f90
  deferred_character_4.f90
  deferred_character_7.f90
  dependency_50.f90
  dependency_51.f90
  elemental_function_3.f90
  widechar_11.f90

  # unimplemented: passing dynamically optional argument to elemental procedures
  bounds_check_9.f90
  bounds_check_fail_2.f90
  elemental_optional_args_2.f90
  elemental_optional_args_3.f90
  elemental_optional_args_4.f90
  elemental_optional_args_6.f90
  elemental_optional_args_7.f90
  generic_31.f90
  optional_absent_2.f90

  # unimplemented: BOZ
  boz_bge.f90

  # unimplemented: coarray allocation
  associate_37.f90

  # unimplemented: coarray in procedure interface
  coarray_allocate_4.f08
  class_optional_1.f90
  class_optional_2.f90
  coarray_41.f90

  # unimplemented: coarray reference
  coarray_lib_comm_1.f90

  # unimplemented: CriticalConstruct implementation
  coarray_2.f90

  # unimplemented: intrinsic: this_image
  coarray_40.f90
  coarray_stat_2.f90
  random_init_3.f90
  random_init_4.f90
  random_init_5.f90
  random_init_6.f90

  # unimplemented: intrinsic: co_broadcast
  coarray_collectives_17.f90

  # unimplemented: intrinsic: atan
  atan2_1.f90

  # unimplemented: intrinsic: erfc_scaled
  erfc_scaled_1.f90

  # unimplemented: intrinsic: execute_command_line
  execute_command_line_2.f90
  execute_command_line_3.f90

  # unimplemented: intrinsic: failed_images
  coarray_failed_images_1.f08

  # unimplemented: intrinsic: image_status
  coarray_image_status_1.f08

  # unimplemented: intrinsic: stopped_images
  coarray_stopped_images_1.f08

  # unimplemented: assignment to pointer result of function reference
  ptr-func-3.f90
  ptr_func_assign_5.f08

  # unimplemented: intrinsic: selected_char_kind
  selected_char_kind_1.f90
  selected_char_kind_4.f90

  # unimplemented: intrinsic: min and max for CHARACTER
  minmax_char_1.f90
  widechar_intrinsics_9.f90
  zero_length_2.f90

  # unimplemented: %VAL() intrinsic for arguments
  c_by_val_1.f
  c_by_val_5.f90
  pointer_check_12.f90

  # unimplemented: parameterized derived types
  dec_type_print_2.f03
  pdt_1.f03
  pdt_10.f03
  pdt_22.f03
  pdt_25.f03
  pdt_7.f03

  # unimplemented: host associated derived type with length parameters
  pdt_31.f03

  # unimplemented: derived type components with non default lower bounds
  structure_constructor_1.f03

  # unimplemented: asynchronous transfers not implemented in runtime
  f2003_inquire_1.f03
  f2003_io_1.f03

  # unimplemented: support for UNION
  dec_init_1.f90
  dec_init_3.f90
  dec_init_4.f90
  dec_structure_22.f90
  dec_union_1.f90
  dec_union_2.f90
  dec_union_3.f90
  dec_union_4.f90
  dec_union_5.f90
  dec_union_6.f90

  # unimplemented: no math runtime available for '[SYM]'
  large_integer_kind_2.f90
  large_real_kind_2.F90
  large_real_kind_3.F90
  large_real_kind_3.F90
  large_real_kind_form_io_1.f90
  norm2_3.f90
  pr96711.f90
)

# These tests are skipped because they cannot be compiled. Unlike the
# UnimplementedTests list, they do not fail with a "not yet implemented"
# assertion. The root cause for the failure could very well be one of those,
# but with the specific failure mode that is observed, it is not clear what
# missing feature is causing the compile-failure for these tests.
# If any of these tests use features that will never be supported, they should
# be moved to the UnsupportedTests list. If the cause of the failure of any
# tests in this list is addressed, they should be removed from here.
#
file(GLOB Skipped CONFIGURE_DEPENDS
  # --------------------------------------------------------------------------
  #
  # These tests are skipped because they trigger internal compiler errors.
  #

  # error: Unexpected typeless constant value
  actual_array_constructor_1.f90
  actual_array_offset_1.f90
  actual_pointer_function_1.f90
  aliasing_dummy_1.f90
  aliasing_dummy_4.f90
  allocatable_function_10.f90
  allocatable_function_9.f90
  allocatable_scalar_10.f90
  allocatable_scalar_13.f90
  allocatable_scalar_3.f90
  allocatable_scalar_9.f90
  allocate_alloc_opt_6.f90
  allocate_class_3.f90
  allocate_derived_5.f90
  allocate_error_6.f90
  allocate_with_mold_1.f90
  allocate_with_mold_3.f90
  allocate_with_source_15.f03
  allocate_with_source_16.f90
  allocate_with_source_22.f03
  allocate_with_source_23.f03
  allocate_with_source_24.f90
  allocate_with_source_5.f90
  allocate_with_source_6.f90
  allocate_with_source_7.f08
  allocate_with_source_9.f08
  alloc_comp_assign_10.f90
  alloc_comp_assign_11.f90
  alloc_comp_assign_12.f03
  alloc_comp_assign_13.f08
  alloc_comp_assign_14.f08
  alloc_comp_assign_15.f03
  alloc_comp_assign_16.f03
  alloc_comp_assign_1.f90
  alloc_comp_assign_2.f90
  alloc_comp_assign_3.f90
  alloc_comp_assign_4.f90
  alloc_comp_assign_5.f90
  alloc_comp_assign_6.f90
  alloc_comp_assign_7.f90
  alloc_comp_assign_8.f90
  alloc_comp_assign_9.f90
  alloc_comp_auto_array_1.f90
  alloc_comp_auto_array_2.f90
  alloc_comp_basics_1.f90
  alloc_comp_basics_2.f90
  alloc_comp_basics_5.f90
  alloc_comp_bounds_1.f90
  alloc_comp_class_1.f90
  alloc_comp_class_3.f03
  alloc_comp_class_4.f03
  alloc_comp_class_5.f03
  alloc_comp_constructor_1.f90
  alloc_comp_constructor_2.f90
  alloc_comp_constructor_3.f90
  alloc_comp_constructor_4.f90
  alloc_comp_constructor_5.f90
  alloc_comp_constructor_6.f90
  alloc_comp_deep_copy_2.f03
  alloc_comp_deep_copy_3.f03
  alloc_comp_default_init_1.f90
  alloc_comp_default_init_2.f90
  alloc_comp_initializer_1.f90
  alloc_comp_initializer_4.f03
  alloc_comp_misc_1.f90
  alloc_comp_optional_1.f90
  alloc_comp_result_1.f90
  alloc_comp_result_3.f90
  alloc_comp_scalar_1.f90
  alloc_comp_transformational_1.f90
  alloc_deferred_comp_1.f90
  array_constructor_32.f90
  array_constructor_type_14.f03
  array_constructor_type_8.f03
  arrayio_11.f90
  arrayio_derived_1.f90
  array_memcpy_5.f90
  array_reference_2.f90
  assign_func_dtcomp_1.f90
  associate_1.f03
  associate_24.f90
  associate_27.f90
  associate_28.f90
  associate_32.f03
  associate_38.f90
  associate_43.f90
  associate_46.f90
  associate_47.f90
  associate_60.f90
  associate_9.f03
  associated_target_3.f90
  associated_target_6.f03
  associated_target_7.f90
  assumed_rank_21.f90
  bind_c_coms.f90
  bind_c_dts_2.f03
  bind_c_usage_10.f03
  bind_c_usage_16.f03
  bind_c_usage_24.f90
  bind_c_usage_33.f90
  binding_c_table_15_1.f03
  binding_label_tests_16.f03
  binding_label_tests_33.f90
  block_13.f08
  blockdata_11.f90
  bound_1.f90
  bound_5.f90
  bounds_check_17.f90
  bounds_check_5.f90
  bounds_check_8.f90
  c_char_tests_2.f03
  c_char_tests_3.f90
  c_f_pointer_shape_tests_5.f90
  c_f_pointer_tests_4.f90
  c_f_pointer_tests.f90
  c_funloc_tests_3.f03
  c_funloc_tests_4.f03
  c_funloc_tests.f03
  c_funptr_1.f90
  c_funptr_1_mod.f90
  char4-subscript.f90
  character_array_constructor_1.f90
  char_array_structure_constructor.f90
  char_assign_1.f90
  char_length_15.f90
  char_pointer_comp_assign.f90
  char_result_5.f90
  char_result_6.f90
  char_type_len.f90
  c_kind_int128_test2.f03
  c_kind_params.f90
  class_19.f03
  class_25.f03
  class_40.f03
  class_65.f90
  class_67.f90
  class_70.f03
  class_alias.f90
  class_allocate_11.f03
  class_allocate_12.f90
  class_allocate_14.f90
  class_allocate_15.f90
  class_allocate_20.f90
  class_array_16.f90
  class_array_21.f03
  class_array_23.f03
  class_array_7.f03
  class_array_9.f03
  class_assign_4.f90
  class_defined_operator_1.f03
  class_defined_operator_2.f03
  class_dummy_2.f03
  class_result_10.f90
  class_result_1.f03
  class_result_9.f90
  class_to_type_3.f03
  c_loc_test_20.f90
  c_loc_test.f90
  c_loc_tests_2.f03
  coarray_allocate_10.f08
  coarray_allocate_6.f08
  coarray_allocate_7.f08
  coarray_allocate_8.f08
  coarray_allocate_9.f08
  coarray_alloc_comp_1.f08
  coarray_alloc_comp_2.f08
  coarray_alloc_comp_3.f08
  coarray_alloc_comp_6.f08
  coarray_alloc_comp_7.f08
  coarray_alloc_comp_8.f08
  coarray_lib_alloc_4.f90
  coarray_poly_9.f90
  coarray_ptr_comp_1.f08
  coarray_ptr_comp_2.f08
  coarray_send_by_ref_1.f08
  com_block_driver.f90
  constructor_2.f90
  contained_module_proc_1.f90
  c_ptr_tests_10.f03
  c_ptr_tests_14.f90
  c_ptr_tests_19.f90
  c_ptr_tests_7.f03
  c_ptr_tests_8.f03
  c_ptr_tests_9.f03
  c_ptr_tests.f03
  cshift_2.f90
  cshift_nan_1.f90
  c_sizeof_1.f90
  c_sizeof_5.f90
  c_size_t_test.f03
  data_derived_1.f90
  data_stmt_pointer.f90
  dec_init_2.f90
  dec_structure_18.f90
  dec_structure_1.f90
  dec_structure_2.f90
  dec_structure_25.f90
  dec_structure_3.f90
  dec_structure_4.f90
  default_initialization_5.f90
  deferred_character_10.f90
  deferred_character_11.f90
  deferred_character_12.f90
  deferred_character_13.f90
  deferred_character_23.f90
  deferred_character_25.f90
  deferred_character_28.f90
  deferred_character_3.f90
  deferred_character_5.f90
  deferred_character_6.f90
  deferred_type_component_1.f90
  deferred_type_component_2.f90
  deferred_type_component_3.f90
  dependency_22.f90
  dependency_23.f90
  dependency_24.f90
  dependency_39.f90
  dependency_55.f90
  der_array_1.f90
  der_array_io_1.f90
  der_array_io_2.f90
  derived_comp_array_ref_1.f90
  derived_comp_array_ref_2.f90
  derived_comp_array_ref_3.f90
  derived_comp_array_ref_4.f90
  derived_comp_array_ref_7.f90
  derived_constructor_comps_1.f90
  derived_constructor_comps_4.f90
  derived_constructor_comps_5.f90
  derived_constructor_comps_6.f90
  derived_constructor_comps_7.f90
  derived_external_function_1.f90
  derived_init_3.f90
  derived_init_5.f90
  der_ptr_component_2.f90
  dtio_10.f90
  dtio_12.f90
  dtio_14.f90
  dtio_15.f90
  dtio_16.f90
  dtio_17.f90
  dtio_19.f90
  dtio_1.f90
  dtio_24.f90
  dtio_25.f90
  dtio_26.f03
  dtio_27.f90
  dtio_28.f03
  dtio_2.f90
  dtio_30.f03
  dtio_31.f03
  dtio_32.f03
  dtio_33.f90
  dtio_34.f90
  dtio_3.f90
  dtio_4.f90
  dtio_7.f90
  dtio_8.f90
  dtio_9.f90
  dynamic_dispatch_11.f03
  dynamic_dispatch_4.f03
  dynamic_dispatch_5.f03
  dynamic_dispatch_6.f03
  dynamic_dispatch_7.f03
  dynamic_dispatch_8.f03
  dynamic_dispatch_9.f03
  elemental_assignment_1.f90
  elemental_dependency_5.f90
  elemental_dependency_6.f90
  elemental_subroutine_10.f90
  elemental_subroutine_11.f90
  elemental_subroutine_2.f90
  elemental_subroutine_3.f90
  entry_13.f90
  entry_16.f90
  equiv_constraint_4.f90
  extends_4.f03
  finalize_13.f90
  finalize_17.f90
  finalize_25.f90
  finalize_31.f90
  finalize_33.f90
  finalize_36.f90
  finalize_38.f90
  finalize_38a.f90
  finalize_50.f90
  finalize_52.f90
  fmt_nonchar_2.f90
  forall_1.f90
  func_assign_3.f90
  func_derived_1.f90
  func_derived_2.f90
  func_derived_3.f90
  func_derived_4.f90
  func_result_6.f90
  function_kinds_1.f90
  generic_15.f90
  generic_23.f03
  implied_do_io_1.f90
  import4.f90
  import.f90
  init_flag_15.f03
  inline_matmul_1.f90
  inline_matmul_9.f90
  inquiry_type_ref_5.f90
  intent_optimize_10.f90
  intent_out_14.f90
  interface_assignment_2.f90
  internal_pack_13.f90
  internal_pack_14.f90
  internal_pack_1.f90
  internal_pack_8.f90
  intrinsic_pack_1.f90
  intrinsic_spread_1.f90
  intrinsic_unpack_1.f90
  iso_c_binding_rename_2.f03
  ISO_Fortran_binding_10.f90
  ISO_Fortran_binding_11.f90
  ISO_Fortran_binding_12.f90
  ISO_Fortran_binding_18.f90
  ISO_Fortran_binding_5.f90
  ISO_Fortran_binding_7.f90
  ISO_Fortran_binding_8.f90
  iso_fortran_binding_uint8_array.f90
  logical_temp_io.f90
  logical_temp_io_kind8.f90
  module_procedure_6.f90
  module_read_2.f90
  move_alloc_15.f90
  move_alloc_16.f90
  move_alloc_4.f90
  multiple_allocation_2.f90
  mvbits_7.f90
  mvbits_8.f90
  namelist_14.f90
  namelist_52.f90
  namelist_54.f90
  namelist_55.f90
  namelist_58.f90
  namelist_60.f90
  namelist_66.f90
  namelist_69.f90
  namelist_70.f90
  namelist_71.f90
  namelist_77.f90
  namelist_79.f90
  namelist_82.f90
  namelist_85.f90
  nested_allocatables_1.f90
  nested_modules_3.f90
  null_9.f90
  nullify_3.f90
  optional_class_1.f90
  overload_1.f90
  parameter_array_init_8.f90
  pdt_11.f03
  pdt_12.f03
  pdt_13.f03
  pdt_14.f03
  pdt_27.f03
  pdt_28.f03
  pointer_array_11.f90
  pointer_array_1.f90
  pointer_array_3.f90
  pointer_array_4.f90
  pointer_array_6.f90
  pointer_array_7.f90
  pointer_array_component_1.f90
  pointer_assign_14.f90
  pointer_assign_15.f90
  pointer_check_11.f90
  pointer_init_1.f90
  pointer_init_8.f90
  pointer_remapping_10.f90
  PR100132.f90
  PR100136.f90
  PR100911.f90
  pr100950.f90
  pr105205.f90
  pr106731.f90
  pr106918.f90
  pr107872.f90
  pr16938.f90
  pr17612.f90
  pr18392.f90
  pr19928-2.f90
  pr32627.f03
  pr35983.f90
  pr43808.f90
  pr43866.f90
  pr47008.f03
  pr55086_aliasing_dummy_4_tfat.f90
  pr62125.f90
  pr64230.f90
  pr65504.f90
  pr69955.f90
  pr71764.f90
  pr84155.f90
  pr84523.f90
  pr86322_3.f90
  pr88611.f90
  pr92050.f90
  pr93685_1.f90
  pr99602b.f90
  print_c_kinds.f90
  proc_decl_17.f90
  proc_decl_2.f90
  proc_ptr_comp_12.f90
  proc_ptr_comp_15.f90
  proc_ptr_comp_16.f90
  proc_ptr_comp_17.f90
  proc_ptr_comp_23.f90
  proc_ptr_comp_47.f90
  proc_ptr_comp_pass_1.f90
  proc_ptr_comp_pass_5.f90
  ptr_func_assign_1.f08
  ptr_func_assign_3.f08
  read_dir.f90
  realloc_on_assign_16.f90
  realloc_on_assign_17.f90
  realloc_on_assign_23.f90
  realloc_on_assign_28.f90
  realloc_on_assign_2.f03
  realloc_on_assign_32.f90
  realloc_on_assign_3.f03
  realloc_on_assign_9.f90
  recursive_alloc_comp_1.f08
  recursive_alloc_comp_2.f08
  recursive_alloc_comp_3.f08
  recursive_alloc_comp_4.f08
  recursive_check_16.f90
  repack_arrays_1.f90
  reshape.f90
  reshape_transpose_1.f90
  reshape_zerosize_3.f90
  same_type_as_3.f03
  select_type_15.f03
  select_type_36.f03
  select_type_43.f90
  simplify_cshift_1.f90
  sizeof.f90
  spread_scalar_source.f90
  spread_simplify_1.f90
  structure_constructor_14.f90
  structure_constructor_2.f03
  submodule_18.f08
  submodule_32.f08
  submodule_6.f08
  submodule_7.f08
  subref_array_pointer_1.f90
  subref_array_pointer_2.f90
  subref_array_pointer_4.f90
  substr_alloc_string_comp_1.f90
  transfer_assumed_size_1.f90
  transfer_simplify_10.f90
  transfer_simplify_1.f90
  transfer_simplify_2.f90
  trim_optimize_5.f90
  typebound_assignment_5a.f03
  typebound_assignment_6.f03
  typebound_assignment_7.f90
  typebound_call_10.f03
  typebound_call_13.f03
  typebound_call_17.f03
  typebound_call_18.f03
  typebound_call_19.f03
  typebound_call_1.f03
  typebound_call_20.f03
  typebound_call_2.f03
  typebound_call_3.f03
  typebound_call_6.f03
  typebound_generic_3.f03
  typebound_generic_4.f03
  typebound_generic_5.f03
  typebound_generic_6.f03
  typebound_generic_9.f03
  typebound_operator_12.f03
  typebound_operator_13.f03
  typebound_operator_20.f90
  typebound_operator_21.f03
  typebound_operator_3.f03
  typebound_operator_6.f03
  typebound_operator_7.f03
  typebound_operator_8.f03
  typebound_operator_9.f03
  typebound_proc_20.f90
  typebound_proc_23.f90
  typebound_proc_27.f03
  typebound_proc_35.f90
  typebound_proc_36.f90
  type_to_class_4.f03
  unlimited_polymorphic_18.f90
  unlimited_polymorphic_19.f90
  unlimited_polymorphic_1.f03
  unlimited_polymorphic_23.f90
  unlimited_polymorphic_25.f90
  unlimited_polymorphic_26.f90
  unlimited_polymorphic_29.f90
  use_24.f90
  use_27.f90
  used_dummy_types_1.f90
  value_1.f90
  value_tests_f03.f90
  where_2.f90
  whole_file_13.f90
  whole_file_14.f90
  winapi.f90
  zero_array_components_1.f90

  # error: 'fir.convert' op invalid type conversion
  achar_4.f90
  c_char_tests_4.f90
  c_char_tests_5.f90
  widechar_6.f90
  widechar_intrinsics_6.f90
  widechar_intrinsics_7.f90
  widechar_select_1.f90

  # error: a function must have a type
  proc_decl_9.f90

  # error: not a constant derived type expression
  allocate_with_source_10.f08
  allocate_with_source_11.f08
  arrayio_12.f90
  associate_25.f90
  associated_4.f90
  associated_target_5.f03
  automatic_default_init_1.f90
  char_component_initializer_1.f90
  char_component_initializer_2.f90
  char_length_8.f90
  charlen_15.f90
  charlen_16.f90
  class_9.f03
  class_allocate_10.f03
  class_allocate_7.f03
  class_allocate_8.f03
  class_allocate_9.f03
  class_array_4.f03
  class_to_type_2.f90
  coarray_42.f90
  constructor_3.f90
  dec_structure_6.f90
  default_initialization_3.f90
  default_initialization_4.f90
  deferred_character_26.f90
  defined_assignment_1.f90
  defined_assignment_10.f90
  defined_assignment_11.f90
  defined_assignment_2.f90
  defined_assignment_3.f90
  defined_assignment_4.f90
  defined_assignment_5.f90
  defined_assignment_9.f90
  dependency_25.f90
  der_array_io_3.f90
  derived_init_1.f90
  derived_init_2.f90
  derived_init_4.f90
  derived_pointer_recursion_2.f90
  dtio_22.f90
  dynamic_dispatch_1.f03
  dynamic_dispatch_12.f90
  dynamic_dispatch_2.f03
  dynamic_dispatch_3.f03
  extends_1.f03
  extends_16.f90
  extends_3.f03
  finalize_15.f90
  finalize_29.f08
  finalize_39.f90
  finalize_40.f90
  finalize_41.f90
  finalize_42.f90
  finalize_43.f90
  finalize_44.f90
  finalize_45.f90
  finalize_46.f90
  finalize_47.f90
  finalize_48.f90
  forall_19.f90
  init_flag_10.f90
  initialization_11.f90
  initialization_19.f90
  initialization_27.f90
  inquiry_type_ref_1.f08
  intent_out_13.f90
  intent_out_2.f90
  intent_out_5.f90
  interface_assignment_1.f90
  internal_pack_10.f90
  internal_pack_6a.f90
  intrinsic_pack_5.f90
  intrinsic_pack_6.f90
  move_alloc_10.f90
  move_alloc_6.f90
  namelist_13.f90
  namelist_15.f90
  namelist_40.f90
  namelist_47.f90
  namelist_64.f90
  namelist_78.f90
  namelist_96.f90
  no-automatic.f90
  optional_assumed_charlen_2.f90
  pointer_array_component_2.f90
  pointer_assign_10.f90
  pointer_assign_11.f90
  pointer_assign_8.f90
  pointer_assign_9.f90
  pointer_init_3.f90
  pr19926.f90
  pr51434.f90
  pr68078.f90
  pr69739.f90
  pr78290.f90
  pr83864.f90
  pr85786.f90
  result_default_init_1.f90
  structure_constructor_5.f03
  submodule_1.f08
  submodule_2.f08
  temporary_3.f90
  transfer_class_2.f90
  typebound_call_32.f90
  typebound_operator_15.f90

  # error: unemittable constant value
  namelist_utf8.f90

  # error: cannot be converted to LLVM IR: missing
  # `LLVMTranslationDialectInterface` registration for dialect for op: func.func
  leadz_trailz_1.f90
  leadz_trailz_2.f90

  # error: failed to legalize operation 'math.ctlz' that was explicitly marked
  # illegal
  leadz_trailz_3.f90

  # --------------------------------------------------------------------------
  #
  # These tests are skipped because they result in a compile error. This may
  # be the result of them exercising unsupported extensions that are not
  # supported in flang or some other reason. If there are multiple errors
  # in a single file, each unique error message will be provided.

  # error: Entity in ALLOCATE statement must have the ALLOCATABLE or POINTER
  # attribute
  ISO_Fortran_binding_15.f90

  # error: Left-hand side of assignment may not be polymorphic unless
  # assignment is to an entire allocatable
  PR100040.f90
  PR100103.f90

  # error: The left-hand side of a pointer assignment is not definable
  PR100094.f90
  associate_42.f90

  # error: Assumed-rank array cannot be forwarded to '[var]=' argument
  PR100906.f90
  PR100914.f90
  assumed_rank_10.f90
  assumed_rank_24.f90
  assumed_rank_9.f90
  associated_assumed_rank.f90
  assumed_rank_16.f90
  assumed_rank_8.f90

  # error: Pointer has rank 0 but target has rank [n]
  PR94331.f90
  PR94327.f90
  assumed_rank_1.f90

  # error: Actual argument variable length '1' does not match the expected
  # length '77'
  PR95214.f90

  # error: Dimension 1 of left operand has extent [m], but right operand has
  # extent [n]
  PR94289.f90
  assumed_rank_2.f90
  assumed_rank_22.f90
  assumed_rank_bounds_2.f90
  assumed_rank_bounds_3.f90
  assumed_rank_17.f90
  assumed_rank_bounds_1.f90

  # error: DIM=3 dimension is out of range for rank-1 array
  assumed_rank_3.f90
  assumed_rank_7.f90

  # error: Subscript [m] is less than lower bound [n] for dimension [d] of
  # array
  bounds_check_11.f90
  bounds_check_fail_1.f90

  # error: Assumed-size polymorphic array may not be associated with a
  # monomorphic dummy argument
  class_dummy_7.f90

  # error: '[var]' is an external procedure without the EXTERNAL attribute in
  # a scope with IMPLICIT NONE(EXTERNAL)
  assumed_type_13.f90
  bind-c-contiguous-3.f90
  bind-c-intent-out.f90

  # error: '[SYM]' may not appear in NULLIFY because '[SYM2]' is an INTENT(IN)
  # dummy argument
  pointer_intent_1.f90

  # error: Assumed type argument requires an explicit interface
  assumed_type_2a.f90

  # error: No intrinsic or user-defined ASSIGNMENT(=) matches operand types
  # 'TYPE 1' and 'TYPE 2'
  dec-comparison-complex_1.f90
  dec-comparison-complex_2.f90
  dec-comparison-int_1.f90
  dec-comparison-int_2.f90
  dec-comparison-real_1.f90
  dec-comparison-real_2.f90
  dec_char_conversion_in_assignment_1.f90
  dec_char_conversion_in_assignment_2.f90
  dec_char_conversion_in_assignment_3.f90
  dec_char_conversion_in_assignment_5.f90
  dec_char_conversion_in_assignment_6.f90
  dec_char_conversion_in_assignment_7.f90
  hollerith2.f90
  hollerith4.f90
  hollerith6.f90
  pdt_23.f03

  # error: Operands of .AND. must be LOGICAL; have 'TYPE 1' and 'TYPE 2'
  dec_bitwise_ops_1.f90
  dec_bitwise_ops_2.f90

  # error: A BIND(C) object must have an interoperable type
  bind-c-contiguous-1.f90
  bind-c-contiguous-4.f90
  bind-c-contiguous-5.f90
  bind_c_char_10.f90
  char4_decl-2.f90

  # error: A dim= argument is required for 'size' when the array is
  # assumed-size
  class_dummy_6.f90

  # error: No explicit type declared for '[sym]'
  PR49268.f90
  boz_complex_3.f90
  char_result_19.f90
  chmod_1.f90
  chmod_2.f90
  chmod_3.f90
  coarray_16.f90
  cray_pointers_7.f90
  dec_math.f90
  dec_math_5.f90
  fmt_en.f90
  fmt_en_rd.f90
  fmt_en_rn.f90
  fmt_en_ru.f90
  fmt_en_rz.f90
  fmt_f0_2.f90
  fmt_f0_3.f90
  fmt_g0_6.f08
  fmt_g0_7.f08
  fmt_pf.f90
  interface_12.f90
  result_in_spec_1.f90
  round_4.f90
  unlimited_polymorphic_13.f90

  # error: Shape of initialized object 'foo' must be constant
  pdt_26.f03

  # error: Kind type parameters of allocatable object must be the same as the
  # corresponding ones of SOURCE or MOLD expression
  pdt_3.f03

  # error: [sym] is not a variable
  cray_pointers_8.f90

  # error: Typeless (BOZ) not allowed for 'a=' argument
  boz_float_3.f90

  # error: Actual argument for 'i=' has bad type 'LOGICAL(1)'
  and_or_xor.f90

  # error: Argument of ALLOCATED() must be an ALLOCATABLE object or component
  select_rank_1.f90

  # error: 'coarray=' argument must have corank > 0 for intrinsic 'lcobound'
  bound_simplification_4.f90
  bound_simplification_5.f90

  # error: Coarray argument requires an explicit interface
  coarray_15.f90

  # error: 'mask=' argument has unacceptable rank 0
  coarray_13.f90

  # error: 'a' has corank 0, but coindexed reference has 1 cosubscripts
  coindexed_1.f90

  # error: 'temp_node_t' is PRIVATE in 'temp_node'
  constructor_6.f90

  # error: Invalid CONVERT value 'swap'
  convert_2.f90

  # error: Type of Cray pointee 'dpte1' is a non-sequence derived type
  cray_pointers_2.f90

  # error: DATA statement value could not be converted to the type '[TYPE]'
  dec_char_conversion_in_data_1.f90
  dec_char_conversion_in_data_2.f90
  dec_char_conversion_in_data_4.f90
  dec_char_conversion_in_data_5.f90
  dec_char_conversion_in_data_6.f90
  hollerith.f90

  # error: Duplicate UNIT specifier
  dec_io_5.f90
  dec_io_6.f90

  # error: cannot process subprogram that was already processed
  binding_label_tests_12.f03

  # error: Value of named constant cannot be computed as a constant value
  array_initializer_1.f90
  pr83874.f90

  # error: In an elemental procedure reference with at least one array argument,
  # actual argument that corresponds to an INTENT(OUT) or INTENT(INOUT) dummy
  # argument must be an array
  impure_1.f08

  # error: Invalid STATUS value
  iomsg_1.f90
  iostat_2.f90
  pr20163-2.f

  # error: '[SYM]' was not declared a separate module procedure
  class_assign_1.f08
  submodule_31.f08

  # error: No operator .XOR. defined for LOGICAL(4) and LOGICAL(4)
  dec_logical_xor_1.f90

  # error: Value in structure constructor of type 'education' is incompatible
  # with component
  extends_2.f03

  # error: If a POINTER or ALLOCATABLE dummy or actual argument is polymorphic,
  # both must be so
  finalize_12.f90

  # error: Must be a scalar value, but is a rank-1 array
  impl_do_var_data.f90

  # error: Unlimited format item list must contain a data edit descriptor
  fmt_error_11.f03

  # error: Expected '[FMT]' edit descriptor '.[SOMETHING]' value
  fmt_missing_period.f
  fmt_missing_period_2.f

  # error: Positive scale factor k (from kP) and width d in a 'E' edit
  # descriptor must satisfy 'k < d+2'
  fmt_zero_digits.f90

  # error: '[SYM]' is not a known intrinsic procedure
  gamma_1.f90
  specifics_1.f90

  # error: Keyword may not appear in a reference to a procedure with an implicit
  # interface
  getenv_1.f90

  # error: Cannot use-associate 'x'; it is already declared in this scope
  iso_fortran_env_3.f90

  # error: Must be a constant value
  matmul_17.f90
  matmul_8.f03
  pr67140.f90
  pr89077.f90
  substr_simplify.f90
  transfer_simplify_12.f90
  zero_sized_9.f90

  # error: Subscript 3 is greater than upper bound 2 for dimension 1 of array
  module_procedure_4.f90

  # error: '[SYM]' is not an object that can appear in an expression
  namelist_print_1.f

  # error: '[SYM]' is already declared in this scoping unit
  namelist_use.f90

  # error: Actual argument type '[TYPE1]' is not compatible with dummy argument
  # type '[TYPE2]'
  no_arg_check_2a.f90
  pdt_2.f03

  # error: '[SYM]' not found in module 'iso_fortran_env'
  overload_3.f90
  pr66311.f90
  proc_ptr_comp_6.f90
  proc_ptr_comp_pass_2.f90
  quad_2.f90
  quad_3.f90
  team_change_1.f90
  team_end_1.f90
  team_form_1.f90
  team_number_1.f90
  unlimited_polymorphic_31.f03

  # error: VOLATILE attribute was already specified
  volatile10.f90

  # error: 'mask=' argument has unacceptable rank 0
  pdt_20.f03

  # error: literal is too large
  pr92629.f90

  # error: In assignment to procedure pointer 'funct', the target is not a
  # procedure or procedure pointer
  proc_ptr_47.f90

  # error: '[SYM]' may not be a procedure as it is in a COMMON block
  proc_ptr_common_1.f90

  # error: Procedure pointer may not be ELEMENTAL
  proc_ptr_comp_45.f90

  # error: Procedure pointer associated with result of reference to function
  # that is an incompatible procedure pointer
  proc_ptr_result_1.f90

  # error: Actual argument associated with procedure pointer dummy argument
  # must be a POINTER unless INTENT(IN)
  proc_ptr_result_6.f90

  # error: Must have '[TYPE1]' type, but is '[TYPE2]'
  real_index_1.f90

  # error: error: Invalid CONVERT value
  record_marker_1.f90
  record_marker_3.f90
  unf_io_convert_1.f90
  unf_io_convert_2.f90
  unf_io_convert_3.f90

  # error: Implicit declaration of function has a different result type than in
  # previous declaration
  recursive_check_14.f90

  # error: Result of pure function may not have an impure FINAL subroutine
  finalize_51.f90

  # --------------------------------------------------------------------------
  #
  # These tests are skipped for a variety of reasons that don't fit well in
  # any of the previous categories

  # The file char_result_mod_19.f90 has the { dg-do run } annotation, but it is
  # not actually the main test file. That would be char_result_19.f90 which is
  # listed as a dependency of char_result_mod_19.f90. This seems to be
  # backwards.
  char_result_mod_19.f90

  # The test calls the subroutine should_not_fail(). The intention seems to be
  # for the call to should_not_fail() to be dead-code eliminated. It is guarded
  # by a conditional with a call to selected_real_kind() that should evaluate
  # to false at compile-time. This is not being eliminated resulting in an
  # "undefined symbol" error at link time.
  #
  selected_real_kind_2.f90

  # For some reason, when building these tests, LLVM-IR is generated instead of
  # of an object file.
  save_6.f90
  shape_9.f90

  # These tests seem to hang at runtime. Not sure if this indicates a problem
  # with flang or with the tests themselves.
  #
  # FIXME: This should be checked and this comment should either be updated to
  # reflect what the actual problem is with the tests or the tests should be
  # removed from this list.
  namelist_42.f90
  namelist_43.f90

  # --------------------------------------------------------------------------
  #
  # These tests are skipped because flang cannot parse these files. This could
  # be because of the use of non-standard syntax, but they will need to be
  # checked to be sure.
  #
  auto_in_equiv_1.f90
  auto_in_equiv_2.f90
  automatic_1.f90
  dec-comparison-character_1.f90
  dec-comparison-character_2.f90
  dec_exp_1.f90
  dec_format_empty_item_1.f
  dec_format_empty_item_2.f
  dec_io_1.f90
  dec_parameter_1.f
  dec_parameter_2.f90
  dec_static_1.f90
  dec_static_2.f90
  dec_structure_10.f90
  dec_structure_5.f90
  dec_structure_7.f90
  fmt_error_10.f
  fmt_error_9.f
  fmt_t_9.f
  substr_9.f90

  # --------------------------------------------------------------------------
  #
  # These tests are skipped because they cause flang to crash.

  # Assertion `ty.isa<fir::RecordType>()' failed
  c_assoc.f90
  c_f_pointer_complex.f03
  c_f_pointer_logical.f03
  c_f_pointer_shape_tests_2.f03
  c_f_pointer_shape_tests_4.f03
  deferred_character_8.f90
  equiv_7.f90
  iso_c_binding_rename_1.f03
  test_only_clause.f90
)

# These tests fail at runtime when they should pass. are likely a result of
# unimplemented features in the runtime, but they could also be bugs. If any
# will never pass with flang (if they use unsupported extensions for instance),
# they should be added to the Unsupported list. These are not enabled by default
# to ensure that the default configuration of the test suite does not fail.
# Tests should be removed from this list when the cause of their failure is
# addressed.
file(GLOB Failing CONFIGURE_DEPENDS
  Wall.f90
  Wno-all.f90
  abort_shouldfail.f90
  achar_6.F90
  advance_5.f90
  advance_6.f90
  aliasing_dummy_5.f90
  allocate_alloc_opt_15.f90
  allocate_alloc_opt_3.f90
  allocate_deferred_char_scalar_1.f03
  allocate_zerosize_3.f
  arrayio_1.f90
  arrayio_3.f90
  arrayio_5.f90
  arrayio_6.f90
  assign_2.f90
  auto_save_2.f90
  backslash_2.f90
  backslash_3.f
  backspace_2.f
  backspace_6.f
  bessel_7.f90
  bounds_check_19.f90
  boz_15.f90
  c_char_tests.f03
  char4_iunit_1.f03
  char4_iunit_2.f03
  check_bits_1.f90
  check_bits_2.f90
  continuation_12.f90
  continuation_13.f90
  continuation_1.f90
  cr_lf.f90
  cray_pointers_10.f90
  cray_pointers_5.f90
  cshift_bounds_3.f90
  cshift_bounds_4.f90
  cshift_large_1.f90
  data_char_1.f90
  data_char_3.f90
  deallocate_alloc_opt_3.f90
  deallocate_stat_2.f90
  deallocate_stat.f90
  dependency_45.f90
  dim_sum_1.f90
  dim_sum_2.f90
  dim_sum_3.f90
  direct_io_7.f90
  do_check_1.f90
  dollar_edit_descriptor_4.f
  elemental_dependency_1.f90
  endfile_3.f90
  eoshift_bounds_1.f90
  eoshift_large_1.f90
  error_format.f90
  error_stop_1.f08
  f2003_io_5.f03
  findloc_6.f90
  fmt_error_4.f90
  fmt_error_5.f90
  fmt_f_default_field_width_1.f90
  fmt_f_default_field_width_2.f90
  fmt_g0_1.f08
  fmt_g_default_field_width_1.f90
  fmt_g_default_field_width_2.f90
  fmt_g.f
  fmt_i_default_field_width_1.f90
  fmt_i_default_field_width_2.f90
  fmt_l.f90
  fmt_zero_width.f90
  fold_nearest.f90
  forall_12.f90
  goto_2.f90
  hollerith8.f90
  init_flag_1.f90
  init_flag_2.f90
  init_flag_3.f90
  init_flag_4.f90
  init_flag_5.f90
  init_flag_6.f90
  init_flag_7.f90
  init_flag_9.f90
  inline_matmul_15.f90
  inquire_13.f90
  inquire_15.f90
  inquire_5.f90
  inquire_9.f90
  inquire_internal.f90
  inquire_recl_f2018.f90
  inquire_size.f90
  integer_exponentiation_2.f90
  internal_dummy_2.f08
  internal_pack_3.f90
  internal_write_1.f90
  intrinsic_std_4.f90
  io_err_1.f90
  io_real_boz_3.f90
  io_real_boz.f90
  iostat_4.f90
  iostat_5.f90
  is_contiguous_3.f90
  large_real_kind_1.f90
  large_unit_1.f90
  list_directed_large.f90
  list_read_11.f90
  list_read_4.f90
  literal_character_constant_1_z.F
  masklr_2.F90
  matmul_5.f90
  matmul_bounds_11.f90
  matmul_bounds_13.f90
  matmul_bounds_15.f
  matmul_bounds_16.f
  matmul_bounds_7.f90
  matmul_bounds_9.f90
  maxloc_2.f90
  maxloc_bounds_3.f90
  maxloc_bounds_6.f90
  maxloc_string_1.f90
  maxlocval_2.f90
  maxlocval_4.f90
  merge_bits_2.F90
  minloc_1.f90
  minlocval_1.f90
  minlocval_4.f90
  minmaxloc_10.f90
  minmaxloc_1.f90
  minmaxloc_3.f90
  minval_char_1.f90
  minval_char_3.f90
  minval_parameter_1.f90
  missing_optional_dummy_6.f90
  mod_large_1.f90
  mod_sign0_1.f90
  module_nan.f90
  multiple_allocation_1.f90
  multiple_allocation_3.f90
  mvbits_4.f90
  namelist_18.f90
  namelist_19.f90
  namelist_21.f90
  namelist_22.f90
  namelist_24.f90
  namelist_37.f90
  namelist_38.f90
  namelist_41.f90
  namelist_51.f90
  namelist_56.f90
  namelist_57.f90
  namelist_61.f90
  namelist_65.f90
  namelist_72.f
  namelist_73.f90
  namelist_80.f90
  namelist_81.f90
  namelist_84.f90
  namelist_87.f90
  namelist_89.f90
  namelist_97.f90
  namelist_char_only.f90
  nan_2.f90
  nearest_1.f90
  nearest_3.f90
  negative_unit.f
  negative_unit_int8.f
  no_range_check_1.f90
  norm2_1.f90
  nosigned_zero_2.f90
  open_access_append_2.f90
  open_errors_2.f90
  open_errors_3.f90
  open_negative_unit_1.f90
  open_new_segv.f90
  open_status_2.f90
  pad_source_3.f
  pad_source_4.f
  pad_source_5.f
  pointer_check_6.f90
  pr12884.f
  pr17285.f90
  pr17286.f90
  pr17706.f90
  pr18210.f90
  pr19657.f
  pr47757-3.f90
  pr47878.f90
  pr50069_1.f90
  pr59700.f90
  pr71523_2.f90
  pr96436_3.f90
  pr96436_4.f90
  pr96436_5.f90
  promotion_3.f90
  promotion_4.f90
  promotion.f90
  random_3.f90
  random_5.f90
  random_init_2.f90
  read_5.f90
  read_bang4.f90
  read_bang.f90
  read_comma.f
  read_eof_3.f90
  read_eof_7.f90
  read_eof_all.f90
  read_legacy_comma.f90
  real4-10-real8-10.f90
  real4-10-real8-16.f90
  real4-10-real8-4.f90
  real4-10.f90
  real4-16-real8-10.f90
  real4-16-real8-16.f90
  real4-16-real8-4.f90
  real4-16.f90
  real4-8-real8-10.f90
  real4-8-real8-16.f90
  real4-8-real8-4.f90
  real4-8.f90
  real8-10.f90
  real8-16.f90
  real8-4.f90
  real_const_3.f90
  realloc_on_assign_11.f90
  recursive_check_7.f90
  repeat_1.f90
  reshape_order_1.f90
  reshape_order_2.f90
  reshape_order_3.f90
  reshape_order_4.f90
  round_3.f08
  selected_kind_1.f90
  short_circuiting_3.f90
  stop_shouldfail.f90
  streamio_11.f90
  streamio_13.f90
  streamio_17.f90
  streamio_4.f90
  system_clock_3.f08
  unf_io_convert_4.f90
  unf_read_corrupted_1.f90
  unf_short_record_1.f90
  unformatted_subrecord_1.f90
  unpack_bounds_2.f90
  unpack_bounds_3.f90
  utf8_1.f03
  utf8_2.f03
  widechar_5.f90
  widechar_8.f90
  widechar_IO_4.f90
  widechar_intrinsics_4.f90
  widechar_intrinsics_5.f90
  widechar_intrinsics_8.f90
  write_check.f90
  zero_sized_1.f90

  # These tests fail at runtime on AArch64 (but pass on x86). Disable them
  # anyway so the test-suite passes by default on AArch64.
  entry_23.f
  findloc_8.f90

  # These tests have race conditions with other tests that cause them to
  # occasionally fail when run in parallel. Every test in each group listed
  # below has a race condition with at least one other test in the group.

  # <group> Tests read/write/replace/delete file named 'tmp.dat'
  pr88169_1.f90
  pr88169_2.f90
  pr88169_3.f90
  list_read_6.f90
  # </group>

  # <group>
  write_rewind_1.f
  write_rewind_2.f
  # </group>

  # <group> Tests read/delete/append file named 'foo'
  append_1.f90
  large_unit_2.f90
  open_access_append_1.f90
  open_status_1.f90
  # </group>

  # <group> Tests create/replace file named 'test.dat'
  direct_io_12.f90
  endfile.f90
  eof_4.f90
  implied_do_io_1.f90
  list_read_7.f90
  namelist_76.f90
  read_eof_8.f90
  read_eof_all.f90
  streamio_18.f90
  # </group>
)

list(APPEND UnsupportedTests "${Unsupported}")
list(APPEND UnimplementedTests "${Unimplemented}")
list(APPEND SkippedTests "${Skipped}")
list(APPEND FailingTests "${Failing}")

# add_tests will find all files with known Fortran extensions, pick out the ones
# that correspond to the "main" file of the test and filter out the tests that
# are in TestsToSkip.
add_tests("${UnsupportedTests}" "${UnimplementedTests}" "${SkippedTests}" "${FailingTests}")

add_subdirectory(analyzer)
add_subdirectory(asan)
add_subdirectory(c-interop)
add_subdirectory(coarray)
add_subdirectory(debug)
add_subdirectory(g77)
add_subdirectory(goacc)
add_subdirectory(goacc-gomp)
add_subdirectory(gomp)
add_subdirectory(graphite)
add_subdirectory(guality)
add_subdirectory(ieee)
add_subdirectory(prof)
add_subdirectory(lto)
add_subdirectory(ubsan)
add_subdirectory(vect)

file(COPY lit.local.cfg DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")
