set(DIRS)
set(PARALLEL_DIRS)

set(LEVEL ../../../../..)
set(PARALLEL_DIRS durbin dynprog gramschmidt lu)
llvm_singlesource()

llvm_add_subdirectories(${DIRS} ${PARALLEL_DIRS})
