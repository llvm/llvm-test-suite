list(APPEND CFLAGS -Wno-int-conversion)
set(RUN_OPTIONS -v ALL < main.c)
llvm_multisource(unix-smail)
llvm_test_data(unix-smail main.c)
