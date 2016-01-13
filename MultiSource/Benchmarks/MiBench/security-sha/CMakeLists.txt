set(DIRS)
set(PARALLEL_DIRS)

set(PROG security-sha)
set(LDFLAGS -lm)
set(RUN_OPTIONS ${CMAKE_CURRENT_SOURCE_DIR}/input_large.asc )
llvm_multisource()

llvm_add_subdirectories(${DIRS} ${PARALLEL_DIRS})
