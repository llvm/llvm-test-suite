list(APPEND CPPFLAGS -DNOMEMOPT)
set(RUN_OPTIONS -v < INPUT/mf.p)
llvm_multisource(p2c)
llvm_test_data(p2c INPUT/mf.p)
