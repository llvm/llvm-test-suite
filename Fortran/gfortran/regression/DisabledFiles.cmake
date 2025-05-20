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
  # Passing Hollerith to CLASS(*). This is not standard. Flang passes it as character.
  unlimited_polymorphic_14.f90
  # Unsupported predefined macro: __TIMESTAMP__
  wdate-time.F90

  # This test checks that two arrays, initialized with random real numbers that
  # are converted to integers, are not identical. It is possible, though
  # unlikely for such "randomly initialized" arrays to be identical. Because of
  # this inherent flakiness, this test will remain unsupported.
  random_init_2.f90

  # Test is not conformant as it writes to a constant argument
  # Similar test, that is conformant, added to UnitTests/assign-goto
  assign_5.f90

  # Test is not conformant as it expects different value of cmdstat and cmdmsg
  # Similar test added: UnitTests/execute_command_line
  execute_command_line_1.f90
  execute_command_line_3.f90

  # Test is not conformant: reference to f() in tobias::sub1 violates Fortran
  # 2023 (and before) 15.5.2.14 point (4). `f()` references the actual argument
  # of `x` while `x` does not have the TARGET or POINTER attribute.
  aliasing_array_result_1.f90
)

# These tests are skipped because they hit a 'not yet implemented' assertion
# in flang and thus fail to compile. They should be removed from here when the
# corresponding feature is implemented. Eventually, this variable should be
# removed altogether once all the missing features are implemented.
file(GLOB UNIMPLEMENTED_FILES CONFIGURE_DEPENDS
  # unimplemented: assumed rank in procedure interface.
  ISO_Fortran_binding_1.f90
  ISO_Fortran_binding_3.f90
  PR100911.f90
  PR100915.f90
  interface_49.f90
  sizeof_6.f90
  unlimited_polymorphic_1.f03

  # unimplemented: ASYNCHRONOUS in procedure interface
  asynchronous_3.f03

  # unimplemented: assumed type in actual argument
  altreturn_10.f90 # bad Fortran, warnings are correct

  # unimplemented: procedure pointers
  compiler-directive_1.f90
  proc_ptr_1.f90
  recursive_check_6.f03

  # unimplemented: procedure components
  proc_ptr_24.f90
  structure_constructor_11.f90

  # unimplemented: procedure pointer results
  pointer_check_5.f90
  pr39695_1.f90
  pr63797.f90

  # unimplemented: BIND (C) internal procedure.
  bind_c_char_4.f90
  bind_c_char_5.f90

  # unimplemented: BIND(C) internal procedures:
  bind_c_usage_9.f03

  # unimplemented: BIND(C) module variable linkage
  binding_label_tests_10.f03
  binding_label_tests_13.f03
  proc_ptr_8.f90

  # unimplemented: allocatable components in derived type assignment
  pr50769.f90

  # unimplemented: passing dynamically optional argument to elemental procedures
  bounds_check_fail_2.f90
  elemental_optional_args_6.f90

  # unimplemented: io-control-spec contains a reference to a non-integer,
  # non-scalar, or non-variable
  fmt_nonchar_2.f90

  # unimplemented: BOZ
  boz_bge.f90

  # unimplemented: coarray address
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
  coarray_allocate_2.f08
  coarray_allocate_3.f08
  coarray_allocate_5.f08
  coarray_alloc_with_implicit_sync_1.f90
  coarray_alloc_with_implicit_sync_2.f90
  coarray_lib_alloc_1.f90
  coarray_lib_alloc_2.f90
  coarray_lib_alloc_3.f90
  coarray_lib_token_3.f90
  coarray_lock_7.f90
  coarray_poly_4.f90
  intent_out_7.f90

  # unimplemented: coarray in procedure interface
  coarray_29_1.f90
  coarray_32.f90
  coarray_36.f
  coarray_37.f90
  coarray_45.f90
  coarray_allocate_4.f08
  coarray_lib_move_alloc_1.f90
  coarray_lib_this_image_1.f90
  coarray_lib_this_image_2.f90
  coarray_poly_5.f90
  coarray_poly_6.f90
  coarray_poly_7.f90
  coarray_poly_8.f90
  class_optional_1.f90
  class_optional_2.f90
  coarray_41.f90
  pr63331.f90
  submodule_26.f08

  # unimplemented: dummy argument coarray in procedure interface
  complex_1.f90

  # unimplemented: coarray reference
  coarray_lib_comm_1.f90

  # unimplemented: co_max
  coarray_collectives_4.f90
  coarray_collectives_5.f90
  coarray_collectives_6.f90

  # unimplemented: CriticalConstruct implementation
  coarray_2.f90
  coarray_critical_1.f90
  coarray_critical_3.f90

  # unimplemented: FORM TEAM statement
  team_sync_2.f90

  # unimplemented: SYNC IMAGES
  pr71706.f90

  # unimplemented: SYNC MEMORY
  coarray_sync_memory.f90

  # unimplemented: intrinsic: co_broadcast
  coarray_collectives_17.f90

  # unimplemented: intrinsic: failed_images
  coarray_failed_images_1.f08

  # unimplemented: intrinsic: image_status
  coarray_image_status_1.f08

  # unimplemented: intrinsic: min and max for CHARACTER
  minmax_char_1.f90

  # unimplemented: intrinsic: num_images
  coarray_allocate_1.f90
  coarray_collectives_12.f90
  pr96737.f90

  # unimplemented: intrinsic: sind
  dec_math_2.f90

  # unimplemented: intrinsic: stopped_images
  coarray_stopped_images_1.f08

  # unimplemented: intrinsic: this_image
  coarray_40.f90
  coarray_43.f90
  coarray_allocate_10.f08
  coarray_allocate_7.f08
  coarray_allocate_8.f08
  coarray_allocate_9.f08
  coarray_alloc_comp_1.f08
  coarray_alloc_comp_2.f08
  coarray_collectives_18.f90
  coarray_fail_18.f90
  coarray_fail_st.f90
  coarray_ptr_comp_1.f08
  coarray_ptr_comp_2.f08
  coarray_send_by_ref_1.f08
  coarray_stat_2.f90
  coarray_stat_function.f90
  coarray_stat_whitespace.f90
  co_reduce_1.f90
  pr84784.f90
  random_init_3.f90
  random_init_4.f90
  random_init_5.f90
  random_init_6.f90
  team_change_3.f90
  team_form_3.f90
  team_get_1.f90
  team_end_3.f90

  # unimplemented: %VAL() intrinsic for arguments
  c_by_val_1.f
  c_by_val_3.f90

  # unimplemented: parameterized derived types
  dec_type_print_2.f03
  pdt_1.f03
  pdt_10.f03
  pdt_11.f03
  pdt_12.f03
  pdt_15.f03
  pdt_19.f03
  pdt_22.f03
  pdt_25.f03
  pdt_27.f03
  pdt_28.f03
  pdt_36.f03
  pdt_7.f03
  pdt_9.f03
  pr95826.f90

  # unimplemented: host associated derived type with length parameters
  pdt_31.f03

  # unimplemented: derived type components with non default lower bounds
  vax_structure_1.f90

  # unimplemented: asynchronous transfers not implemented in runtime
  f2003_io_1.f03

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

  # unimplemented: no math runtime available for '[SYM]'
  large_real_kind_2.F90
  large_real_kind_3.F90
  large_real_kind_3.F90
  large_real_kind_form_io_1.f90
  norm2_3.f90
  pr96711.f90

  # unimplemented: compute elemental function result length parameters in HLFIR
  elemental_function_3.f90

  # These tests are NYI: support for polymorphic types; when polymorphic
  # type support is enabled by option, they pass.  Delete these when
  # polymorphic types are enabled by default.
  class_allocate_15.f90
  dtio_27.f90
  submodule_6.f08
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

  # These still crash with flang-new when compiling in this test
  # environment, but are usually successful when run manually.
  bind_c_dts_2.f03
  c_funloc_tests.f03
  c_funloc_tests_3.f03
  c_funloc_tests_4.f03
  c_f_pointer_shape_tests_5.f90
  c_f_pointer_tests_4.f90
  c_loc_test.f90
  c_loc_tests_2.f03
  c_loc_test_20.f90
  c_ptr_tests_14.f90
  deferred_character_10.f90
  iso_c_binding_rename_2.f03
  logical_temp_io.f90
  logical_temp_io_kind8.f90
  pr35983.f90
  pr43866.f90
  pr71764.f90
  pr88611.f90
  repack_arrays_1.f90

  # Categorize and debug further
  c_funptr_1.f90 # needs "win32_types" module
  c_funptr_1_mod.f90 # needs "win32_types" module
  c_kind_params.f90 # runtime failure detected in test
  coarray_allocate_6.f08 # NYI: allocation of coarray
  coarray_alloc_comp_3.f08 # NYI: allocation of coarray
  coarray_alloc_comp_6.f08 # NYI: lowering coarray reference
  coarray_alloc_comp_7.f08 # NYI: lowering coarray reference
  coarray_alloc_comp_8.f08 # NYI: lowering coarray reference
  coarray_lib_alloc_4.f90 # NYI: allocation of coarray
  coarray_poly_9.f90 # NYI: allocation of coarray
  winapi.f90 # needs -lkernel32 and target *-*-cygwin*
  widechar_11.f90 # No ASSIGNMENT matches TYPE(c_ptr) and TYPE(__builtin_c_ptr)

  # error: not a constant derived type expression
  coarray_42.f90
  init_flag_10.f90
  pr68078.f90
  pr69739.f90
  typebound_call_32.f90

  # --------------------------------------------------------------------------
  #
  # These tests are skipped because they result in a compile error. This may
  # be the result of them exercising unsupported extensions that are not
  # supported in flang or some other reason. If there are multiple errors
  # in a single file, each distinct error message will be provided.

  # error: ALLOCATABLE dummy argument 'arg=' must be associated with an
  # ALLOCATABLE actual argument
  class_transformational_1.f90

  # error: Assumed-rank array cannot be forwarded to '[var]=' argument
  PR100906.f90
  PR100914.f90

  # error: Actual argument variable length '1' does not match the expected
  # length '77'
  PR95214.f90

  # error: Dimension 1 of left operand has extent [m], but right operand has
  # extent [n]
  assumed_rank_bounds_2.f90
  assumed_rank_bounds_1.f90

  # error: Subscript [m] is less than lower bound [n] for dimension [d] of
  # array
  bounds_check_11.f90
  bounds_check_fail_1.f90

  # error: Assumed-size polymorphic array may not be associated with a
  # monomorphic dummy argument
  class_dummy_7.f90

  # error: '[var]' is an external procedure without the EXTERNAL attribute in
  # a scope with IMPLICIT NONE(EXTERNAL)
  bind-c-contiguous-3.f90

  # error: Assumed type argument requires an explicit interface
  assumed_type_2a.f90

  # error: No intrinsic or user-defined ASSIGNMENT(=) matches operand types
  # 'TYPE 1' and 'TYPE 2'
  assumed_type_18.f90
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
  value_optional_2.f90

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
  boz_complex_3.f90
  char_result_19.f90
  chmod_1.f90
  chmod_2.f90
  chmod_3.f90
  coarray_16.f90
  cray_pointers_7.f90
  dec_math.f90
  dec_math_5.f90
  f_c_string1.f90
  f_c_string2.f90
  fmt_g0_6.f08
  fmt_pf.f90
  interface_12.f90
  result_in_spec_1.f90
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

  # error: Actual argument for 'x=' has bad type 'UNSIGNED''
  out_of_range.f90
  out_of_range_2.f90
  out_of_range_3.f90

  # error: 'coarray=' argument must have corank > 0 for intrinsic 'lcobound'
  bound_simplification_4.f90
  bound_simplification_5.f90

  # error: Coarray argument requires an explicit interface
  coarray_15.f90

  # error: 'mask=' argument has unacceptable rank 0
  coarray_13.f90

  # error: 'a' has corank 0, but coindexed reference has 1 cosubscripts
  coindexed_1.f90

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

  # error: Must be a constant value
  transfer_simplify_12.f90

  # error: COMMON block was not lowered before its usage
  test_common_binding_labels.f03

  # error: Subscript 3 is greater than upper bound 2 for dimension 1 of array
  module_procedure_4.f90

  # error: '[SYM]' is already declared in this scoping unit
  namelist_use.f90

  # error: Actual argument type '[TYPE1]' is not compatible with dummy argument
  # type '[TYPE2]'
  no_arg_check_2a.f90
  pdt_2.f03

  # error: '[SYM]' not found in module 'iso_fortran_env'
  team_change_1.f90
  team_end_1.f90
  team_form_1.f90
  team_number_1.f90

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

  # error: Must have '[TYPE1]' type, but is '[TYPE2]'
  real_index_1.f90

  # error: error: Invalid CONVERT value
  record_marker_3.f90

  # error: Result of pure function may not have an impure FINAL subroutine
  finalize_51.f90

  # error: local non-SAVE variable has coarray component
  # Consider using override.yaml to enable this test but expect different behavior
  coarray_lib_realloc_1.f90

  # error: 'arith.constant' op integer return type must be signless
  # error: Lowering to LLVM IR failed
  # error: cannot be converted to LLVM IR: missing
  # `LLVMTranslationDialectInterface` registration for dialect for op: func.func
  unsigned_25.f90
  unsigned_26.f90
  unsigned_34.f90
  unsigned_35.f90

  # error: Operands must not be UNSIGNED
  unsigned_43.f90
  unsigned_44.f90

  # error: Substring must begin at 1 or later, not -1
  bounds_check_26.f90

  # This test uses the makefile generation options -MT, -MD etc. which are
  # not yet supported.
  dependency_generation_1.f90

  # error: BIND(C) procedure assembly name conflicts with non BIND(C) procedure
  # assembly name
  use_rename_14.f90

  # ---------------------------------------------------------------------------
  #
  # These tests require REAL(kind=16) support. Currently, we do not determine
  # if this is available before enabling the test. Until we can do so
  # reliably, disable it everywhere.

  pr82253.f90
  pr91497.f90
  nan_7.f90

  # --------------------------------------------------------------------------
  #
  # These tests are skipped for a variety of reasons that don't fit well in
  # any of the previous categories

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

  # --------------------------------------------------------------------------
  #
  # These tests are skipped because they cause flang to crash.

  # Assertion `ty.isa<fir::RecordType>()' failed
  c_assoc.f90
  equiv_7.f90
  iso_c_binding_rename_1.f03

  # --------------------------------------------------------------------------
  #
  # These tests require libquadmath which is not built by default. They are
  # disabled until the test suite's configure script is fixed to allow
  # conditionally enabling them if libquadmath is available.

  quad_1.f90
  quad_3.f90
  internal_dummy_3.f08

  # --------------------------------------------------------------------------
  #
  # These are skipped almost certainly because of a bug in the way multi-file
  # compile tests are built by the test-suite. This almost certainly has nothing
  # to do with flang, but they will be skipped until the test suite build
  # scripts are fixed.

  class_4a.f03
  matmul_bounds_14.f
  namelist_83.f90
  pr37287-1.f90
  pr77420_3.f90
  public_private_module_3.f90

  # ----------------------------------------------------------------------------
  #
  # These files are only intended to be run on AArch64, but we don't currently
  # process the target attribute, so these are disabled everywhere. When the
  # DejaGNU target attribute is handled correctly, these should be removed from
  # here.
  pr88833.f90

  # ----------------------------------------------------------------------------
  #
  # These tests have a -J flag but the build system adds a -J of its own and
  # exactly one is allowed. If the build system is changed, these can be removed
  # from here.
  include_14.f90
  include_15.f90
  include_16.f90
  include_17.f90
  include_18.f90
  include_19.f90
  include_20.f90
  include_8.f90

  # ----------------------------------------------------------------------------
  #
  # These tests require 128-bit integer support. Since we do not process
  # DejaGNU directives to conditionally disable such tests, they are always
  # disabled until we can conditionally run such tests
  selected_logical_kind_3.f90

  # error: Only -std=f2018 is allowed currently.
  continuation_19.f

  # error: Must be a constant value
  pdt_33.f03

  # error: 'foo_size' is not a procedure
  pr103312.f90

  # error: Actual argument type '__builtin_c_ptr' is not compatible with dummy
  # argument type 'c_ptr'
  pr108961.f90

  # error: Procedure pointer 'op' with implicit interface may not be associated
  # with procedure designator 'new_t' with explicit interface that cannot be
  # called via an implicit interface
  pr112407a.f90
)

# These tests are disabled because they fail when they are expected to pass.
file(GLOB FAILING_FILES CONFIGURE_DEPENDS
  # ---------------------------------------------------------------------------
  #
  # These tests fail at runtime when they should pass. are likely a result of
  # unimplemented features in the runtime, but they could also be bugs. If any
  # will never pass with flang (if they use unsupported extensions for instance),
  # they should be added to the Unsupported list.

  # Tests that "fail" because they should fail
  assign_2.f90 # j=5; goto j
  error_stop_1.f08 # ERROR STOP stops program
  stop_shouldfail.f90 # STOP stops program

  # require further analysis
  alloc_comp_class_4.f03
  bounds_check_10.f90
  bounds_check_7.f90
  bounds_check_array_ctor_1.f90
  bounds_check_array_ctor_2.f90
  bounds_check_array_ctor_6.f90
  bounds_check_array_ctor_7.f90
  bounds_check_array_ctor_8.f90
  bounds_check_fail_4.f90
  bounds_check_strlen_1.f90
  bounds_check_strlen_2.f90
  bounds_check_strlen_3.f90
  bounds_check_strlen_4.f90
  bounds_check_strlen_5.f90
  bounds_check_strlen_7.f90
  char_bounds_check_fail_1.f90
  char_pointer_assign_4.f90
  char_pointer_assign_5.f90
  check_bits_1.f90 # requires -fcheck=bits to catch ISHFTC runtime error
  check_bits_2.f90 # requires -fcheck=bits to catch ISHFTC runtime error
  cr_lf.f90 # shenanigans with CR characters
  dollar_edit_descriptor_4.f # TODO: (i3,$) format shouldn't advance record when looping
  list_read_11.f90 # more CR character shenanigans
  matmul_bounds_10.f90
  matmul_bounds_2.f90
  matmul_bounds_3.f90
  matmul_bounds_4.f90
  matmul_bounds_5.f90
  matmul_bounds_8.f90
  merge_char_3.f90
  module_nan.f90
  namelist_87.f90
  nan_2.f90 # depend on MIN/MAX(1.,NaN) folding to 1.; f18 & Intel return NaN.
  negative_unit_int8.f # depends on 64-bit unit numbers or something?
  no_range_check_1.f90
  nosigned_zero_2.f90 # only works with a -fno-sign-zero option
  open_access_append_2.f90 # expects warning for OPEN(ACCESS='APPEND'), gets one
  open_errors_3.f90 # same file open on multiple units - valid in F'2018?
  open_status_2.f90 # TODO: support OPEN(STATUS='UNKNOWN')?  research
  pad_source_3.f # depends on -fno-pad-source option
  pad_source_4.f # depends on -ffixed-line-length-none option
  pad_source_5.f # depends on -ffixed-line-length-0 option
  pr119502.f90
  pr12884.f
  pr17286.f90
  pr17706.f90 # depends on -fno-sign-zero option
  pr59700.f90
  pr71523_2.f90
  pr88052.f90
  pr96436_3.f90
  pr96436_4.f90
  pr96436_5.f90
  pr96436_6.f90
  pr96436_7.f90
  pr96436_8.f90
  pr96436_9.f90
  pr96436_10.f90
  promotion_3.f90
  promotion_4.f90
  read_5.f90
  read_bang4.f90
  read_bang.f90
  read_eof_all.f90
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
  recursive_check_11.f90
  recursive_check_13.f90
  recursive_check_7.f90
  recursive_check_9.f90
  reduce_1.f90
  round_3.f08
  selected_kind_1.f90
  short_circuiting_3.f90
  streamio_13.f90
  streamio_17.f90
  system_clock_3.f08
  transpose_2.f90
  unf_io_convert_4.f90
  unf_read_corrupted_1.f90
  unf_short_record_1.f90
  unformatted_subrecord_1.f90
  unsigned_2.f90
  unsigned_22.f90
  unsigned_30.f90
  unsigned_4.f90
  utf8_3.f03
  widechar_IO_4.f90
  zero_sized_1.f90
  do_check_1.f90
  random_3.f90

  # This test fails with "STOP: code 2" when compiled with -O0, but passes at
  # higher optimization levels.
  pr117797.f90

  # ---------------------------------------------------------------------------
  #
  # These tests are expected to raise a runtime error, but currently don't.

  allocate_error_1.f90
  cshift_bounds_2.f90
  deallocate_error_1.f90
  do_check_2.f90
  do_check_3.f90
  do_check_4.f90
  do_check_11.f90
  do_check_12.f90
  endfile_4.f90
  fmt_g0_2.f08
  inline_sum_bounds_check_1.f90
  inline_sum_bounds_check_2.f90
  io_real_boz2.f90
  io_real_boz_4.f90
  io_real_boz_5.f90
  namelist_96.f90 # real data for integer NAMELIST input
  no_unit_error_1.f90
  pointer_check_10.f90
  pointer_check_11.f90 # test exhibits UB, sometimes at O3 it hangs forever
  pointer_remapping_6.f08
  unpack_bounds_1.f90

  # ---------------------------------------------------------------------------
  #
  # Compilation of these tests is expected to fail, but it succeeds instead.

  allocate_error_8.f90
  do_concurrent_12.f90
  do_concurrent_15.f90
  empty_derived_type_2.f90
  interface_51.f90
  interface_52.f90
  proc_ptr_56.f90
  test_common_binding_labels_2_main.f03
  string_1.f90 # Expect error on 32 bits platform
  unsigned_16.f90
  unsigned_37.f90
  unsigned_38.f90
  unsigned_41.f90

  # This test seems to have been commented out entirely, and therefore
  # compilation will succeed. However, there are still DejaGNU annotations in
  # it, and one of them is xfail, so our framework registers this test as xfail.
  initialization_25.f90

  # Gfortran expects compilation errors for invalid uses of volatile; flang
  # supports one of these as an extension, and the others ought to either be
  # warnings or errors. See the flang extensions document: "A non-definable
  # actual argument, including the case of a vector subscript, may be associated
  # with an ASYNCHRONOUS or VOLATILE dummy argument"
  # llvm-project#137369
  volatile8.f90

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
  class_3.f03
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
  intrinsic_std_4.f90
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
  proc_ptr_37.f90 # https://github.com/llvm/llvm-project/issues/73215
  proc_ptr_46.f90 # https://github.com/llvm/llvm-project/issues/73215
  protected_3.f90
  selected_char_kind_3.f90
  spread_init_expr_2.f90
  structure_constructor_9.f90
  system_clock_2.f90
  use_6.f90
  used_before_typed_4.f90
  value_2.f90
  volatile2.f90
  warnings_are_errors_1.f90

  # -std=f2003 tests to detect Fortran 2008 features
  allocate_alloc_opt_8.f90
  bessel_3.f90
  bind_c_array_params.f03
  bind_c_bool_1.f90
  binding_label_tests_20.f90
  class_52.f90
  c_funloc_tests_5.f03
  c_kind_int128_test1.f03
  c_loc_test_19.f90
  c_loc_test_21.f90
  c_loc_tests_10.f03
  c_loc_tests_4.f03
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
  ptr_func_assign_2.f08
  pure_formal_2.f90
  rank_2.f90
  realloc_on_assign_20.f90
  submodule_3.f08
  type_decl_2.f90
  typebound_proc_3.f03
  typebound_proc_15.f03

  # -std=f2008 tests to detect Fortran 2018 features
  assumed_type_16.f90
  assumed_type_4.f90
  bind_c_usage_28.f90
  c_loc_tests_11.f03
  coarray_collectives_2.f90
  coarray_collectives_10.f90
  coarray_collectives_13.f90
  implicit_14.f90
  pr90290.f90
  pr91564.f90
  rank_3.f90
  assumed_rank_5.f90

  # Requires behaviour specific to -std=f2008 and fails with -std=f2018.
  finalize_38a.f90

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
  der_io_5.f90 # gfortran's error is inappropriate, array-ctor are not polymorphic.
  equiv_pure.f90 # gfortran's error is inappropriate for this test
  finalize_9.f90
  func_decl_3.f90
  initialization_20.f90
  initialization_24.f90
  interface_7.f90
  intrinsic_short-long.f90
  parameter_array_init_6.f90
  pr105501.f90 # Missing space between TYPE and IS is not ambiguous for parser.
  pr19936_1.f90 # ac-do-variables are their own entities
  pr35031.f90 # ENTRY in ELEMENTAL
  pr43996.f90
  pr70070.f90
  pr70853.f90
  pr71799.f90
  pr88328.f90
  recursive_check_1.f # RECURSIVE is now default
  recursive_check_2.f90
  select_type_17.f03 # gfortran's error is inappropriate: pointer results are variables.
  string_1_lp64.f90
  substr_10.f90

  # Tests that expect nonconformant IS_CONTIGUOUS answers with zero size arrays.
  is_contiguous_1.f90
  is_contiguous_3.f90

  # Flang allows a redundant 'contiguous' attribute on scalars and on arrays
  # that are simply contiguous (not pointers or assumed-shape/rank).
  contiguous_6.f90
  contiguous_9.f90
  pr95503.f90

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
  associate_50.f90
  associated_3.f90
  bessel_5_redux.f90
  bounds_temporaries_1.f90
  c_f_pointer_tests_5.f90
  dec_loc_rval_3.f03
  do_4.f
  do_check_5.f90
  do_subscript_6.f90
  dollar_sym_1.f90
  dollar_sym_3.f
  entry_22.f90
  enum_8.f90
  error_recovery_4.f90
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
  recursive_check_3.f90
  restricted_expression_2.f90
  restricted_expression_3.f90
  return_1.f90
  size_kind_3.f90
  string_3.f90
  string_3_lp64.f90
  warn_conversion.f90
  whole_file_1.f90
  whole_file_2.f90

  # Tests that used to be hard errors, are now warnings, need -pedantic to
  # observe them
  interface_6.f90
  interop_params.f03
  iso_c_binding_class.f03

  # Tests that would be errors if we supported options to enable checks
  dec_structure_24.f90
  line_length_5.f90
  module_private_1.f90

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
  # External should not have same name as COMMON
  common_15.f90
  # Not catching lack of label actual argument for alternate return dummy
  do_check_19.f90
  # Not catching use of ENTRY-only dummy argument in a specification expression
  entry_dummy_ref_1.f90
  # Parent component of extended derived type with PRIVATE default must be PRIVATE
  extends_10.f03
  # Old-style initializer on declaration of dummy argument
  oldstyle_2.f90
  # integer, parameter :: dp = kind(1.0_dp)
  recursive_parameter_1.f90
  # Statement function cannot be a dummy argument
  stfunc_2.f90
  # Statement function argument implicit type doesn't match later explicit type
  stfunc_3.f90
  # Assumed-length CHARACTER cannot be VALUE
  value_5.f90
  # No return type mismatch warning
  whole_file_34.f90
  # No interface mismatch warning on call to implicit interface expecting alternate returns
  whole_file_3.f90

  # Test configuration problems
  # Needs to be compiled as class_4[abc].f03 due to modules -- then compiles
  class_4b.f03
  class_4c.f03
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

  # Compiler bugs that should be fixed
  # D lines confuse continuation line detection
  d_lines_3.f
  # "0include" not recognized as INCLUDE line with 0 in column 6
  include_12.f
  # Invalid specification expression: reference to impure function 'iargc' -- might as well consider it to be pure
  pr71085.f90
  # No explicit type declared for 'f'
  pr91945.f90
  # error: No explicit type declared for 'arg4'
  unused_artificial_dummies_1.f90

  # Invalid specification expression: reference to OPTIONAL dummy argument
  allocatable_length_2.f90

  # Valid errors
  # Valid out-of-bounds subscript errors, are warnings in gfortran
  bounds_check_3.f90
  # Valid errors about mismatching actual/dummy character lengths; are warnings in gfortran
  char_length_3.f90
  # Valid error: 'x' may not be a local variable in a pure subprogram  because: 'x' is polymorphic in a pure subprogram
  class_49.f90
  class_74.f90
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
  # Valid error: Result of ENTRY is not compatible with result of containing function
  entry_17.f90
  # Just bad syntax:   READ ('(') // 'A)', var  -- note transposed ) and final quote
  fmt_read_3.f90
  # Valid error: Label '99' is in a construct that prevents its use as a branch target here
  goto_8.f90
  # Valid error: Generic 'ambiguous' may not have specific procedures 'f' and 'f' as their interfaces are not distinguishable
  interface_1.f90
  # Valid error: Generic 'generic' may not have specific procedures 'foo' and 'bar' as their interfaces are not distinguishable
  interface_8.f90
  # Valid error: Dimension 1 of left-hand side has extent 2, but right-hand side has extent 3
  iso_fortran_env_7.f90
  # Valid error: Invalid specification expression: reference to local entity '...'
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
  # Valid error: Values in array constructor must have the same declared type when no explicit type appears
  zero_sized_12.f90
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

  # Unclear; may be bogus error on actual non-coarray arg to dummy coarray, may be bad test
  coarray_args_2.f90
  coarray_lib_token_1.f90
  coarray_lib_token_4.f90

  # ---------------------------------------------------------------------------
  #
  # These are "compile" tests which fail to compile, though compilation is
  # expected to succeed.
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
  literal_character_constant_1_z.F

  # In these tests, the -fopenmp and -fopenacc flags are either not being passed
  # correctly to flang while building the tests, or flag does not define the
  # _OPENMP/_OPENACC directives while gfortran does.
  openacc-define-3.f90
  openmp-define-3.f90

  # Tests looking for runtime errors (e.g., bound checks). Correctly
  # caught by flang runtime.
  allocate_with_source_22.f03
  associate_32.f03
  inline_matmul_1.f90
  maxloc_bounds_5.f90
  ptr_func_assign_1.f08

  # Tests looking for runtime errors (e.g., bound checks). Correctly
  # caught by flang runtime, but not caught with Flang optimizations,
  # e.g. due to intrinsics inlining.
  # Until https://github.com/orgs/llvm/projects/12?pane=issue&itemId=29048733
  # is implemented, they can only pass at -O0:
  all_bounds_1.f90
  cshift_bounds_3.f90
  cshift_bounds_4.f90
  inline_matmul_15.f90
  matmul_5.f90
  matmul_bounds_11.f90
  matmul_bounds_13.f90
  matmul_bounds_15.f
  matmul_bounds_16.f
  matmul_bounds_7.f90
  matmul_bounds_9.f90
  maxloc_bounds_1.f90
  maxloc_bounds_2.f90
  maxloc_bounds_3.f90
  maxloc_bounds_4.f90
  maxloc_bounds_6.f90
  maxloc_bounds_7.f90
  maxloc_bounds_8.f90
  pack_bounds_1.f90
  spread_bounds_1.f90

  # Bad test, assigning an 11 elements array to a 12 elements array.
  transfer_array_intrinsic_4.f90

  # Bad test; reads 0.D99999 from a file; every other Fortran works
  io_err_1.f90

  # Fails at runtime with a valid I/O error due to INQUIRE(IOLENGTH=n)
  # being used on a derived type with defined unformatted output.
  dtio_16.f90

  # Fail at runtime due to dependence on gfortran's specific IOSTAT=
  # error code numbers or IOMSG= error message texts.
  direct_io_7.f90
  dtio_10.f90
  dtio_15.f90
  dtio_24.f90
  dtio_26.f03
  iostat_4.f90
  namelist_89.f90
  namelist_97.f90

  # Depends on gfortran's exact NAMELIST output spacing and record advances
  dtio_25.f90
  namelist_18.f90
  namelist_19.f90
  namelist_38.f90
  namelist_57.f90
  namelist_65.f90
  namelist_84.f90
  pr18210.f90

  # Bad test that expects partial NAMELIST input into a character array to
  # blank-fill the remaining elements.
  namelist_56.f90

  # Bad test that expects truncated NAMELIST input groups to be treated as
  # END= conditions rather than ERR= conditions (like every other Fortran).
  namelist_81.f90

  # Bad test that expects the result of TRIM() to have a leading space
  dtio_14.f90

  # Bad tests that expect IOMSG to be defined by a defined I/O subroutine
  # even when IOSTAT=0, violating F'23 12.6.4.8.3 paragraph 4:
  # "If the defined input/output procedure returns a nonzero value for the iostat
  # argument, the procedure shall also return an explanatory message in the iomsg
  # argument. Otherwise, the procedure shall not change the value of the
  # iomsg argument."
  dtio_4.f90

  # Valid test, but the expected output is incorrect (gfortran inserts
  # spaces that must not be there; F'23 13.10.4 p1).
  dtio_30.f03

  # A bad test that expects child input to span records
  dtio_7.f90

  # Unimplemented extension: reading a directory as a stream
  read_dir.f90

  # Unimplemented extension: \u and \U Unicode escape sequences
  widechar_1.f90

  # Unimplemented extension: \b backslash escapes in FORMAT statements
  backslash_3.f

  # Depends on gfortran's exact (DE)ALLOCATE(ERRMSG=) wording
  allocate_alloc_opt_15.f90
  allocate_alloc_opt_3.f90
  deallocate_alloc_opt_3.f90
  deallocate_stat_2.f90

  # Depends on gfortran's exact non-zero (DE)ALLOCATE(STAT=) codes
  deallocate_stat.f90

  # Depends on gfortran's incorrect return of EOR (-2) on internal
  # WRITE record overflow
  arrayio_3.f90

  # Depends on gfortran's incorrect return of EOF (-1) on internal
  # WRITE array overflow
  arrayio_5.f90

  # Depends on gfortran's implementation of list-directed & G0 output
  char4_iunit_1.f03
  char4_iunit_2.f03
  f2003_io_5.f03
  fmt_f_default_field_width_1.f90
  fmt_f_default_field_width_2.f90
  fmt_g0_1.f08
  fmt_g_default_field_width_1.f90
  fmt_g_default_field_width_2.f90
  fmt_i_default_field_width_1.f90
  fmt_i_default_field_width_2.f90
  fmt_zero_width.f90
  list_directed_large.f90

  # Depends on gfortran padding Hollerith with blanks up to even 32-bit words.
  # gfortran & nvfortran do so; ifort/ifx, NAG, and f18 pad with zeroes; XLF
  # doesn't pad at all.
  hollerith8.f90

  # Depends on gfortran returning a nonstandard "UNSPECIFIED" result for
  # INQUIRE(..., POSITION=).
  inquire_5.f90

  # Depends on gfortran's specific maximum sequential unformatted record size.
  inquire_recl_f2018.f90

  # gfortran interprets INQUIRE(-1, ..., IOSTAT=) as a failed attempt to
  # inquire a child unit created for defined I/O to an internal unit, even
  # when it is not; f18 treats it as a nonexistent external unit.
  # Other compilers vary.
  inquire_internal.f90

  # gfortran expects FLUSH(unconnected unit) to be a runtime error;
  # all other Fortran compilers, and (debatably) the standard, allow it.
  iostat_5.f90

  # Depends on gfortran emitting "Infinity" for formatted output;
  # some compilers, including f18, emit "Inf".
  large_real_kind_1.f90

  # Require -finit-local-zero or similar.
  dec_init_2.f90 # needs -finit-derived -finit-integer=42 &c.
  init_flag_15.f03 # needs -finit-derived -finit-integer
  auto_save_2.f90 # requires -fno-automatic -finit-local-zero
  init_flag_1.f90 # needs -finit-local-zero
  init_flag_2.f90
  init_flag_3.f90
  init_flag_4.f90
  init_flag_5.f90
  init_flag_6.f90
  init_flag_7.f90
  init_flag_9.f90

  # Require -fno-realloc-lhs or similar.
  realloc_on_assign_21.f90

  # Require -fcheck=bounds or similar.
  bounds_check_17.f90
  pr48958.f90

  # Require -fcheck=pointer.
  pointer_check_6.f90

  # These files require the __truncsfbf2 intrinsic that is not available
  # before GCC 13. Alternatively, it requires compiler-rt to be built and a
  # command line option provided to instruct the compiler to use it. Currently,
  # we do not support either a version check on GCC or require that compiler-rt
  # be built, so these are disabled. See:
  #
  # https://github.com/llvm/llvm-test-suite/pull/143#discussion_r1689462248
  #
  fmt_en.f90
  fmt_en_rd.f90
  fmt_en_rn.f90
  fmt_en_ru.f90
  fmt_en_rz.f90

  # The causes of failure of these tests need to be investigated
  PR113061.f90
  allocate_with_source_29.f90
  boz_8.f90
  continuation_18.f90
  data_initialized_4.f90
  data_pointer_3.f90
  date_and_time_2.f90
  interface_50.f90
  interface_procedure_1.f90
  iso_fortran_env_9.f90
  line_length_12.f90
  oldstyle_5.f
  out_of_range_1.f90
  pdt_34.f03
  pdt_35.f03
  pr112407b.f90
  pr114883.f90
  pr25623-2.f90
  pr25623.f90
  pr43984.f90
  pr88624.f90
  pr99368.f90
  reshape_10.f90
  selected_logical_kind_2.f90
  submodule_3.f08
  submodule_33.f08
  unsigned_21_be.f90
  achar_2.f90
  allocate_with_source_30.f90
  allocate_with_source_31.f90
  backslash_1.f90
  bound_11.f90
  bounds_check_fail_6.f90
  bounds_check_fail_7.f90
  internal_dummy_2.f08
  iso_fortran_env_8.f90
  optional_absent_12.f90
  pr103389.f90
  pr105456-nmlr.f90
  pr105473.f90
  pr111022.f90
  pr114304.f90
  zero_sized_15.f90

  # Test needs to add -pedantic to show the error
  pr32601.f03

  # Tests expect semantic errors that are not raised.
  c_sizeof_7.f90

  # We allow USE association of a subprogram's name into its scope, with a portability
  # warning, so long as it is not used in that scope.
  use_15.f90
  use_rename_8.f90
)
