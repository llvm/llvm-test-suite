llvm_add_subdirectories(Benchmarks)
if(NOT TEST_SUITE_BENCHMARKING_ONLY)
  llvm_add_subdirectories(UnitTests Regression)
endif()

file(COPY lit.local.cfg DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")
