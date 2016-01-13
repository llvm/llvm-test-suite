set(DIRS)
set(PARALLEL_DIRS)

set(LEVEL ../../../..)
set(PROG Equivalencing-flt)
set(LDFLAGS -lm)
list(APPEND CFLAGS -std=gnu99)
set(RUN_OPTIONS 3125 5)
llvm_multisource()

llvm_add_subdirectories(${DIRS} ${PARALLEL_DIRS})
