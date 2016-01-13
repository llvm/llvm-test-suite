set(DIRS)
set(PARALLEL_DIRS)

set(DIRS )
llvm_singlesource()

llvm_add_subdirectories(${DIRS} ${PARALLEL_DIRS})
