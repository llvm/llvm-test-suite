set(DIRS)
set(PARALLEL_DIRS)

set(LEVEL ../../../..)
set(PROG office)
set(LDFLAGS -lstdc++)
llvm_multisource()

llvm_add_subdirectories(${DIRS} ${PARALLEL_DIRS})
