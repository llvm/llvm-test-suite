set(DIRS)
set(PARALLEL_DIRS)

set(PROG deriv1)
set(LDFLAGS -lstdc++)
llvm_multisource()

llvm_add_subdirectories(${DIRS} ${PARALLEL_DIRS})
