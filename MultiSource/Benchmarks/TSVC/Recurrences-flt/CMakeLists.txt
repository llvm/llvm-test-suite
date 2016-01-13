set(DIRS)
set(PARALLEL_DIRS)

set(LEVEL ../../../..)
set(PROG Recurrences-flt)
set(LDFLAGS -lm)
list(APPEND CFLAGS -std=gnu99)
set(RUN_OPTIONS 20000 5)
llvm_multisource()

llvm_add_subdirectories(${DIRS} ${PARALLEL_DIRS})
