set(RUN_OPTIONS input.txt)
llvm_multisource(uuencode)
llvm_test_data(uuencode input.txt)
