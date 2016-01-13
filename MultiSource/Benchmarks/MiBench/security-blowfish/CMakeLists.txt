set(DIRS)
set(PARALLEL_DIRS)

set(LEVEL ../../../..)
set(PROG security-blowfish)
set(LDFLAGS -lm)
set(RUN_OPTIONS print_test_data)
llvm_multisource()

llvm_add_subdirectories(${DIRS} ${PARALLEL_DIRS})
