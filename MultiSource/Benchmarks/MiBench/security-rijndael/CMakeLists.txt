set(DIRS)
set(PARALLEL_DIRS)

set(LEVEL ../../../..)
set(PROG security-rijndael)
set(LDFLAGS -lm)
set(RUN_OPTIONS ${CMAKE_CURRENT_SOURCE_DIR}/output_large.enc Output/output_large.dec d 1234567890abcdeffedcba09876543211234567890abcdeffedcba0987654321)
set(HASH_PROGRAM_OUTPUT 1)
llvm_multisource()

llvm_add_subdirectories(${DIRS} ${PARALLEL_DIRS})
