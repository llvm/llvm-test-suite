set(DIRS)
set(PARALLEL_DIRS)

set(PARALLEL_DIRS ldecod lencod)
llvm_multisource()

llvm_add_subdirectories(${DIRS} ${PARALLEL_DIRS})
