list(APPEND CPPFLAGS -std=c++11)

llvm_test_run()

llvm_test_executable(MemFunctions main.cpp)

target_link_libraries(MemFunctions benchmark)
