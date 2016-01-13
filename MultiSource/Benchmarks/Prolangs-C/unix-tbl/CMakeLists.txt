set(DIRS)
set(PARALLEL_DIRS)

set(LEVEL ../../../..)
set(PROG unix-tbl)
llvm_multisource()

llvm_add_subdirectories(${DIRS} ${PARALLEL_DIRS})
