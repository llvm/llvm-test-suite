set(PARALLEL_DIRS)

set(PARALLEL_DIRS kernels solvers)

llvm_add_subdirectories(${PARALLEL_DIRS})
