set(DIRS)
set(PARALLEL_DIRS)

set(PROG aha)
set(CPPFLAGS )
set(LDFLAGS )
llvm_multisource()

llvm_add_subdirectories(${DIRS} ${PARALLEL_DIRS})
