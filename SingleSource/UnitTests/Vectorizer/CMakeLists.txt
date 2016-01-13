set(DIRS)
set(PARALLEL_DIRS)

list(APPEND LDFLAGS -lstdc++)
llvm_singlesource()

llvm_add_subdirectories(${DIRS} ${PARALLEL_DIRS})
