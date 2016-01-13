set(DIRS)
set(PARALLEL_DIRS)

set(PROG primes)
set(LDFLAGS -lstdc++)
llvm_multisource()

llvm_add_subdirectories(${DIRS} ${PARALLEL_DIRS})
