list(APPEND LDFLAGS -lm)
set(RUN_OPTIONS input.dat)
llvm_multisource(network-dijkstra)
llvm_test_data(network-dijkstra input.dat)
