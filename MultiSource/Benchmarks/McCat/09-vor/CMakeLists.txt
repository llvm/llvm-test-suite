set(RUN_OPTIONS < vor.in3)
list(APPEND LDFLAGS -lm)
llvm_multisource(vor)
llvm_test_data(vor vor.in3)
