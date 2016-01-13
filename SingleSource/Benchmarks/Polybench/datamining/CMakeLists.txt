set(DIRS)
set(PARALLEL_DIRS)

set(LEVEL ../../../..)
set(PARALLEL_DIRS correlation covariance )
llvm_singlesource()

llvm_add_subdirectories(${DIRS} ${PARALLEL_DIRS})
