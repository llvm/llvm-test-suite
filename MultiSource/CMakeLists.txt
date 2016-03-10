llvm_add_subdirectories(Applications Benchmarks)
if(NOT TEST_SUITE_BENCHMARKING_ONLY)
  llvm_add_subdirectories(UnitTests)
endif()
