llvm_add_subdirectories(Benchmarks)
if(NOT TEST_SUITE_BENCHMARKING_ONLY)
  llvm_add_subdirectories(UnitTests Regression)
endif()
