set(DIRS)
set(PARALLEL_DIRS)

set(PARALLEL_DIRS floyd-warshall reg_detect)
llvm_singlesource()

llvm_add_subdirectories(${DIRS} ${PARALLEL_DIRS})
