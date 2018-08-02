set(PROG gnugo)
set(HASH_PROGRAM_OUTPUT 1)
set(RUN_OPTIONS < ${CMAKE_CURRENT_SOURCE_DIR}/stdin)
llvm_multisource()
