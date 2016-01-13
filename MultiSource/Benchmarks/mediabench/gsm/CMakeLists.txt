set(DIRS)
set(PARALLEL_DIRS)

set(LEVEL ../../../..)
set(PARALLEL_DIRS toast )
llvm_multisource()

llvm_add_subdirectories(${DIRS} ${PARALLEL_DIRS})
