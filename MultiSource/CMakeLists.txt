llvm_add_subdirectories(Applications Benchmarks)
if(NOT DEFINED BENCHMARKING_ONLY)
  llvm_add_subdirectories(UnitTests)
endif()
