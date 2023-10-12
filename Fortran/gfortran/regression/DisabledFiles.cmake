#===------------------------------------------------------------------------===#
#
# Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
# See https://llvm.org/LICENSE.txt for license information.
# SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
#
#===------------------------------------------------------------------------===#

# Some tests in the suite use non-standard features that are supported in
# gfortran but are not (and might never be) supported by flang. But if they are,
# they should be moved out of here.
file(GLOB UNSUPPORTED_FILES CONFIGURE_DEPENDS
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

  # ---------------------------------------------------------------------------
  #
  # This test emits diagnostics in JSON format and checks the resulting JSON
  # diagnostic output.
  diagnostic-format-json-1.F90

  # "automatic" attribute extension not supported in parser
  auto_in_equiv_3.f90
  auto_in_equiv_7.f90
  # "static" attribute extension not supported in parser
  auto_in_equiv_6.f90
  # BESJ0 intrinsic function extension not supported
  bessel_2.f90
  # COMPLEX intrinsic function extension not supported (standard is CMPLX)
  boz_complex_2.f90
  # BOZ not allowed in FLOAT intrinsic function extension (which is supported) -- would be easy to add
  boz_float_2.f90
  # THIS_IMAGE(DISTANCE=), NUM_IMAGES(DISTANCE=), and NUM_IMAGES(FAILED=) extensions not supported
  coarray_this_image_1.f90
  coarray_this_image_2.f90
  # f18 requires extension Cray pointee to be a sequence type if derived
  cray_pointers_11.f90
  # Unimplemented in extension: assumed-size Cray pointee
  cray_pointers_6.f90
  # Unimplemented in extension: Cray pointer to function
  cray_pointers_9.f90
  # DEC "typed" bit intrinsics: BBTEST, BITEST, FLOATI, FLOATJ, BIEOR, &c.
  dec_intrinsic_ints.f90
  # COTAN extension intrinsic
  dec_math_4.f90
  # DEC old-style PARAMETER statement without parentheses
  dec_parameter_3.f90
  # TYPE statement as a synonym for PRINT
  dec_type_print.f90
  # Unsupported extension intrinsic procedures for POSIX APIs (chdir, symlnk, getpid, &c)
  g77_intrinsics_sub.f
  noreturn-3.f90
  # Unsupported: assignment of Hollerith to numeric (b = 4habcd), Hollerith in DATA for numeric, &c.
  hollerith5.f90
  hollerith_legacy.f90
  # Unsupported REALPART and IMAGPART extension intrinsic functions
  imag_1.f
  initialization_29.f90
  # Unsupported ETIME intrinsic procedure
  intrinsic_8.f90
  # Unsupported SIGNAL intrinsic procedure
  intrinsic_signal.f90
  # Unsupported directive !GCC$ attributes NO_ARG_CHECK :: buf   leads to semantic errors
  no_arg_check_1.f90
  no_arg_check_2.f90
  # Unsupported directive syntax  !dir$ unroll(2)
  pr88148.f90
  pr91496.f90
  # Unsupported extension: using .NOT., .OR., &c. on INTEGER
  pr88228.f90
  # Unsupported extension: BOZ output list item
  pr91650_2.f90
  # Unsupoorted extension: PRINT NAMELIST_NAME
  print_fmt_3.f
  # Unsupported extension intrinsic functions DACOSH, ZCOS, &c.
  specifics_2.f90
  # Unsupported predefined macro: __TIMESTAMP__
  wdate-time.F90
)

# These tests are skipped because they hit a 'not yet implemented' assertion
# in flang and thus fail to compile. They should be removed from here when the
# corresponding feature is implemented. Eventually, this variable should be
# removed altogether once all the missing features are implemented.
file(GLOB UNIMPLEMENTED_FILES CONFIGURE_DEPENDS
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
  PR95352.f90
  PR96726.f90
  PR96727.f90
  PR96728.f90
  PR97046.f90
  assumed_rank_11.f90
  assumed_rank_12.f90
  assumed_rank_18.f90
  assumed_rank_19.f90
  assumed_rank_20.f90
  assumed_rank_5.f90
  assumed_type_9.f90
  bind-c-contiguous-2.f90
  interface_49.f90
  is_contiguous_2.f90
  pr103366.f90
  pr84088.f90
  pr88932.f90
  pr92277.f90
  pr95828.f90
  select_rank_5.f90
  sizeof_4.f90
  sizeof_6.f90

  # unimplemented: ASYNCHRONOUS in procedure interface
  assumed_rank_13.f90
  asynchronous_3.f03

  # unimplemented: assumed type in actual argument
  altreturn_10.f90

  # unimplemented: procedure pointers
  associated_target_8.f90
  block_11.f90
  c_f_pointer_tests_3.f90
  c_funloc_tests_7.f90
  compiler-directive_1.f90
  dec_structure_15.f90
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
  pr66465.f90
  pr78719_1.f90
  pr99602a.f90
  pr99602.f90
  proc_decl_23.f90
  proc_ptr_1.f90
  proc_ptr_13.f90
  proc_ptr_16.f90
  proc_ptr_18.f90
  proc_ptr_21.f90
  proc_ptr_22.f90
  proc_ptr_23.f90
  proc_ptr_25.f90
  proc_ptr_26.f90
  proc_ptr_27.f90
  proc_ptr_28.f90
  proc_ptr_3.f90
  proc_ptr_30.f90
  proc_ptr_31.f90
  proc_ptr_34.f90
  proc_ptr_39.f90
  proc_ptr_42.f90
  proc_ptr_43.f90
  proc_ptr_45.f90
  proc_ptr_5.f90
  proc_ptr_51.f90
  proc_ptr_comp_10.f90
  proc_ptr_comp_8.f90
  proc_ptr_comp_9.f90
  proc_ptr_result_3.f90
  recursive_check_4.f03
  recursive_check_5.f03
  recursive_check_6.f03
  stmt_func_1.f90
  warn_unused_function_3.f90

  # unimplemented: procedure pointer arguments
  internal_pack_17.f90
  module_private_2.f90
  pr69603.f90
  proc_ptr_10.f90
  proc_ptr_19.f90
  proc_ptr_20.f90
  proc_ptr_29.f90
  proc_ptr_36.f90
  proc_ptr_6.f90
  proc_ptr_7.f90
  proc_ptr_9.f90
  proc_ptr_comp_2.f90
  submodule_30.f08

  # unimplemented: procedure components
  assignment_4.f90
  deferred_type_proc_pointer_1.f90
  deferred_type_proc_pointer_2.f90
  pr82253.f90
  proc_ptr_24.f90
  proc_ptr_48.f90
  proc_ptr_comp_1.f90
  proc_ptr_comp_11.f90
  proc_ptr_comp_13.f90
  proc_ptr_comp_14.f90
  proc_ptr_comp_18.f90
  proc_ptr_comp_19.f90
  proc_ptr_comp_21.f90
  proc_ptr_comp_24.f90
  proc_ptr_comp_26.f90
  proc_ptr_comp_27.f90
  proc_ptr_comp_28.f90
  proc_ptr_comp_29.f90
  proc_ptr_comp_32.f90
  proc_ptr_comp_33.f90
  proc_ptr_comp_34.f90
  proc_ptr_comp_40.f90
  proc_ptr_comp_44.f90
  proc_ptr_comp_4.f90
  proc_ptr_comp_5.f90
  proc_ptr_comp_51.f90
  proc_ptr_comp_52.f90
  proc_ptr_comp_7.f90
  structure_constructor_11.f90

  # unimplemented: procedure pointer results
  pointer_check_5.f90
  pr39695_1.f90
  pr63797.f90
  pr78739.f90
  proc_ptr_12.f90
  proc_ptr_41.f90
  proc_ptr_49.f90
  proc_ptr_result_4.f90
  proc_ptr_result_7.f90

  # unimplemented: support for polymorphic types.
  ISO_Fortran_binding_17.f90
  PR100120.f90
  PR100245.f90
  PR95331.f90
  alloc_comp_deep_copy_1.f03
  allocate_alloc_opt_12.f90
  allocate_alloc_opt_13.f90
  allocate_alloc_opt_8.f90
  allocate_class_4.f90
  allocate_derived_2.f90
  allocate_derived_3.f90
  allocate_with_mold_2.f90
  allocate_with_mold_4.f90
  allocate_with_source_18.f03
  allocate_with_source_13.f03
  allocate_with_source_14.f03
  allocate_with_source_17.f03
  allocate_with_source_21.f03
  allocate_with_source_25.f90
  allocate_with_source_8.f08
  associate_18.f08
  associate_20.f03
  associate_8.f03
  alloc_comp_class_2.f90
  allocate_alloc_opt_10.f90
  allocate_with_source_26.f90
  associate_12.f90
  associate_13.f90
  associate_14.f90
  associate_16.f90
  associate_40.f90
  associate_48.f90
  associate_52.f90
  associated_6.f90
  associated_target_4.f90
  assumed_type_10.f90
  assumed_type_11.f90
  assumed_type_16.f90
  assumed_type_17.f90
  assumed_type_1.f90
  assumed_type_2.f90
  assumed_type_4.f90
  assumed_type_7.f90
  auto_dealloc_1.f90
  auto_dealloc_2.f90
  bind_c_array_params_2.f90
  c_assoc_5.f90
  c_f_pointer_tests_5.f90
  character_workout_1.f90
  character_workout_4.f90
  class_1.f03
  class_10.f03
  class_11.f03
  class_12.f03
  class_13.f03
  class_14.f03
  class_15.f03
  class_16.f03
  class_18.f03
  class_21.f03
  class_22.f03
  class_23.f03
  class_26.f03
  class_27.f03
  class_28.f03
  class_29.f03
  class_32.f90
  class_33.f90
  class_34.f90
  class_35.f90
  class_37.f03
  class_3.f03
  class_41.f03
  class_42.f03
  class_44.f03
  class_45a.f03
  class_47.f90
  class_48.f90
  class_46.f03
  class_51.f90
  class_52.f90
  class_54.f90
  class_6.f03
  class_62.f90
  class_63.f90
  class_64.f90
  class_66.f90
  class_68.f90
  class_allocate_1.f03
  class_allocate_13.f90
  class_allocate_16.f90
  class_allocate_17.f90
  class_allocate_18.f90
  class_allocate_19.f03
  class_allocate_21.f90
  class_allocate_22.f90
  class_allocate_23.f08
  class_allocate_24.f90
  class_allocate_25.f90
  class_allocate_3.f03
  class_allocate_4.f03
  class_allocate_5.f90
  class_allocate_6.f03
  class_array_1.f03
  class_array_15.f03
  class_array_10.f03
  class_array_11.f03
  class_array_12.f03
  class_array_14.f90
  class_array_17.f90
  class_array_18.f90
  class_array_19.f90
  class_array_2.f03
  class_array_20.f03
  class_array_22.f03
  class_array_3.f03
  class_array_5.f03
  class_array_6.f03
  class_array_8.f03
  class_assign_2.f90
  class_assign_3.f90
  class_dummy_1.f03
  class_dummy_8.f90
  class_dummy_9.f90
  class_nameclash.f90
  class_result_2.f90
  class_result_3.f90
  class_result_5.f90
  class_result_6.f90
  class_result_7.f90
  class_result_8.f90
  class_to_type_1.f03
  class_to_type_4.f90
  coarray_31.f90
  coarray_allocate_2.f08
  coarray_allocate_3.f08
  coarray_allocate_5.f08
  coarray_class_1.f90
  coarray_lib_alloc_2.f90
  coarray_lib_alloc_3.f90
  coarray_poly_5.f90
  contiguous_5.f90
  default_initialization_6.f90
  deferred_character_20.f90
  deferred_character_29.f90
  deferred_type_param_3.f90
  defined_assignment_6.f90
  defined_assignment_7.f90
  defined_assignment_8.f90
  dependency_53.f90
  dependency_56.f90
  dependency_57.f90
  dependency_60.f90
  der_io_5.f90
  derived_init_6.f90
  do_check_15.f90
  dtio_20.f03
  dtio_23.f90
  dtio_29.f03
  dtio_35.f90
  dummy_procedure_4.f90
  dynamic_dispatch_10.f03
  elemental_function_5.f90
  elemental_optional_args_5.f03
  extends_9.f03
  extends_type_of_3.f90
  exit_3.f08
  extends_type_of_1.f03
  extends_type_of_2.f03
  finalize_10.f90
  finalize_14.f90
  finalize_16.f90
  finalize_18.f90
  finalize_21.f90
  finalize_23.f90
  finalize_28.f90
  finalize_37.f90
  generic_22.f03
  generic_33.f90
  implicit_class_1.f90
  init_flag_19.f03
  inline_matmul_25.f90
  intent_out_7.f90
  interface_32.f90
  interface_41.f90
  move_alloc_12.f90
  move_alloc_13.f90
  move_alloc_14.f90
  move_alloc_2.f90
  move_alloc_5.f90
  move_alloc_7.f90
  namelist_91.f90
  null_10.f90
  pointer_check_7.f90
  pointer_check_8.f90
  pointer_array_5.f90
  pointer_array_8.f90
  pointer_array_component_3.f90
  pointer_check_14.f90
  pointer_intent_4.f90
  pr100551.f90
  pr100949.f90
  pr105501.f90
  pr108010.f90
  pr109209.f90
  pr42051.f03
  pr48958.f90
  pr57904.f90
  pr57987.f90
  pr61960.f90
  pr63331.f90
  pr64589.f90
  pr64980.f03
  pr68864.f90
  pr71047.f08
  pr78092.f90
  pr86328.f90
  pr86760.f90
  pr87992.f90
  pr88379.f90
  pr93473.f90
  pr93601.f90
  pr94397.F90
  pr95687.f90
  pr95829.f90
  pr99112.f90
  pr99545.f90
  pr99602c.f90
  pr99602d.f90
  proc_ptr_52.f90
  proc_ptr_50.f90
  proc_ptr_comp_49.f90
  proc_ptr_comp_50.f90
  proc_ptr_comp_pass_3.f90
  proc_ptr_comp_pass_6.f90
  ptr_func_assign_2.f08
  realloc_on_assign_20.f90
  realloc_on_assign_21.f90
  realloc_on_assign_27.f08
  realloc_on_assign_31.f90
  same_type_as_2.f03
  scalar_pointer_1.f90
  select_type_10.f03
  select_type_12.f03
  select_type_13.f03
  select_type_14.f03
  select_type_16.f03
  select_type_17.f03
  select_type_18.f03
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
  select_type_40.f90
  select_type_41.f90
  select_type_42.f90
  select_type_44.f90
  select_type_45.f90
  select_type_46.f90
  select_type_47.f90
  select_type_48.f90
  select_type_49.f90
  select_type_50.f90
  sizeof_5.f90
  storage_size_1.f08
  storage_size_3.f08
  storage_size_5.f90
  structure_constructor_13.f03
  temporary_2.f90
  transfer_class_1.f90
  transfer_class_3.f90
  type_to_class_1.f03
  type_to_class_2.f03
  type_to_class_3.f03
  type_to_class_5.f03
  typebound_assignment_1.f03
  typebound_assignment_2.f03
  typebound_assignment_3.f03
  typebound_assignment_4.f90
  typebound_assignment_5.f03
  typebound_assignment_6a.f03
  typebound_assignment_8.f90
  typebound_call_11.f03
  typebound_call_12.f03
  typebound_call_14.f03
  typebound_call_16.f03
  typebound_call_21.f03
  typebound_call_22.f03
  typebound_call_23.f03
  typebound_call_26.f90
  typebound_call_27.f90
  typebound_call_28.f90
  typebound_call_30.f90
  typebound_deferred_1.f90
  typebound_generic_14.f03
  typebound_generic_7.f03
  typebound_generic_8.f03
  typebound_operator_11.f90
  typebound_operator_17.f90
  typebound_operator_18.f90
  typebound_operator_19.f90
  typebound_operator_1.f03
  typebound_operator_5.f03
  typebound_proc_14.f03
  typebound_proc_15.f03
  typebound_proc_16.f03
  typebound_proc_17.f03
  typebound_proc_18.f03
  typebound_proc_1.f08
  typebound_proc_21.f90
  typebound_proc_24.f03
  typebound_proc_25.f90
  typebound_proc_30.f90
  typebound_proc_31.f90
  typebound_proc_32.f90
  typebound_proc_33.f90
  unlimited_polymorphic_11.f90
  unlimited_polymorphic_12.f90
  unlimited_polymorphic_15.f90
  unlimited_polymorphic_16.f90
  unlimited_polymorphic_14.f90
  unlimited_polymorphic_17.f90
  unlimited_polymorphic_20.f90
  unlimited_polymorphic_21.f90
  unlimited_polymorphic_22.f90
  unlimited_polymorphic_24.f03
  unlimited_polymorphic_25.f03
  unlimited_polymorphic_3.f03
  unlimited_polymorphic_30.f03
  unlimited_polymorphic_32.f90
  unlimited_polymorphic_32.f03
  unlimited_polymorphic_5.f90
  unlimited_polymorphic_6.f90
  unlimited_polymorphic_7.f90
  unlimited_polymorphic_8.f90
  unresolved_fixup_1.f90
  use_20.f90
  use_21.f90
  use_26.f90
  warn_conversion_11.f90
  whole_file_27.f90

  # unimplemented: BIND (C) internal procedure.
  ISO_Fortran_binding_19.f90
  PR93308.f90
  array_reference_3.f90
  bind_c_char_2.f90
  bind_c_char_3.f90
  bind_c_char_4.f90
  bind_c_char_5.f90
  internal_dummy_4.f08

  # unimplemented: BIND(C) internal procedures:
  bind-c-char-descr.f90
  bind_c_usage_11.f03
  bind_c_usage_9.f03
  init_flag_16.f03
  null_actual_2.f90

  # unimplemented: BIND(C) module variable linkage
  bind_c_dts.f90
  bind_c_vars.f90
  bind_c_dts_4.f03
  bind_c_implicit_vars.f03
  bind_c_usage_25.f90
  binding_label_tests_10.f03
  binding_label_tests_13.f03
  binding_label_tests_7.f03
  c_kind_tests_2.f03
  global_vars_c_init.f90
  kind_tests_2.f03
  kind_tests_3.f03
  implicit_pure_5.f90
  proc_ptr_8.f90
  public_private_module_2.f90
  sizeof_3.f90

  # unimplemented: character array expression temp with dynamic length.
  actual_array_constructor_2.f90
  array_constructor_17.f90
  associate_35.f90
  assumed_charlen_arg_1.f90
  assumed_charlen_sharing.f90
  char_cons_len.f90
  char_length_13.f90
  char_length_23.f90
  char_length_7.f90
  char_result_13.f90
  deferred_character_36.f90
  mapping_3.f90
  pr77506.f90
  pr91862.f90
  transfer_resolve_1.f90

  # unimplemented: allocatable component in structure constructor
  alloc_comp_constructor_7.f90
  alloc_comp_init_expr.f03
  structure_constructor_17.f90

  # unimplemented: allocatable components in derived type assignment
  alloc_comp_result_2.f90
  generic_30.f90
  pr50769.f90
  realloc_on_assign_16a.f90

  # unimplemented: gather rhs LEN parameters in assignment to allocatable
  allocate_assumed_charlen_4.f90
  allocate_error_5.f90
  associate_58.f90
  bounds_check_22.f90
  char_length_20.f90
  char_length_21.f90
  deferred_character_1.f90
  deferred_character_14.f90
  deferred_character_2.f90
  deferred_character_21.f90
  deferred_character_22.f90
  deferred_character_27.f90
  deferred_character_34.f90
  deferred_character_4.f90
  deferred_character_7.f90
  dependency_50.f90
  dependency_51.f90
  elemental_function_3.f90
  elemental_function_2.f90
  realloc_on_assign_14.f90
  widechar_11.f90

  # unimplemented: passing dynamically optional argument to elemental procedures
  bounds_check_9.f90
  bounds_check_fail_2.f90
  elemental_optional_args_1.f90
  elemental_optional_args_2.f90
  elemental_optional_args_3.f90
  elemental_optional_args_4.f90
  elemental_optional_args_6.f90
  elemental_optional_args_7.f90
  generic_31.f90
  optional_absent_2.f90
  pr95446.f90

  # unimplemented: io-control-spec contains a reference to a non-integer,
  # non-scalar, or non-variable
  assign_8.f90
  fmt_nonchar_3.f90
  typebound_proc_29.f90
  write_invalid_format.f90

  # unimplemented: BOZ
  boz_bge.f90
  boz_8.f90
  nan_4.f90

  # unimplemented: coarray address
  coarray_38.f90
  coarray_39.f90
  coarray_dependency_1.f90

  # unimplemented: coarray allocation
  associate_26a.f90
  associate_26.f90
  associate_37.f90
  coarray_12.f90
  coarray_19.f90
  coarray_25.f90
  coarray_30.f90
  coarray_alloc_with_implicit_sync_1.f90
  coarray_alloc_with_implicit_sync_2.f90
  coarray_lib_alloc_1.f90
  coarray_lib_token_3.f90
  coarray_lock_4.f90
  coarray_lock_7.f90
  coarray_poly_4.f90

  # unimplemented: coarray in procedure interface
  coarray_29_1.f90
  coarray_32.f90
  coarray_36.f
  coarray_37.f90
  coarray_45.f90
  coarray_allocate_4.f08
  coarray_class_2.f90
  coarray_lib_move_alloc_1.f90
  coarray_lib_this_image_1.f90
  coarray_lib_this_image_2.f90
  coarray_poly_6.f90
  coarray_poly_7.f90
  coarray_poly_8.f90
  class_optional_1.f90
  class_optional_2.f90
  coarray_41.f90
  submodule_26.f08

  # unimplemented: coarray reference
  coarray_lib_comm_1.f90

  # unimplemented: co_max
  coarray_collectives_3.f90
  coarray_collectives_4.f90
  coarray_collectives_5.f90
  coarray_collectives_6.f90

  # unimplemented: CriticalConstruct implementation
  coarray_2.f90
  coarray_critical_1.f90

  # unimplemented: LOCK runtime
  coarray_lock_1.f90
  coarray_lock_2.f90
  coarray_lock_6.f90

  # unimplemented: SYNC ALL runtime
  coarray_9.f90

  # unimplemented: SYNC IMAGES
  pr71706.f90

  # unimplemented: SYNC MEMORY
  coarray_sync_memory.f90

  # unimplemented: intrinsic: atan
  atan2_1.f90

  # unimplemented: intrinsic: co_broadcast
  coarray_collectives_17.f90

  # unimplemented: intrinsic: erfc_scaled
  erfc_scaled_1.f90
  erf_2.F90
  erf_3.F90

  # unimplemented: intrinsic: execute_command_line
  execute_command_line_1.f90
  execute_command_line_2.f90
  execute_command_line_3.f90

  # unimplemented: intrinsic: failed_images
  coarray_failed_images_1.f08

  # unimplemented: intrinsic: image_status
  coarray_image_status_1.f08

  # unimplemented: intrinsic: min and max for CHARACTER
  minmax_char_1.f90
  widechar_intrinsics_9.f90
  zero_length_2.f90

  # unimplemented: intrinsic: num_images
  coarray_allocate_1.f90
  coarray_collectives_12.f90
  pr96737.f90

  # unimplemented: intrinsic: selected_char_kind
  selected_char_kind_1.f90
  selected_char_kind_4.f90

  # unimplemented: intrinsic: sind
  dec_math_2.f90

  # unimplemented: intrinsic: stopped_images
  coarray_stopped_images_1.f08

  # unimplemented: intrinsic: this_image
  coarray_40.f90
  coarray_43.f90
  coarray_collectives_18.f90
  coarray_fail_18.f90
  coarray_fail_st.f90
  coarray_stat_2.f90
  coarray_stat_function.f90
  coarray_stat_whitespace.f90
  co_reduce_1.f90
  pr84784.f90
  random_init_3.f90
  random_init_4.f90
  random_init_5.f90
  random_init_6.f90

  # unimplemented: %VAL() intrinsic for arguments
  c_by_val_1.f
  c_by_val_2.f90
  c_by_val_3.f90
  c_by_val_4.f
  c_by_val_5.f90
  pointer_check_12.f90

  # unimplemented: parameterized derived types
  dec_type_print_2.f03
  pdt_1.f03
  pdt_10.f03
  pdt_15.f03
  pdt_19.f03
  pdt_22.f03
  pdt_25.f03
  pdt_7.f03
  pdt_9.f03
  pr95826.f90

  # unimplemented: host associated derived type with length parameters
  pdt_31.f03

  # unimplemented: derived type components with non default lower bounds
  structure_constructor_1.f03
  vax_structure_1.f90
  whole_file_11.f90

  # unimplemented: derived type specification expression is neither constant nor
  # a length type parameter
  pr95882_1.f90

  # unimplemented: asynchronous transfers not implemented in runtime
  asynchronous_5.f03
  f2003_inquire_1.f03
  f2003_io_1.f03
  f2003_io_2.f03

  # unimplemented: support for UNION
  dec_init_1.f90
  dec_init_3.f90
  dec_init_4.f90
  dec_structure_13.f90
  dec_structure_16.f90
  dec_structure_22.f90
  dec_union_1.f90
  dec_union_10.f90
  dec_union_11.f90
  dec_union_12.f90
  dec_union_2.f90
  dec_union_3.f90
  dec_union_4.f90
  dec_union_5.f90
  dec_union_6.f90
  dec_union_8.f90
  dec_union_9.f90
  pr78259.f90

  # unimplemented: VOLATILE in procedure interface
  volatile12.f90
  volatile8.f90

  # unimplemented: assignment to pointer result of function reference
  ptr-func-3.f90
  ptr_func_assign_5.f08

  # unimplemented: deep copy on allocatable members
  alloc_comp_auto_array_3.f90

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
file(GLOB SKIPPED_FILES CONFIGURE_DEPENDS
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
  char_cast_2.f90
  c_char_tests_4.f90
  c_char_tests_5.f90
  widechar_6.f90
  widechar_intrinsics_2.f90
  widechar_intrinsics_3.f90
  widechar_intrinsics_6.f90
  widechar_intrinsics_7.f90
  widechar_select_1.f90

  # error: 'llvm.mlir.constant' op expected array type of 4294967300 i8 elements
  # for the string constant:
  string_1.f90

  # error: pointer not a MutableBoxValue:
  associated_7.f90

  # error: symbol is not mapped to any IR value:
  array_constructor_21.f90
  where_operator_assign_2.f90

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
  # in a single file, each distinct error message will be provided.

  # error: Entity in ALLOCATE statement must have the ALLOCATABLE or POINTER
  # attribute
  ISO_Fortran_binding_15.f90

  # error: Left-hand side of assignment may not be polymorphic unless
  # assignment is to an entire allocatable
  PR100040.f90
  PR100103.f90

  # error: The left-hand side of a pointer assignment is not definable
  PR100094.f90

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

  # error: COMMON block was not lowered before its usage
  common_18.f90
  test_common_binding_labels.f03

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

  # --------------------------------------------------------------------------
  #
  # These tests are skipped because they cause flang to hang - possibly in an
  # infinite loop.

  pr49540-1.f90 # Only on AArch64

  # --------------------------------------------------------------------------
  #
  # These tests are skipped because REAL(10) is not supported on AAch64.

  pr91497.f90

  # --------------------------------------------------------------------------
  #
  # These are skipped almost certainly because of a bug in the way multi-file
  # compile tests are built by the test-suite. This almost certainly has nothing
  # to do with flang, but they will be skipped until the test suite build
  # scripts are fixed.

  altreturn_9_0.f90
  bind_c_array_params_3.f90
  bind_c_usage_17.f90
  class_4a.f03
  deferred_character_33.f90
  enum_10.f90
  f2c_5.f90
  global_vars_f90_init.f90
  lrshift_1.f90
  matmul_blas_1.f
  matmul_bounds_14.f
  mixed_io_1.f90
  namelist_83.f90
  pr37287-1.f90
  pr77420_3.f90
  pr83149_1.f90
  pr83149_b.f90
  pr93524.f90
  public_private_module_3.f90
  static_linking_1.f
)

# These tests are disabled because they fail when they are expected to pass.
file(GLOB FAILING_FILES CONFIGURE_DEPENDS
  # ---------------------------------------------------------------------------
  #
  # These tests fail at runtime when they should pass. are likely a result of
  # unimplemented features in the runtime, but they could also be bugs. If any
  # will never pass with flang (if they use unsupported extensions for instance),
  # they should be added to the Unsupported list.

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

  # ---------------------------------------------------------------------------
  #
  # This test fails with optimizations enabled, but succeeds when compiled
  # without optimizations.
  inline_transpose_1.f90

  # These tests fail at runtime on AArch64 (but pass on x86). Disable them
  # anyway so the test-suite passes by default on AArch64.
  entry_23.f
  findloc_8.f90

  # ---------------------------------------------------------------------------
  #
  # Compilation of these tests is expected to fail, but it succeeds instead.

  # Tests that exercise gfortran's ability to set -std=f95 and then see errors on newer features
  abstract_type_1.f90
  alloc_comp_constraint_7.f90
  alloc_comp_std.f90
  allocatable_scalar_2.f90
  allocate_alloc_opt_5.f90
  argument_checking_14.f90
  argument_checking_2.f90
  array_constructor_38.f90
  array_constructor_type_13.f90
  assign_3.f90
  associate_2.f95
  asynchronous_2.f90
  block_3.f90
  blockdata_5.f90
  blockdata_6.f90
  boz_10.f90
  boz_7.f90
  byte_1.f90
  common_19.f90
  common_9.f90
  constructor_4.f90
  constructor_7.f90
  dup_save_2.f90
  equiv_constraint_1.f90
  equiv_constraint_2.f90
  finalize_6.f90
  fmt_error_8.f
  fmt_g0_3.f08
  implied_shape_2.f90
  import2.f90
  initialization_13.f90
  initialization_16.f90
  initialization_30.f90
  initialization_4.f90
  inquire_iolength.f90
  interface_15.f90
  interface_abstract_2.f90
  intrinsic_param_1.f90
  intrinsic_std_1.f90
  io_constraints_10.f90
  io_constraints_11.f90
  iostat_3.f90
  logint_2.f
  minmax_char_2.f90
  module_procedure_double_colon_2.f90
  namelist_34.f90
  namelist_35.f90
  namelist_3.f90
  namelist_5.f90
  namelist_63.f90
  namelist_assumed_char.f90
  newunit_2.f90
  pointer_assign_6.f90
  pointer_intent_2.f90
  pointer_remapping_1.f90
  pr107423.f90
  pr77978_1.f90
  pr95373_1.f90
  private_type_10.f90
  private_type_12.f90
  private_type_1.f90
  private_type_2.f90
  private_type_4.f90
  private_type_9.f90
  proc_decl_4.f90
  protected_3.f90
  selected_char_kind_3.f90
  spread_init_expr_2.f90
  structure_constructor_9.f90
  system_clock_2.f90
  use_6.f90
  used_before_typed_4.f90
  value_2.f90
  volatile2.f90
  warning-directive-2.F90
  warnings_are_errors_1.f90

  # -std=f2003 tests to detect Fortran 2008 features
  bessel_3.f90
  bind_c_array_params.f03
  bind_c_bool_1.f90
  binding_label_tests_20.f90
  c_funloc_tests_5.f03
  c_kind_int128_test1.f03
  c_loc_test_19.f90
  c_loc_test_21.f90
  c_loc_tests_10.f03
  c_loc_tests_4.f03
  c_sizeof_2.f90
  char_length_1.f90
  coarray_5.f90
  common_20.f90
  complex_intrinsic_4.f90
  complex_intrinsic_6.f90
  contains_empty_1.f03
  contains.f90
  contiguous_2.f90
  finalize_2.f03
  generic_26.f90
  iall_iany_iparity_2.f90
  intrinsic_std_5.f03
  io_constraints_12.f90
  module_procedure_double_colon_3.f90
  norm2_4.f90
  parity_3.f90
  pointer_remapping_2.f03
  pointer_target_2.f90
  pr95373_2.f90
  ptr-func-2.f90
  pure_formal_2.f90
  rank_2.f90
  type_decl_2.f90
  typebound_proc_3.f03

  # -std=f2008 tests to detect Fortran 2018 features
  bind_c_usage_28.f90
  c_loc_tests_11.f03
  coarray_collectives_2.f90
  implicit_14.f90
  pr90290.f90
  pr91564.f90
  rank_3.f90

  # Tests that use -std=... to enable checks that no longer apply in modern Fortran.
  # Module variable with derived type default initialization requires explicit SAVE
  default_initialization_1.f90
  save_4.f90
  # ERROR STOP in pure procedure
  error_stop_4.f90
  # EXIT outside DO
  exit_5.f03
  # New features in ISO_FORTRAN_ENV & ISO_C_BINDING
  iso_c_binding_compiler_2.f90
  iso_c_binding_param_1.f90
  iso_fortran_env_6.f90

  # Tests that are not errors, and compile just fine with flang
  constant_shape.f90
  continuation_2.f90
  equiv_pure.f90 # gfortran's error is inappropriate for this test
  finalize_9.f90
  func_decl_3.f90
  initialization_20.f90
  initialization_24.f90
  interface_7.f90
  intrinsic_short-long.f90
  parameter_array_init_6.f90
  pr19936_1.f90 # ac-do-variables are their own entities
  pr35031.f90 # ENTRY in ELEMENTAL
  pr43996.f90
  pr70070.f90
  pr70853.f90
  pr71799.f90
  pr88328.f90
  recursive_check_1.f # RECURSIVE is now default
  recursive_check_2.f90
  string_1_lp64.f90
  substr_10.f90

  # Tests that expect nonconformant IS_CONTIGUOUS answers with zero size arrays.
  is_contiguous_1.f90
  is_contiguous_3.f90

  # Tests that are errors in gfortran but for which we emit adequate warnings; might need to use -pedantic to see them
  achar_3.f90
  achar_5.f90
  argument_checking_19.f90
  argument_checking_20.f90
  argument_checking_22.f90
  argument_checking_24.f90
  arith_divide.f
  arith_divide_no_check.f
  arithmetic_overflow_1.f90
  array_constructor_type_18.f03
  associate_50.f90
  associated_3.f90
  bessel_5_redux.f90
  bounds_temporaries_1.f90
  dec_loc_rval_3.f03
  do_4.f
  do_check_5.f90
  do_subscript_6.f90
  dollar_sym_1.f90
  dollar_sym_3.f
  entry_22.f90
  enum_8.f90
  error_recovery_4.f90
  fmt_f_default_field_width_3.f90
  fmt_g_default_field_width_3.f90
  fmt_i_default_field_width_3.f90
  ichar_1.f90
  int_conv_2.f90
  integer_exponentiation_4.f90
  interface_21.f90
  interface_30.f90
  interface_33.f90
  interface_46.f90
  invalid_contains_1.f90
  invalid_contains_2.f90
  invalid_procedure_name.f90 # but maybe should be error instead of warning, as in all other compilers
  iso_fortran_env_4.f90
  nearest_5.f90
  pr103259.f90
  pr16433.f
  pr58027.f90
  pr77460.f90
  pr77978_2.f90
  pr84734.f90
  pr86045.f90
  pr91714.f90
  pr92993.f90
  pr95611.f90
  pr95614_1.f90
  pr95614_2.f90
  pr95882_3.f90
  pr95882_4.f90
  recursive_check_3.f90
  return_1.f90
  size_kind_3.f90
  string_2.f90
  string_3.f90
  string_3_lp64.f90
  warn_conversion.f90
  whole_file_1.f90
  whole_file_2.f90

  # Tests that would be errors if we supported options to enable checks
  dec_structure_24.f90
  dec_structure_26.f90
  dec_structure_27.f90
  fimplicit_none_1.f90
  line_length_5.f90
  module_private_1.f90
  spread_size_limit_2.f90

  # Tests of options that need to be in the test configuration
  include_6.f90

  # Missed errors (though not required by a numbered standard constraint)
  # ALLOCATE(entity, stat=something in entity)
  allocate_alloc_opt_11.f90
  # Same object appears more than once in ALLOCATE
  allocate_error_2.f90
  allocate_error_4.f90
  # Character length mismatch between definition and external in same file
  auto_char_len_4.f90
  # Non-conformable array operands -- needs symbolic evaluation to see
  bounds_check_18.f90
  # BTEST position argument checking
  btest_1.f90
  # Not catching EQUIVALENCE of default-initialized derived type object with object in COMMON
  equiv_constraint_9.f90
  # MASKL argument checking
  masklr_3.f90
  # MODULO(x,0) argument checking
  modulo_check.f90
  # MOVE_ALLOC with overlapping arguments
  move_alloc_17.f90
  # MVBITS argument checking
  mvbits_9.f90
  # INQUIRE(UNIT=-1, ...)
  negative_unit_check.f90
  # Small RANDOM_SEED(GET=/PUT=) arrays
  random_seed_1.f90
  random_seed_4.f90
  # RESHAPE(SOURCE=) array is too small
  reshape_source_size_1.f90

  # Extensions, intentionally not errors, but should maybe elicit a portability warning
  # BIND(C,NAME=) name same as module
  binding_label_tests_29.f90
  # BIND(C,NAME=) names are case sensitive in f18
  binding_label_tests_34.f90
  # COMMON block name clashes with local entity
  common_7.f90
  common_8.f90
  # No option needed to enable Cray pointers
  cray_pointers_3.f90
  # D lines default to comments, no need to use option to make that happen
  d_lines_4.f
  dec_d_lines_3.f
  # Complex components (%RE and %IM) and substrings are allowed in DATA statements (need to document extension)
  data_inquiry_ref.f90
  data_substring.f90
  # ELEMENTAL subprograms may not have dummy procedures
  elemental_args_check_2.f90
  elemental_args_check_4.f90
  # Construct labels can conflict with local names
  host_assoc_types_1.f90
  # Names with leading underscores
  invalid_name.f90
  # Long lines in free form source
  line_length_6.f90
  line_length_8.f90
  line_length_9.f90
  # NAMELIST before declaration of object in group
  namelist_98.f90
  # BOZ in structure constructor
  pr93604.f90
  # USE'd module name used as local entity
  pr95880.f90
  use_28.f90
  # Forward reference to procedure name in PROCEDURE(...)
  proc_decl_11.f90
  # Statement function with argument or result with rank > 0
  statement_function_3.f
  # Useless SUBMODULE
  submodule_21.f08
  # Initial tab in fixed form means five leading blanks
  tab_continuation.f
  # DOUBLE COMPLEX
  type_decl_1.f90

  # gfortran warnings and optional errors that we miss & should fix
  # "bytea" statement for "byte a"
  byte_4.f90
  # DO index variable modified in call to internal procedure
  do_check_13.f90
  do_check_16.f90

  # Not relevant to f18
  # Tests "!GCC$ attributes stdcall, fastcall::test"
  compiler-directive_2.f
  # unsupported COMPLEX extension intrinsic function
  complex_intrinsic_2.f90
  # !GCC$ unroll
  directive_unroll_5.f90
  # Tests "!GCC$ attributes weak :: x"
  weak-3.f90

  # Probable bugs
  # ["a", "ab"]
  array_constructor_28.f03
  bounds_check_array_ctor_3.f90
  bounds_check_array_ctor_5.f90
  # ASSOCIATED(p,(t))
  associated_target_1.f90
  # BIND(C) dummy argument can't be CONTIGUOUS pointer
  bind_c_contiguous.f90
  # C_PTR's component should be private so C_PTR structure constructor doesn't work
  c_ptr_tests_13.f03
  # C_SIZEOF() argument must be an interoperable type
  c_sizeof_6.f90
  # Automatic CHARACTER can't be in COMMON
  common_13.f90
  # External should not have same name as COMMON
  common_15.f90
  # Cray pointee must not be in COMMON or EQUIVALENCE
  cray_pointers_4.f90
  # Not catching lack of label actual argument for alternate return dummy
  do_check_19.f90
  # Not catching use of ENTRY-only dummy argument in a specification expression
  entry_dummy_ref_1.f90
  # Parent component of extended derived type with PRIVATE default must be PRIVATE
  extends_10.f03
  # Further declarations after an initialization that are incompatible with it
  initialization_17.f90
  # Old-style initializer on declaration of dummy argument
  oldstyle_2.f90
  # Function result may not be a coarray
  pr104210.f90
  # Should ensure that C_PTR component is private and warn on attempt to PRINT it
  pr32601.f03
  # ABS(S) after CALL S(1)
  pr71859.f90
  # PRESENT() argument must be a whole dummy argument name, not subobject
  present_1.f90
  # integer, parameter :: dp = kind(1.0_dp)
  recursive_parameter_1.f90
  # Statement function cannot be a dummy argument
  stfunc_2.f90
  # Statement function argument implicit type doesn't match later explicit type
  stfunc_3.f90
  # Valid parser failure, could have better error recovery
  use_29.f90
  # Assumed-length CHARACTER cannot be VALUE
  value_5.f90
  # No return type mismatch warning
  whole_file_34.f90
  # No interface mismatch warning on call to implicit interface expecting alternate returns
  whole_file_3.f90
  # Out-of-range \U characters -- do we even support?
  widechar_1.f90

  # Test configuration problems
  # Needs to be compiled as class_4[abc].f03 due to modules -- then compiles
  class_4b.f03
  class_4c.f03
  # Needs to be compiled as class_45[abc].f03 due to modules -- then compiles
  class_45b.f03
  # Needs to be compiled as coarray_29_[12].f90 due to modules -- then hits NYI in lowering "coarray in procedure interface"
  coarray_29_2.f90
  # Needs to be compiled as coarray_35{,a}.f90 -- then hits NYI in lowering "intrinsic: this_image"
  coarray_35a.f90
  # Needs to be compiled with "-ed" or whatever flang-new uses to enable D lines (Fortran::common::LanguageFeature::OldDebugLines); GNU uses "-fd-lines-as-code"
  dec_d_lines_1.f
  d_lines_2.f
  # Needs -fxor-operator
  dec_logical_xor_2.f90
  # Needs to be compiled as Fortran/gfortran/regression/namelist_83{,_2}.f90 due to modules -- then compiles
  namelist_83_2.f90
  # Needs to be compiled as Fortran/gfortran/regression/pr77420_[34].f90 due to modules -- then compiles
  pr77420_4.f90
  # Needs to be compiled as Fortran/gfortran/regression/public_private_module_[34].f90
  public_private_module_4.f90
  # Needs to be a "*.f" file or be compiled with option that forces fixed form
  restricted_expression_1.f90
  # Needs to be compiled as Fortran/gfortran/regression/whole_file_2[89].f90 due to modules -- then compiles
  whole_file_29.f90
  # Needs to be compiled as Fortran/gfortran/regression/whole_file_3[01].f90 due to modules -- then compiles
  whole_file_31.f90

  # Compiler bugs that should be fixed
  # D lines confuse continuation line detection
  d_lines_3.f
  # "LLVM ERROR: not implemented"
  forall_17.f90
  # "0include" not recognized as INCLUDE line with 0 in column 6
  include_12.f
  # .../FIRBuilder.cpp:379: mlir::Value fir::FirOpBuilder::createConvert(mlir::Location, mlir::Type, mlir::Value): Assertion `!fir::isa_derived(toTy)' failed.
  pr68227.f90
  # Invalid specification expression: reference to impure function 'iargc' -- might as well consider it to be pure
  pr71085.f90
  # No explicit type declared for 'f'
  pr91945.f90
  # error: No explicit type declared for 'arg4'
  unused_artificial_dummies_1.f90

  # Valid errors
  # Valid out-of-bounds subscript errors, are warnings in gfortran
  bounds_check_3.f90
  # Valid errors about mismatching actual/dummy character lengths; are warnings in gfortran
  char_length_3.f90
  # Valid error: 'x' may not be a local variable in a pure subprogram  because: 'x' is polymorphic in a pure subprogram
  class_49.f90
  class_74.f90
  # Valid error: Coindexed polymorphic object may not be associated with a polymorphic dummy argument 'x='
  class_dummy_4.f03
  # Valid error: 'atom=' argument must be a scalar coarray or coindexed object for intrinsic 'atomic_ref'
  coarray_atomic_6.f90
  # Valid error: The event-variable must be a coarray
  coarray_event_1.f08
  # Valid error: ALLOCATABLE coarray '...' may not be associated with INTENT(OUT) dummy argument '...='
  coarray_lib_token_2.f90
  intent_out_11.f90
  # Valid error "The type of 'n' has already been implicitly declared" on   "implicit NONE; integer :: a(n); integer (kind=1), intent(in) :: n"
  directive_unroll_1.f90
  directive_unroll_2.f90
  directive_unroll_3.f90
  directive_unroll_4.f90
  # Valid error: A sequence type must have at least one component
  dtio_36.f90
  # Valid error: Result of ENTRY is not compatible with result of containing function
  entry_17.f90
  # Just bad syntax:   READ ('(') // 'A)', var  -- note transposed ) and final quote
  fmt_read_3.f90
  # Valid error: Label '99' is in a construct that prevents its use as a branch target here
  goto_8.f90
  # These tests attempt to print the value of the private component of a C_PTR.
  init_flag_17.f90
  c_ptr_tests_16.f90
  # Valid error: Generic 'ambiguous' may not have specific procedures 'f' and 'f' as their interfaces are not distinguishable
  interface_1.f90
  # Valid error: Generic 'generic' may not have specific procedures 'foo' and 'bar' as their interfaces are not distinguishable
  interface_8.f90
  # Valid error: Dimension 1 of left-hand side has extent 2, but right-hand side has extent 3
  iso_fortran_env_7.f90
  # Valid error: Invalid specification expression: reference to local entity '...'
  pr101026.f
  pr101267.f90
  pr78061.f
  pr79315.f90
  pr95090.f90
  # Valid error: An array component of an interoperable type must have at least one element
  pr105954.f90
  # Bogus error: 'dcdx' is not a callable procedure
  pr41011.f
  # Valid error: Must have INTEGER type, but is REAL(4)   on implicit real-valued DO indices being used as subscripts
  pr41928.f90
  # Valid error: DATA statement initializations affect 'i(1_8,2_8)' more than once
  pr49540-2.f90
  # Valid error: A variable with BIND(C) attribute may only appear in the specification part of a module
  pr67900.f90
  # Valid error: Label '1000' is not distinct
  pr69554-1.F90
  pr69554-2.F90
  # Valid error: Subscript value (3) is out of range on dimension 1 in reference to a constant array value
  pr71935.f90
  # Valid error: Return type of function 'c' does not match return type of the corresponding interface body
  pr83113.f90
  # Valid error: 'v' is already declared in this scoping unit
  pr84957.f90
  # Valid error: Procedure 'foo' is recursively defined.  Procedures in the cycle: 'foo', 'r1'
  recursive_interface_1.f90
  recursive_interface_2.f90
  # Valid error: Actual argument associated with POINTER dummy argument 'thenode=' must also be POINTER unless INTENT(IN)
  select_type_30.f03
  # Valid error: INTEGER stop code must be of default kind
  stop_2.f
  # Valid error: 'bar' is a MODULE procedure which must be declared within a MODULE or SUBMODULE
  submodule_24.f08
  # Valid error: Implicit declaration of function 'bifac' has a different result type than in previous declaration
  whole_file_10.f90
  # Valid error: Values in array constructor must have the same declared type when no explicit type appears
  zero_sized_12.f90
  # Valid errors: attempts to modify pointer component of INTENT(IN) argument
  pointer_intent_1.f90
  # Valid error: ASSOCIATE entities are not pointers
  associate_42.f90

  # Not yet implemented in evaluate / semantics
  # IMAGE_INDEX not (yet) an intrinsic function
  coarray_11.f90
  pr104330.f90
  # ATOMIC_ADD is not (yet) a known intrinsic procedure
  coarray_atomic_4.f90
  coarray_atomic_5.f90
  # CO_REDUCE is not (yet) a known intrinsic procedure
  coarray_collectives_11.f90
  coarray_collectives_15.f90
  coarray_collectives_16.f90
  # Unsupported in folding: erfc_scaled(real(kind=4)) cannot be folded on host
  erfc_scaled_2.f90
  # Can't fold MERGE of derived types
  merge_init_expr_2.f90
  # asin(real(kind=16)) cannot be folded on host
  quad_1.f90

  # Unclear; may be bogus error on actual non-coarray arg to dummy coarray, may be bad test
  coarray_args_2.f90
  coarray_lib_token_1.f90
  coarray_lib_token_4.f90
  # Unclear: conflict between ancestor module type name and submodule name: '...' is already declared in this scoping unit
  pr95689.f90

  # ---------------------------------------------------------------------------
  #
  # These are "compile" tests which fail to compile, though compilation is
  # expected to succeed.
  blockdata_4.f90
  internal_dummy_1.f90

  # This test has a #illegal preprocessor directive. I think this is expected to
  # raise a warning in gfortran, but flang raises an error and fails to compile
  # instead. This may be a policy difference between flang and gfortran but
  # should be confirmed.
  badline.f

  # These test use byte order marks and are in UTF-16 or UTF32. This causes
  # flang's scanner to fail producing errors such as:
  #
  #     error: bad character (0xff) in Fortran token
  #
  # TODO: Need to check if we intend to support such files.
  #
  bom_error.f90
  bom_UTF-16.f90
  bom_UTF16-BE.f90
  bom_UTF16-LE.f90
  bom_UTF-32.f90

  # These check if the parser accepts the "form-feed" character (ASCII 0x0c).
  # Flang fails to compile with "bad character (0x0c) in Fortran token".
  feed_1.f90
  feed_2.f90

  # This splits a string (the argument to an include directive) across two lines
  # using a continuation character. This causes an error:
  #
  #   error: Incomplete character literal
  #
  # This may be a DEC extension but I am not sure.
  include_13.f90

  # This has something to do with the -ffixed-line-length-none directive. It
  # could be that the flag is not being passed correctly to flang in the test
  # suite's build system, or that flang does not support the flag.
  line_length_1.f

  # In these tests, the -fopenmp and -fopenacc flags are either not being passed
  # correctly to flang while building the tests, or flag does not define the
  # _OPENMP/_OPENACC directives while gfortran does.
  openacc-define-3.f90
  openmp-define-3.f90
)
