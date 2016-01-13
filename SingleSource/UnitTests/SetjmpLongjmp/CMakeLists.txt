set(DIRS)
set(PARALLEL_DIRS)

set(DIRS C C++)
set(LEVEL ../../..)
llvm_singlesource()

llvm_add_subdirectories(${DIRS} ${PARALLEL_DIRS})
