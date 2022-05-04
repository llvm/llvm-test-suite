set(RUN_OPTIONS input.txt)
list(APPEND CFLAGS -Wno-implicit-int)
llvm_multisource(uuencode)
llvm_test_data(uuencode input.txt)
