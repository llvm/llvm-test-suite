#===------------------------------------------------------------------------===#
#
# Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
# See https://llvm.org/LICENSE.txt for license information.
# SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
#
#===------------------------------------------------------------------------===#

# There are currently no unsupported files.
set(UNSUPPORTED_FILES "")

file(GLOB UNIMPLEMENTED_FILES CONFIGURE_DEPENDS
  # unimplemented: procedure pointers
  atomic-10.f90

  # unimplemented: procedure pointer arguments
  pr44036-1.f90
  pr44036-2.f90

  # unimplemented: coarray in procedure interface
  declare-simd-coarray-lib.f90

  # unimplemented: gather rhs LEN parameters in assignment to allocatable
  defaultmap-3.f90
  defaultmap-4.f90
  defaultmap-5.f90
  defaultmap-6.f90

  # unimplemented: support for polymorphic types
  pr102621.f90
  pr86470.f90

  # unimplemented: derived type components with non default lower bounds
  depend-iterator-1.f90

  # unimplemented: Construct enclosing do loop
  combined-if.f90
  openmp-simd-6.f90
  pr107214-7.f90
  pr79154-2.f90
  pr82568.f90
  schedule-modifiers-1.f90
  target3.f90
  teams1.f90

  # unimplemented: array sections not supported for task depend
  depend-4.f90

  # unimplemented: OMPD_target_data for Array Expressions or Structure
  # Components.
  map-5.f90

  # unimplemented: OpenMP Block construct clause
  pr71758.f90
  pr77352.f90
  pr81887.f90
  target-device-2.f90

  # unimplemented: OMPD_target_data MapOperand BoxType
  pr107214.f90

  # unimplemented: Unhandled block directive
  pr39152.f90
  pr69128.f90
  pr69281.f90
  pr70855.f90
  pr95869.f90
  teams-4.f90
  workshare2.f90
  workshare3.f90

  # unimplemented: OpenMPDeclareSimdConstruct
  pr79154-1.f90
  pr93555.f90
  declare-simd-6.f90

  # unimplemented: OpenMPRequiresConstruct
  requires-7.f90
  target-device-ancestor-5.f90
  target-device-ancestor-6.f90

  # unimplemented: NONTEMPORAL clause in SIMD construct
  nontemporal-1.f90

  # unimplemented: LINEAR clause in SIMD construct
  pr89027.f90
)

file(GLOB SKIPPED_FILES CONFIGURE_DEPENDS
  # error: the update operation inside the region must be a binary operation and
  # that update operation must have the region argument as an operand
  atomic-12.f90

  # error: address must dereference to value type
  omp_atomic2.f90

  # error: SemanticsContext::FindScope(): invalid source location
  target-device-ancestor-4.f90
  taskwait.f90

  # Crash in: Fortran::semantics::AnalyzeKindSelector
  openmp-simd-1.f90
  openmp-simd-2.f90
  openmp-simd-3.f90
  pr71704.f90
)

file(GLOB FAILING_FILES CONFIGURE_DEPENDS
  #
  # These tests are marked as failing because they fail to compile when the
  # compilation is expected to succeed.
  #

  # expected end of line
  affinity-1.f90
  cancel-3.f90
  clauses-1.f90
  declare-simd-4.f90
  declare-target-4.f90
  if-1.f90
  lastprivate-conditional-2.f90
  lastprivate-conditional-3.f90
  lastprivate-conditional-4.f90
  linear-2.f90
  linear-4.f90
  pr99928-1.f90
  pr99928-2.f90
  pr99928-3.f90
  pr99928-4.f90
  pr99928-5.f90
  pr99928-6.f90
  pr99928-8.f90
  scan-5.f90
  taskloop-1.f90
  workshare-reduction-10.f90
  workshare-reduction-11.f90
  workshare-reduction-12.f90
  workshare-reduction-13.f90
  workshare-reduction-14.f90
  workshare-reduction-15.f90
  workshare-reduction-16.f90
  workshare-reduction-17.f90
  workshare-reduction-18.f90
  workshare-reduction-19.f90
  workshare-reduction-1.f90
  workshare-reduction-20.f90
  workshare-reduction-21.f90
  workshare-reduction-22.f90
  workshare-reduction-23.f90
  workshare-reduction-24.f90
  workshare-reduction-25.f90
  workshare-reduction-26.f90
  workshare-reduction-27.f90
  workshare-reduction-28.f90
  workshare-reduction-29.f90
  workshare-reduction-2.f90
  workshare-reduction-30.f90
  workshare-reduction-31.f90
  workshare-reduction-32.f90
  workshare-reduction-33.f90
  workshare-reduction-34.f90
  workshare-reduction-35.f90
  workshare-reduction-36.f90
  workshare-reduction-37.f90
  workshare-reduction-38.f90
  workshare-reduction-39.f90
  workshare-reduction-3.f90
  workshare-reduction-40.f90
  workshare-reduction-41.f90
  workshare-reduction-42.f90
  workshare-reduction-43.f90
  workshare-reduction-44.f90
  workshare-reduction-45.f90
  workshare-reduction-46.f90
  workshare-reduction-47.f90
  workshare-reduction-48.f90
  workshare-reduction-49.f90
  workshare-reduction-4.f90
  workshare-reduction-50.f90
  workshare-reduction-51.f90
  workshare-reduction-52.f90
  workshare-reduction-53.f90
  workshare-reduction-54.f90
  workshare-reduction-55.f90
  workshare-reduction-56.f90
  workshare-reduction-57.f90
  workshare-reduction-58.f90
  workshare-reduction-5.f90
  workshare-reduction-6.f90
  workshare-reduction-7.f90
  workshare-reduction-8.f90
  workshare-reduction-9.f90

  # expected 'TASKYIELD'
  affinity-clause-1.f90
  affinity-clause-5.f90
  depend-5.f90
  pr103643.f90

  # expected 'THREADPRIVATE'
  affinity-clause-3.f90
  all-memory-2.f90
  masked-1.f90
  masked-combined-1.f90
  masked-taskloop.f90
  nothing-1.f90
  num-teams-1.f90
  num-teams-2.f90
  openmp-simd-7.f90
  parallel-master-1.f90
  pr103695.f90
  pr99928-11.f90
  reduction-task-3.f90
  scan-2.f90
  scope-6.f90

  # expected 'DO'
  all-memory-3.f90

  # expected 'ALLOCATE'
  assume-1.f90
  assume-3.f90
  assume-4.f90
  atomic-25.f90
  atomic.f90
  openmp-simd-8.f90

  # expected 'END ATOMIC'
  atomic-16.f90
  atomic-17.f90

  # expected '!$OMP '
  atomic-19.f90
  atomic-20.f90
  atomic-21.f90
  strictly-structured-block-3.f90

  # expected 'DECLARE TARGET'
  depend-6.f90
  depobj-1.f90
  lastprivate-conditional-5.f90
  reduction-task-1.f90
  scan-3.f90
  scan-4.f90

  # expected 'END'
  error-2.f90
  omp_parse1.f90

  # expected 'CRITICAL'
  loop-1.f90
  loop-3.f90
  loop-5.f90

  # expected 'TARGET UPDATE'
  map-6.f90
  map-7.f90
  target-has-device-addr-2.f90

  # expected 'MASTER'
  nowait-2.f90
  nowait-5.f90
  strictly-structured-block-1.f90

  # expected 'SINGLE'
  nowait-3.f90
  nowait-7.f90
  scope-1.f90
  scope-2.f90

  # IMPORT statements must follow any USE statements and precede all other
  # declarations
  order-1.f90

  # expected 'PARALLEL DO'
  pr102431.f90

  # expected 'TARGET TEAMS DISTRIBUTE'
  pr107214-4.f90

  # expected 'TYPE'
  pr77665.f90

  # 'b1' appears in more than one data-sharing clause on the same OpenMP
  # directive
  allocate-1.f90

  # COPYPRIVATE variable is not PRIVATE or THREADPRIVATE in outer context
  copyprivate-1.f90
  pr26224.f

  # The DEFAULT(NONE) clause requires that 'a' must be listed in a data-sharing
  # attribute clause
  crayptr4.f90

  # Implied-shape array must be a named constant or a dummy argument
  crayptr5.f90

  # Internal: no symbol found for
  declare-simd-2.f90
  declare-simd-3.f90
  is_device_ptr-1.f90
  is_device_ptr-3.f90
  pr83977.f90

  # The type of 'var_1' has already been implicitly declared
  declare-target-1.f90

  # SEQ_CST clause is not allowed on the FLUSH directive
  flush-1.f90

  # At least one of MAP clause must appear on the TARGET DATA directive
  is_device_ptr-2.f90
  map-3.f90

  # ORDER clause is not allowed on the TEAMS DISTRIBUTE directive
  order-5.f90
  order-7.f90

  # `DISTRIBUTE` region has to be strictly nested inside `TEAMS` region.
  pr104757.f90

  # The parameter of the SAFELEN clause must be a constant positive integer
  # expression
  pr77516.f90

  # Subscript 9 is greater than upper bound 8 for dimension 1 of array
  pr78299.f90

  # The chunk size of the SCHEDULE clause must be a positive integer expression
  schedule-1.f90

  # Only the TO, ALLOC map types are permitted for MAP clauses on the TARGET
  # ENTER DATA directive
  target-data-1.f90

  # DEFAULT clause is not allowed on the TARGET TEAMS DISTRIBUTE SIMD directive
  target1.f90

  # Must be a constant value
  target2.f90

 # bad character ('{') in Fortran token
  declare-variant-10.f90
  declare-variant-11.f90
  declare-variant-12.f90
  declare-variant-13.f90
  declare-variant-14.f90
  declare-variant-15.f90
  declare-variant-16.f90
  declare-variant-1.f90
  declare-variant-3.f90
  declare-variant-4.f90
  declare-variant-5.f90
  declare-variant-8.f90
  declare-variant-9.f90
  free-2.f90

  # Incomplete character literal
  include_1.f
  include_2.f90

  #
  # These tests are marked as failing because the compilation succeeds when it
  # is expected to fail.
  #
  canonical-loop-2.f90
  crayptr2.f90
  map-alloc-comp-1.f90
  pr33439.f90
  pr44036-3.f90
  pr78866-2.f90
  reduction3.f90
  sharing-3.f90
)
