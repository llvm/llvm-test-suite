set(DIRS)
set(PARALLEL_DIRS)

set(PROG eks)
set(LDFLAGS -lm)
llvm_multisource()

llvm_add_subdirectories(${DIRS} ${PARALLEL_DIRS})
