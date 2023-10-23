#===------------------------------------------------------------------------===#
#
# Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
# See https://llvm.org/LICENSE.txt for license information.
# SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
#
#===------------------------------------------------------------------------===#

# These tests are skipped because they hit a 'not yet implemented' assertion
# in flang and thus fail to compile. They should be removed from here when the
# corresponding feature is implemented. Eventually, this variable should be
# removed altogether once all the missing features are implemented.
file(GLOB UNIMPLEMENTED_FILES CONFIGURE_DEPENDS
  # unimplemented: lower descriptor designator to HLFIR value
  allocatable_scalar_1.f90
  deferred_type_param_8.f90
  pointer_function_actual_1.f90

  # unimplemented: compute elemental function result length parameters in HLFIR
  array_temporaries_3.f90
  pure_byref_1.f90

  # unimplemented: BIND(C) INTENT(OUT) allocatable deallocation in HLFIR
  bind_c_procs_3.f90

  # unimplemented: pointer assignment inside FORALL
  dependency_19.f90
  forall_3.f90
  pr49698.f90
)

# These tests are disabled because they fail when they are expected to pass.
file(GLOB FAILING_FILES CONFIGURE_DEPENDS
  # ---------------------------------------------------------------------------
  #
  # These tests fail at runtime when they should pass. are likely a result of
  # unimplemented features in the runtime, but they could also be bugs. If any
  # will never pass with flang (if they use unsupported extensions for instance),
  # they should be added to the Unsupported list.

  all_bounds_1.f90
  array_constructor_11.f90
  array_constructor_45.f90
  bounds_check_array_ctor_4.f90
  bounds_check_fail_3.f90
  bounds_check_12.f90
  function_optimize_11.f90
  maxloc_bounds_1.f90
  maxloc_bounds_2.f90
  maxloc_bounds_4.f90
  maxloc_bounds_5.f90
  maxloc_bounds_7.f90
  maxloc_bounds_8.f90
  pack_bounds_1.f90
  pr67524.f90
  spread_bounds_1.f90
  transfer_array_intrinsic_4.f90
  maxlocval_1.f90
)
