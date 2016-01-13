set(DIRS)
set(PARALLEL_DIRS)

set(PROG mybison)
set(RUN_OPTIONS ${CMAKE_CURRENT_SOURCE_DIR}/parse.y.in -v)
llvm_multisource()

llvm_add_subdirectories(${DIRS} ${PARALLEL_DIRS})
