llvm_add_subdirectories(Regression Benchmarks)
if(NOT DEFINED BENCHMARKING_ONLY)
  llvm_add_subdirectories(UnitTests)
endif()

