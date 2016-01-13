set(DIRS)
set(PARALLEL_DIRS)

set(REQUIRES_EH_SUPPORT 1)
list(APPEND LDFLAGS -lstdc++)
llvm_singlesource()

llvm_add_subdirectories(${DIRS} ${PARALLEL_DIRS})
