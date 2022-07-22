list(APPEND CFLAGS -Wno-implicit-function-declaration -Wno-implicit-int -Wno-int-conversion)
set(RUN_OPTIONS parse.y.in -v)
llvm_multisource(mybison)
llvm_test_data(mybison parse.y.in)
