# Try and enable C++11. Don't use C++14 because it doesn't work in some
# configurations.
add_cxx_compiler_flag(-std=c++11)
if (NOT HAVE_CXX_FLAG_STD_CXX11)
  add_cxx_compiler_flag(-std=c++0x)
endif ()

llvm_test_run()

llvm_test_executable(SLPVectorizationBenchmarks
  main.cpp
  Versioning.cpp)

target_link_libraries(SLPVectorizationBenchmarks benchmark)
