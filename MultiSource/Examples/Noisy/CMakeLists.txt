set(DIRS)
set(PARALLEL_DIRS)

set(LEVEL ../../..)
set(PROG Noisy)
set(CPPFLAGS )
set(LDFLAGS )
llvm_multisource()

llvm_add_subdirectories(${DIRS} ${PARALLEL_DIRS})
