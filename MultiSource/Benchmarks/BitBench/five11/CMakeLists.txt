set(RUN_OPTIONS input-file)
llvm_multisource(five11)
set_property(TARGET five11 PROPERTY C_STANDARD 17)
llvm_test_data(five11 input-file)
