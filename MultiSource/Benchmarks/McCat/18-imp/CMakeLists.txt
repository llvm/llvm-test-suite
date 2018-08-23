list(APPEND LDFLAGS -lm)
set(RUN_OPTIONS ./sg01.imp)
llvm_multisource(imp)
llvm_test_data(imp sg01.imp sg01.pgm)
