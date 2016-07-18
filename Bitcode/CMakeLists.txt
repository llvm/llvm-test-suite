if(NOT TEST_SUITE_BENCHMARKING_ONLY)
  llvm_add_subdirectories(Regression)
  if(ARCH STREQUAL "x86")
    llvm_add_subdirectories(simd_ops)
  endif()
endif()

