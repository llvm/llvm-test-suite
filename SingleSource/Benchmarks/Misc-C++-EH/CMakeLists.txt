set(DIRS)
set(PARALLEL_DIRS)

list(APPEND LDFLAGS -lm -lstdc++)
set(LIBS -lstdc++)
set(REQUIRES_EH_SUPPORT 1)
llvm_singlesource()

llvm_add_subdirectories(${DIRS} ${PARALLEL_DIRS})
