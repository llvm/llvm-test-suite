# We need at least clang 3.9 to process the bitcode here.
if(CMAKE_C_COMPILER_ID STREQUAL "Clang" AND
    CMAKE_CXX_COMPILER_ID STREQUAL "Clang" AND
    NOT CMAKE_C_COMPILER_VERSION VERSION_LESS "3.9" AND
    NOT CMAKE_CXX_COMPILER_VERSION VERSION_LESS "3.9")
  set(ENABLE_BITCODE_DEFAULT "True")
endif()

set(TEST_SUITE_ENABLE_BITCODE_TESTS ${ENABLE_BITCODE_DEFAULT} CACHE BOOL "Enable bitcode tests")
if(TEST_SUITE_ENABLE_BITCODE_TESTS)
  llvm_add_subdirectories(Benchmarks)
  if(NOT TEST_SUITE_BENCHMARKING_ONLY)
    llvm_add_subdirectories(Regression)
    if(ARCH STREQUAL "x86" OR ARCH STREQUAL "AArch64" OR ARCH STREQUAL "ARM")
      llvm_add_subdirectories(simd_ops)
    endif()
  endif()
endif()
