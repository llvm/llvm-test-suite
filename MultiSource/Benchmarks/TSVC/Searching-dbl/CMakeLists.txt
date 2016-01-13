set(DIRS)
set(PARALLEL_DIRS)

set(LEVEL ../../../..)
set(PROG Searching-dbl)
set(LDFLAGS -lm)
list(APPEND CFLAGS -std=gnu99)
set(RUN_OPTIONS 80000 14)
llvm_multisource()

llvm_add_subdirectories(${DIRS} ${PARALLEL_DIRS})
