set(DIRS)
set(PARALLEL_DIRS)

set(DIRS )
set(LEVEL ../../../..)
llvm_singlesource()

llvm_add_subdirectories(${DIRS} ${PARALLEL_DIRS})
