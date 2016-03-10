if(NOT TEST_SUITE_BENCHMARKING_ONLY)
  llvm_add_subdirectories(2mm 3mm gemm)
endif()
llvm_add_subdirectories(atax bicg cholesky doitgen gemver gesummv mvt symm syr2k syrk trisolv trmm)
