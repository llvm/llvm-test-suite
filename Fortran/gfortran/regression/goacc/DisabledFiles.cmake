#===------------------------------------------------------------------------===#
#
# Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
# See https://llvm.org/LICENSE.txt for license information.
# SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
#
#===------------------------------------------------------------------------===#

# There are currently no unsupported files.
set(UNSUPPORTED_FILES "")

# There are currently no unimplemented files.
file(GLOB UNIMPLEMENTED_FILES CONFIGURE_DEPENDS
  # unimplemented: OpenACC Atomic construct not lowered yet
  atomic-1.f90
  privatization-1-compute.f90
  privatization-1-compute-loop.f90

  # unimplemented: OpenACC Cache construct not lowered yet
  cache-1.f95

  # unimplemented: OpenACC Routine construct not lowered yet
  classify-routine.f95
  classify-routine-nohost.f95
  kernels-decompose-2.f95
  pr89773.f90
  private-explicit-routine-1.f95
  private-predetermined-routine-1.f95
  privatization-1-routine_gang.f90
  privatization-1-routine_gang-loop.f90
  routine-external-level-of-parallelism-1.f
  routine-level-of-parallelism-1.f90
  routine-module-mod-1.f90
  routine-multiple-directives-1.f90

  # unimplemented: OpenACC Standalone Declarative construct not lowered yet
  declare-3.f95
  pr78260-2.f90
  pr94120-1.f90

  # unimplemented: support for polymorphic types
  derived-chartypes-1.f90
  derived-chartypes-2.f90
  derived-chartypes-3.f90
  derived-chartypes-4.f90
  derived-classtypes-1.f95
  derived-types-2.f90
)

# These tests are disabled because they cause flang to crash.
file(GLOB SKIPPED_FILES CONFIGURE_DEPENDS
  # error: unsupported OpenACC operation:
  array-with-dt-1a.f90
  array-with-dt-1.f90
  array-with-dt-2.f90
  array-with-dt-3.f90
  array-with-dt-4.f90
  attach-descriptor.f90
  kernels-alias-4.f95
  kernels-alias.f95

  # error: unsupported OpenACC operation: acc.firstprivate.recipe
  default_none.f95

  # error: unsupported OpenACC operation: acc.kernels
  default-1.f95
  default-5.f
  kernels-alias-2.f95
  kernels-alias-3.f95
  uninit-copy-clause.f95

  # error: unsupported OpenACC operation: acc.nocreate
  data-tree.f95
  kernels-tree.f95

  # error: unsupported OpenACC operation: acc.parallel
  asyncwait-5.f
  fixed-3.f
  fixed-4.f
  pr85879.f90
  uninit-dim-clause.f95
  uninit-firstprivate-clause.f95

  # error: unsupported OpenACC operation: acc.private.recipe
  private-explicit-kernels-1.f95
  private-explicit-parallel-1.f95

  # error: unsupported OpenACC operation: acc.reduction
  parallel-tree.f95

  # error: unsupported OpenACC operation: acc.reduction.recipe
  combined-directives.f90
  combined_loop.f90
  loop-tree-1.f90
  modules.f95
  orphan-reductions-3.f90
  pr85703.f90
  private-3.f95
  reduction-2.f95

  # error: unsupported OpenACC operation: acc.reduction
  reduction-promotions.f90

  # error: unsupported OpenACC operation: acc.use_device
  host_data-tree.f95
  uninit-use-device-clause.f95

  # error: unsupported OpenACC operation: acc.wait
  wait.f90

  # error: failed to legalize operation 'cf.br'
  classify-kernels.f95
  classify-kernels-parloops.f95
  classify-kernels-unparallelized.f95
  classify-kernels-unparallelized-parloops.f95
  classify-parallel.f95
  classify-serial.f95
  gang-static.f95
  kernels-decompose-1.f95
  kernels-loop-2.f95
  kernels-loop-data-2.f95
  kernels-loop-data-enter-exit-2.f95
  kernels-loop-data-enter-exit.f95
  kernels-loop-data.f95
  kernels-loop-data-update.f95
  kernels-loop.f95
  kernels-loop-inner.f95
  kernels-loop-n.f95
  kernels-loops-adjacent.f95
  kernels-parallel-loop-data-enter-exit.f95
  loop-2-kernels-nested.f95
  loop-2-parallel-nested.f95
  note-parallelism.f90
  pr104717.f90
  pr78027.f90
  pr84217.f90
  pr93464-2.f90
  pr93464.f90
  private-predetermined-kernels-1.f95
  private-predetermined-parallel-1.f95
  tile-3.f90
  tile-lowering.f95
  vector_length.f90

  # error: failed to legalize operation 'cf.cond_br'
  pr77371-1.f90

  # error: null operand found
  array-with-dt-5.f90
  finalize-1.f
  mapping-tests-3.f90
  update-if_present-1.f90

  # error: operation with block successors must terminate its parent block
  fixed-1.f
)

# There tests are disabled because they fail when they should pass.
file(GLOB FAILING_FILES CONFIGURE_DEPENDS
  # These tests fail to compile when compilation is expected to succeed. This
  # is likely because some OpenACC clauses/directives are not yet implemented
  # but they do not trigger an assertion.
  common-block-3.f90
  default-4.f
  nested-function-1.f90
  nested-reductions-1-kernels.f90
  nested-reductions-1-parallel.f90
  nested-reductions-2-kernels.f90
  nested-reductions-2-parallel.f90
  pr71704.f90
  routine-intrinsic-1.f
  specification-part.f90
  uninit-if-clause.f95

  # This test failes to compile when compilation is expected to succeed. It
  # fails with a module not found error. There is a DejaGNU directive
  # "dg-compile-aux-modules" which might have something to do with this.
  routine-module-1.f90
)
