set(DIRS)
set(PARALLEL_DIRS)

set(PARALLEL_DIRS SMG2000 )
llvm_multisource()

llvm_add_subdirectories(${DIRS} ${PARALLEL_DIRS})
