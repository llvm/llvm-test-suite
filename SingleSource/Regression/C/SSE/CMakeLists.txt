set(DIRS)
set(PARALLEL_DIRS)

set(LEVEL ../../../..)
list(APPEND CFLAGS -msse2)
llvm_singlesource()

llvm_add_subdirectories(${DIRS} ${PARALLEL_DIRS})
