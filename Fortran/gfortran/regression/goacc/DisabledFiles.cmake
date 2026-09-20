#===------------------------------------------------------------------------===#
#
# Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
# See https://llvm.org/LICENSE.txt for license information.
# SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
#
#===------------------------------------------------------------------------===#

# There are currently no unsupported files.
set(UNSUPPORTED_FILES "")

# Flang accepts and lowers OpenACC to the OpenACC MLIR dialect, but code
# generation for the directives below is not implemented yet. Compiling these
# aborts with "not yet implemented: OpenACC <directive> directive". The files
# are grouped by the directive that is reported first for each test.
file(GLOB UNIMPLEMENTED_FILES CONFIGURE_DEPENDS
  # not yet implemented: OpenACC atomic directive
  atomic-1.f90

  # not yet implemented: OpenACC cache directive
  cache-1.f95

  # not yet implemented: OpenACC data directive
  data-tree.f95
  default-4.f
  kernels-loop-data-2.f95
  kernels-loop-data.f95
  modules.f95

  # not yet implemented: OpenACC declare directive
  declare-3.f95
  pr78260-2.f90

  # not yet implemented: OpenACC enter data directive
  array-with-dt-4.f90
  array-with-dt-5.f90
  attach-descriptor.f90
  derived-chartypes-1.f90
  derived-chartypes-2.f90
  derived-chartypes-3.f90
  derived-chartypes-4.f90
  derived-classtypes-1.f95
  derived-types-2.f90
  enter-exit-data-2.f90
  kernels-loop-data-enter-exit-2.f95
  kernels-loop-data-enter-exit.f95
  kernels-loop-data-update.f95
  kernels-parallel-loop-data-enter-exit.f95
  mapping-tests-3.f90

  # not yet implemented: OpenACC exit data directive
  array-with-dt-3.f90
  finalize-1.f

  # not yet implemented: OpenACC host_data directive
  host_data-tree.f95
  uninit-use-device-clause.f95

  # not yet implemented: OpenACC kernels directive
  classify-kernels-parloops.f95
  classify-kernels-unparallelized-parloops.f95
  classify-kernels-unparallelized.f95
  classify-kernels.f95
  default-1.f95
  default-5.f
  kernels-alias-2.f95
  kernels-alias-3.f95
  kernels-alias-4.f95
  kernels-alias.f95
  kernels-decompose-1.f95
  kernels-loop-2.f95
  kernels-loop-inner.f95
  kernels-loop-n.f95
  kernels-loop.f95
  kernels-loops-adjacent.f95
  kernels-tree.f95
  loop-tree-1.f90
  nested-reductions-1-kernels.f90
  nested-reductions-2-kernels.f90
  orphan-reductions-3.f90
  private-explicit-kernels-1.f95
  private-predetermined-kernels-1.f95
  routine-3.f90
  uninit-copy-clause.f95

  # not yet implemented: OpenACC kernels loop directive
  loop-2-kernels-nested.f95

  # not yet implemented: OpenACC parallel directive
  fixed-1.f
  fixed-3.f
  fixed-4.f
  implied-copy-2.f90
  nested-reductions-1-parallel.f90
  nested-reductions-2-parallel.f90
  note-parallelism.f90
  parallel-tree.f95
  pr104717.f90
  pr77371-1.f90
  pr78027.f90
  pr85879.f90
  pr93464-2.f90
  pr93464.f90
  privatization-1-compute.f90
  privatization-1-compute-loop.f90
  private-3.f95
  private-explicit-parallel-1.f95
  private-predetermined-parallel-1.f95
  reduction-promotions.f90
  tile-lowering.f95
  uninit-dim-clause.f95
  uninit-firstprivate-clause.f95
  uninit-if-clause.f95

  # not yet implemented: OpenACC parallel loop directive
  classify-parallel.f95
  combined-directives.f90
  combined_loop.f90
  common-block-3.f90
  default_none.f95
  gang-static.f95
  implied-copy-1.f90
  loop-2-parallel-nested.f95
  pr84217.f90
  pr85703.f90
  reduction-2.f95
  tile-3.f90
  vector_length.f90

  # not yet implemented: OpenACC routine directive
  classify-routine.f95
  classify-routine-nohost.f95
  kernels-decompose-2.f95
  pr71704.f90
  pr89773.f90
  private-explicit-routine-1.f95
  private-predetermined-routine-1.f95
  privatization-1-routine_gang.f90
  privatization-1-routine_gang-loop.f90
  routine-external-level-of-parallelism-1-parallel.f
  routine-external-level-of-parallelism-1-serial.f
  routine-level-of-parallelism-1.f90
  routine-module-1.f90
  routine-multiple-directives-1.f90

  # not yet implemented: OpenACC serial directive
  nested-reductions-1-serial.f90
  nested-reductions-2-serial.f90
  private-explicit-serial-1.f95
  private-predetermined-serial-1.f95
  serial-tree.f95

  # not yet implemented: OpenACC serial loop directive
  classify-serial.f95
  loop-2-serial-nested.f95

  # not yet implemented: OpenACC update directive
  array-with-dt-1a.f90
  array-with-dt-1.f90
  array-with-dt-2.f90
  update-if_present-1.f90

  # not yet implemented: OpenACC wait directive
  wait.f90
)

# There are currently no files that make flang crash.
set(SKIPPED_FILES "")

# These tests are disabled because they fail when they should pass.
file(GLOB FAILING_FILES CONFIGURE_DEPENDS
  # error: 'acc.parallel' op wait attribute cannot appear with waitOperands
  # error: verification of lowering to FIR failed
  asyncwait-5.f

  # error: expected declaration construct
  # IMPORT is not accepted in the specification part of an interface body.
  specification-part.f90

  # error: INDEPENDENT and AUTO clauses are mutually exclusive and may not
  # appear on the same LOOP directive
  nested-function-1.f90

  # error: Modifier is not allowed for the COPYIN clause on the ENTER DATA
  # directive
  readonly-1.f90

  # These tests are expected to issue a compile-time error, but succeed instead.
  routine-8.f90
  routine-intrinsic-2.f
)
