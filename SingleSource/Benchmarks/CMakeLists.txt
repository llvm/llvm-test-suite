set(PARALLEL_DIRS)

set(PARALLEL_DIRS Dhrystone CoyoteBench Shootout Shootout-C++ Stanford McGill Misc Misc-C++ Misc-C++-EH BenchmarkGame Adobe-C++ Polybench Linpack SmallPT)
list(APPEND LDFLAGS -lm)

llvm_add_subdirectories(${PARALLEL_DIRS})
