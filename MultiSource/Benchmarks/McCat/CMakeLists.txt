llvm_add_subdirectories(01-qbsort 04-bisect 08-main 12-IOtest 17-bintr 03-testtrie 05-eks 09-vor 18-imp)
if(NOT TEST_SUITE_BENCHMARKING_ONLY)
  llvm_add_subdirectories(15-trie)
endif()
