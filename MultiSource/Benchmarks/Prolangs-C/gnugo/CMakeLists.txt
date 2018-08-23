set(HASH_PROGRAM_OUTPUT 1)
set(RUN_OPTIONS < stdin)
llvm_multisource(gnugo)
llvm_test_data(gnugo stdin)
