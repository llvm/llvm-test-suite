set(DIRS)
set(PARALLEL_DIRS)

set(LEVEL ../../../..)
set(PROG p2c)
list(APPEND CPPFLAGS -DNOMEMOPT)
set(RUN_OPTIONS -v)
set(STDIN_FILENAME ${CMAKE_CURRENT_SOURCE_DIR}/INPUT/mf.p)
llvm_multisource()

llvm_add_subdirectories(${DIRS} ${PARALLEL_DIRS})
