if(NOT TEST_SUITE_BENCHMARKING_ONLY)
  llvm_add_subdirectories(Regression)
  if(ARCH STREQUAL "x86" OR ARCH STREQUAL "AArch64")
    llvm_add_subdirectories(simd_ops)
  endif()
endif()

