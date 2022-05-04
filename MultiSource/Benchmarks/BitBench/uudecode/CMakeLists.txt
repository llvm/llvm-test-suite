set(RUN_OPTIONS input-file)
list(APPEND CFLAGS -Wno-implicit-int)
llvm_multisource(uudecode)
llvm_test_data(uudecode input-file)
