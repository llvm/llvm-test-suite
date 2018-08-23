list(APPEND LDFLAGS -lm)
set(RUN_OPTIONS -x medsmall1.adj_list)
llvm_multisource(PathFinder)
llvm_test_data(PathFinder medsmall1.adj_list)
