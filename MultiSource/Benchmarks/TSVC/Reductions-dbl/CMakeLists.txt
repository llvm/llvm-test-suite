set(DIRS)
set(PARALLEL_DIRS)

set(PROG Reductions-dbl)
set(LDFLAGS -lm)
list(APPEND CFLAGS -std=gnu99)
set(RUN_OPTIONS 1670 14)
llvm_multisource()

llvm_add_subdirectories(${DIRS} ${PARALLEL_DIRS})
