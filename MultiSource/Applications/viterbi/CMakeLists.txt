list(APPEND CPPFLAGS -I${CMAKE_CURRENT_SOURCE_DIR} -DPROJ_SRC_DIR=".")
llvm_multisource(viterbi)
llvm_test_data(viterbi Dist_demux)
