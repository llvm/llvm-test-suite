set(DIRS)
set(PARALLEL_DIRS)

set(LEVEL ../../..)
set(PROG lambda)
list(APPEND LDFLAGS -lstdc++)
list(APPEND LIBS -lstdc++)
set(STDIN_FILENAME ${CMAKE_CURRENT_SOURCE_DIR}/input)
llvm_multisource()

llvm_add_subdirectories(${DIRS} ${PARALLEL_DIRS})
