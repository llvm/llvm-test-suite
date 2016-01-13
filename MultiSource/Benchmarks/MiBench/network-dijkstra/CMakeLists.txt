set(DIRS)
set(PARALLEL_DIRS)

set(LEVEL ../../../..)
set(PROG network-dijkstra)
set(LDFLAGS -lm)
set(RUN_OPTIONS ${CMAKE_CURRENT_SOURCE_DIR}/input.dat)
llvm_multisource()

llvm_add_subdirectories(${DIRS} ${PARALLEL_DIRS})
