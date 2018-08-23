list(APPEND CPPFLAGS -DBASE_ITERATIONS=25)
list(APPEND LDFLAGS -lm)

llvm_multisource(nbench)
llvm_test_data(nbench NNET.DAT)
