set(RUN_OPTIONS -n examples/expr_cpp.tc)
llvm_multisource(treecc)
llvm_test_data(treecc examples/expr_cpp.tc)
