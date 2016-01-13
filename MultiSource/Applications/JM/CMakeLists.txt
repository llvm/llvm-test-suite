set(DIRS)
set(PARALLEL_DIRS)

set(PARALLEL_DIRS ldecod lencod)

llvm_add_subdirectories(${DIRS} ${PARALLEL_DIRS})
