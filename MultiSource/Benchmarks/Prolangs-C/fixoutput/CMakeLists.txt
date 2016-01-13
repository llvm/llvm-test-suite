set(DIRS)
set(PARALLEL_DIRS)

set(PROG fixoutput)
llvm_multisource()

llvm_add_subdirectories(${DIRS} ${PARALLEL_DIRS})
