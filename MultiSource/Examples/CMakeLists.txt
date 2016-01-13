set(DIRS)
set(PARALLEL_DIRS)

set(LEVEL ../..)
set(PARALLEL_DIRS MultipleResults)
llvm_multisource()

llvm_add_subdirectories(${DIRS} ${PARALLEL_DIRS})
