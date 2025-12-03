llvm_test_run()

llvm_test_executable(MemFunctions main.cpp)
set_property(TARGET MemFunctions PROPERTY CXX_STANDARD 11)

target_link_libraries(MemFunctions benchmark)
