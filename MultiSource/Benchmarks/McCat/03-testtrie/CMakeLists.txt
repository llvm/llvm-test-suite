list(APPEND LDFLAGS -lm)
set(RUN_OPTIONS testtrie.in2)
llvm_multisource(testtrie)
llvm_test_data(testtrie testtrie.in2)
