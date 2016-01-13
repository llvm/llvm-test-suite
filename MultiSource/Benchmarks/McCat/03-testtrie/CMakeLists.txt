set(DIRS)
set(PARALLEL_DIRS)

set(LEVEL ../../../..)
set(PROG testtrie)
set(LDFLAGS -lm)
list(APPEND RUN_OPTIONS ${CMAKE_CURRENT_SOURCE_DIR}/testtrie.in2)
llvm_multisource()

llvm_add_subdirectories(${DIRS} ${PARALLEL_DIRS})
