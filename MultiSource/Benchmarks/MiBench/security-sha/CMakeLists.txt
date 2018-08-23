list(APPEND LDFLAGS -lm)
set(RUN_OPTIONS input_large.asc)
llvm_multisource(security-sha)
llvm_test_data(security-sha input_large.asc)
