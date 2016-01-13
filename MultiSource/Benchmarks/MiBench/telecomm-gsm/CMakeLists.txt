set(DIRS)
set(PARALLEL_DIRS)

set(LEVEL ../../../..)
set(PROG telecomm-gsm)
set(CPPFLAGS -DSTUPID_COMPILER -DNeedFunctionPrototypes=1 -DSASR)
set(LDFLAGS -lm)
set(RUN_OPTIONS -fps -c ${CMAKE_CURRENT_SOURCE_DIR}/large.au)
set(HASH_PROGRAM_OUTPUT 1)
llvm_multisource()

llvm_add_subdirectories(${DIRS} ${PARALLEL_DIRS})
