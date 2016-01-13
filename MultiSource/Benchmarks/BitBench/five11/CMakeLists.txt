set(DIRS)
set(PARALLEL_DIRS)

set(LEVEL ../../../..)
set(PROG five11)
set(LDFLAGS )
set(RUN_OPTIONS ${CMAKE_CURRENT_SOURCE_DIR}/input-file)
llvm_multisource()

llvm_add_subdirectories(${DIRS} ${PARALLEL_DIRS})
