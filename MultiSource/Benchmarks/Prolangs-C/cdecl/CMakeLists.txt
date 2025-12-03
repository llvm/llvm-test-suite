set(RUN_OPTIONS < testset)
llvm_multisource(cdecl)
set_property(TARGET cdecl PROPERTY C_STANDARD 90)
llvm_test_data(cdecl testset)
