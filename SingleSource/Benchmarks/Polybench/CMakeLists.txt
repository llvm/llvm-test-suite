set(DIRS)
set(PARALLEL_DIRS)

set(LEVEL ../../..)
set(PARALLEL_DIRS datamining linear-algebra medley stencils)
llvm_singlesource()

llvm_add_subdirectories(${DIRS} ${PARALLEL_DIRS})
