set(DIRS)
set(PARALLEL_DIRS)

set(LEVEL ../../../..)
set(PROG compiler)
llvm_multisource()

llvm_add_subdirectories(${DIRS} ${PARALLEL_DIRS})
