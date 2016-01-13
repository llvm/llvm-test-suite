set(DIRS)
set(PARALLEL_DIRS)

set(LEVEL ../../../..)
set(PROG ks)
list(APPEND RUN_OPTIONS ${CMAKE_CURRENT_SOURCE_DIR}/KL-4.in)
llvm_multisource()

llvm_add_subdirectories(${DIRS} ${PARALLEL_DIRS})
