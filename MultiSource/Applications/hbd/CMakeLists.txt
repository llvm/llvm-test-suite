list(APPEND CPPFLAGS -DHAVE_CONFIG_H)
set(RUN_OPTIONS Sort.class)
llvm_multisource(hbd)
llvm_test_data(hbd Sort.class)
