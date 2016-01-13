set(DIRS)
set(PARALLEL_DIRS)

set(PARALLEL_DIRS correlation covariance )

llvm_add_subdirectories(${DIRS} ${PARALLEL_DIRS})
