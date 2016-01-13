set(DIRS)
set(PARALLEL_DIRS)

set(PROG objects)
set(LIBS -lstdc++)
set(LDFLAGS -lstdc++)
llvm_multisource()

llvm_add_subdirectories(${DIRS} ${PARALLEL_DIRS})
