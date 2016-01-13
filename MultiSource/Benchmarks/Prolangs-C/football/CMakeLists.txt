set(DIRS)
set(PARALLEL_DIRS)

set(PROG football)
llvm_multisource()

llvm_add_subdirectories(${DIRS} ${PARALLEL_DIRS})
