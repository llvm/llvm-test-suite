set(PARALLEL_DIRS)

set(PARALLEL_DIRS Regression Benchmarks)
if(NOT DEFINED BENCHMARKING_ONLY)
  list(APPEND PARALLEL_DIRS UnitTests)
endif()

llvm_add_subdirectories(${PARALLEL_DIRS})
