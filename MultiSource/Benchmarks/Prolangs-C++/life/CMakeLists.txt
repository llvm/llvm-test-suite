set(DIRS)
set(PARALLEL_DIRS)

set(PROG life)
set(LDFLAGS -lstdc++)
llvm_multisource()

llvm_add_subdirectories(${DIRS} ${PARALLEL_DIRS})
