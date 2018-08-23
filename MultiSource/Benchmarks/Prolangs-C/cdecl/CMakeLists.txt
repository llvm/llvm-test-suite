list(APPEND CFLAGS -std=gnu89)
set(RUN_OPTIONS < testset)
llvm_multisource(cdecl)
llvm_test_data(cdecl testset)
