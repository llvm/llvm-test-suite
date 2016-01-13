set(DIRS)
set(PARALLEL_DIRS)

set(PARALLEL_DIRS encode decode)

llvm_add_subdirectories(${DIRS} ${PARALLEL_DIRS})
