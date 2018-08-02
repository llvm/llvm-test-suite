list(APPEND LDFLAGS -lm)
set(RUN_OPTIONS print_test_data)
llvm_multisource(security-blowfish)
