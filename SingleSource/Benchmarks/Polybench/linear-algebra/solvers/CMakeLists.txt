set(PARALLEL_DIRS)

set(PARALLEL_DIRS durbin dynprog gramschmidt lu)

llvm_add_subdirectories(${PARALLEL_DIRS})
