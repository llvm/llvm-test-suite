set(DIRS)
set(PARALLEL_DIRS)

set(PROG vor)
set(STDIN_FILENAME ${CMAKE_CURRENT_SOURCE_DIR}/vor.in3)
set(LDFLAGS -lm)
llvm_multisource()

llvm_add_subdirectories(${DIRS} ${PARALLEL_DIRS})
