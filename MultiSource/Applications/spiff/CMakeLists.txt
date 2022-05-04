list(APPEND CFLAGS -Wno-implicit-int)
set(RUN_OPTIONS Sample.3 Sample.4)
llvm_multisource(spiff)
llvm_test_data(spiff Sample.3 Sample.4)
