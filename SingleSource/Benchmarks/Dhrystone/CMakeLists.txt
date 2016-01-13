set(DIRS)
set(PARALLEL_DIRS)

list(APPEND LDFLAGS -lm)
llvm_singlesource()

llvm_add_subdirectories(${DIRS} ${PARALLEL_DIRS})
