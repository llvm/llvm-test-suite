set(DIRS)
set(PARALLEL_DIRS)

set(PROG imp)
list(APPEND RUN_OPTIONS ${CMAKE_CURRENT_SOURCE_DIR}/sg01.imp)
set(LDFLAGS -lm)
llvm_multisource()

llvm_add_subdirectories(${DIRS} ${PARALLEL_DIRS})
