set(DIRS)
set(PARALLEL_DIRS)

list(APPEND CFLAGS -msse2)
llvm_singlesource()

llvm_add_subdirectories(${DIRS} ${PARALLEL_DIRS})
