set(DIRS)
set(PARALLEL_DIRS)

set(PARALLEL_DIRS kernels solvers)

llvm_add_subdirectories(${DIRS} ${PARALLEL_DIRS})
