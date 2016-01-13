set(DIRS)
set(PARALLEL_DIRS)

set(PROG vcirc)
set(LDFLAGS -lstdc++)
llvm_multisource()

llvm_add_subdirectories(${DIRS} ${PARALLEL_DIRS})
