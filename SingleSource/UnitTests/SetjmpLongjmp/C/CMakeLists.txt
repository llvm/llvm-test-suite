set(DIRS)
set(PARALLEL_DIRS)

set(LEVEL ../../../..)
set(REQUIRES_EH_SUPPORT 1)
llvm_singlesource()

llvm_add_subdirectories(${DIRS} ${PARALLEL_DIRS})
