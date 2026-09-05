llvm_test_run()

llvm_test_executable(VectorMulI8Bench
  VectorMulI8Bench.cpp
)

target_link_libraries(VectorMulI8Bench benchmark)
