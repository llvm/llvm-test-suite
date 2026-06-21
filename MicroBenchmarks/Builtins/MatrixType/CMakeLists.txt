# Enable matrix types benchmarks for compilers supporting -fenable-matrix.
check_c_compiler_flag(-fenable-matrix COMPILER_HAS_MATRIX_FLAG)
if (COMPILER_HAS_MATRIX_FLAG)
  set(CMAKE_CXX_STANDARD 20)
  set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

  llvm_test_run()

  set_property(SOURCE main.cpp PROPERTY COMPILE_FLAGS -fenable-matrix)

  llvm_test_executable(MatrixType main.cpp)
  target_link_libraries(MatrixType benchmark)
endif()
