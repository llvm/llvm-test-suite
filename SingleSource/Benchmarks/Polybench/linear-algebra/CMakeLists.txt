set(DIRS)
set(PARALLEL_DIRS)

set(LEVEL ../../../..)
set(PARALLEL_DIRS kernels solvers)
llvm_singlesource()

llvm_add_subdirectories(${DIRS} ${PARALLEL_DIRS})
