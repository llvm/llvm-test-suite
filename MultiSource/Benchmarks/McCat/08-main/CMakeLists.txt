set(DIRS)
set(PARALLEL_DIRS)

set(PROG main)
set(LDFLAGS -lm)
set(HASH_PROGRAM_OUTPUT 1)
llvm_multisource()

llvm_add_subdirectories(${DIRS} ${PARALLEL_DIRS})
