set(DIRS)
set(PARALLEL_DIRS)

set(PROG automotive-bitcount)
set(LDFLAGS -lm)
set(RUN_OPTIONS 1125000)
llvm_multisource()

llvm_add_subdirectories(${DIRS} ${PARALLEL_DIRS})
