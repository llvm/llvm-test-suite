set(DIRS)
set(PARALLEL_DIRS)

set(LEVEL ../../..)
set(PROG kc)
set(CPPFLAGS -I${CMAKE_CURRENT_SOURCE_DIR} -DYYDEBUG=1)
set(LDFLAGS -lstdc++)
list(APPEND LIBS -lstdc++)
set(RUN_OPTIONS -f test  -o -v -s kcc ${CMAKE_CURRENT_SOURCE_DIR}/inputs/f3.k ${CMAKE_CURRENT_SOURCE_DIR}/inputs/f2.k ${CMAKE_CURRENT_SOURCE_DIR}/inputs/f1.k)
set(HASH_PROGRAM_OUTPUT 1)
llvm_multisource()

llvm_add_subdirectories(${DIRS} ${PARALLEL_DIRS})
