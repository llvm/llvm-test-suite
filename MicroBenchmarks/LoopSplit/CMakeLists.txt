# LoopSplit microbenchmark for #pragma omp split counts(...).
# Copy this directory to llvm-test-suite/MicroBenchmarks/LoopSplit/
# and add: add_subdirectory(LoopSplit) to MicroBenchmarks/CMakeLists.txt.
#
# Configure test-suite with a Clang that supports -fopenmp and -fopenmp-version=60.

llvm_test_run(WORKDIR %S)
llvm_test_verify(%b/${FPCMP} %S/LoopSplit.reference_output %S/LoopSplit.txt)

llvm_test_executable(LoopSplit main.cpp)
llvm_test_data(LoopSplit LoopSplit.reference_output)

target_compile_options(LoopSplit PRIVATE -fopenmp -fopenmp-version=60)
target_link_libraries(LoopSplit benchmark)
