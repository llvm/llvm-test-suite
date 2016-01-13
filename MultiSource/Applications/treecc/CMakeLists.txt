set(DIRS)
set(PARALLEL_DIRS)

set(LEVEL ../../..)
set(PROG treecc)
set(RUN_OPTIONS -n ${CMAKE_CURRENT_SOURCE_DIR}/examples/expr_cpp.tc)
llvm_multisource()

llvm_add_subdirectories(${DIRS} ${PARALLEL_DIRS})
