set(DIRS)
set(PARALLEL_DIRS)

set(PROG multitest)
set(CPPFLAGS )
set(LDFLAGS )
llvm_multisource()

llvm_add_subdirectories(${DIRS} ${PARALLEL_DIRS})
