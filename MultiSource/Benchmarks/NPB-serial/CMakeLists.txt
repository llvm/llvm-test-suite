set(DIRS)
set(PARALLEL_DIRS)

set(PARALLEL_DIRS is )
llvm_multisource()

llvm_add_subdirectories(${DIRS} ${PARALLEL_DIRS})
