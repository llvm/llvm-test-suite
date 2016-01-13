set(DIRS)
set(PARALLEL_DIRS)

set(LEVEL ../../../..)
set(PROG Symbolics-flt)
set(LDFLAGS -lm)
list(APPEND CFLAGS -std=gnu99)
set(RUN_OPTIONS 9090 5)
llvm_multisource()

llvm_add_subdirectories(${DIRS} ${PARALLEL_DIRS})
