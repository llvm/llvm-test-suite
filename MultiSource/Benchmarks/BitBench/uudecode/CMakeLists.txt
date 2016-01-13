set(DIRS)
set(PARALLEL_DIRS)

set(PROG uudecode)
set(LDFLAGS )
set(RUN_OPTIONS ${CMAKE_CURRENT_SOURCE_DIR}/input-file)
llvm_multisource()

llvm_add_subdirectories(${DIRS} ${PARALLEL_DIRS})
