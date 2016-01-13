set(DIRS)
set(PARALLEL_DIRS)

set(PARALLEL_DIRS g721encode )
llvm_multisource()

llvm_add_subdirectories(${DIRS} ${PARALLEL_DIRS})
