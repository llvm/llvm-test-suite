set(DIRS)
set(PARALLEL_DIRS)

list(APPEND LDFLAGS -lm)
set(HASH_PROGRAM_OUTPUT 1)
llvm_singlesource()

llvm_add_subdirectories(${DIRS} ${PARALLEL_DIRS})
