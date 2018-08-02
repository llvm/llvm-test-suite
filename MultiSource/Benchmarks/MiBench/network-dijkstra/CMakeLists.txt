list(APPEND LDFLAGS -lm)
set(RUN_OPTIONS ${CMAKE_CURRENT_SOURCE_DIR}/input.dat)
llvm_multisource(network-dijkstra)
