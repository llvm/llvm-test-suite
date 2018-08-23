list(APPEND LDFLAGS -lm)
set(RUN_OPTIONS < bnchmrk.in1)
llvm_multisource(bintr)
llvm_test_data(bintr bnchmrk.in1)
