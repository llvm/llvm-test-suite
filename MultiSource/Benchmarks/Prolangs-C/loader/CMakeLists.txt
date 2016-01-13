set(DIRS)
set(PARALLEL_DIRS)

set(LDFLAGS -lm)
set(PROG loader)
llvm_multisource()

llvm_add_subdirectories(${DIRS} ${PARALLEL_DIRS})
