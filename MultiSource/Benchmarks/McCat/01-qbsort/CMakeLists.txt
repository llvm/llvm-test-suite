set(RUN_OPTIONS 1000 < ${CMAKE_CURRENT_SOURCE_DIR}/benchmark.in3)
list(APPEND LDFLAGS -lm)
set(HASH_PROGRAM_OUTPUT 1)
llvm_multisource(qbsort)
