list(APPEND CPPFLAGS -std=c++11 -ffast-math)

llvm_test_verify_hash_program_output(output.txt)
llvm_test_verify(WORKDIR ${CMAKE_CURRENT_BINARY_DIR}
  ${FPCMP} harris.reference_output output.txt
)
llvm_test_run(WORKDIR ${CMAKE_CURRENT_BINARY_DIR})
llvm_test_executable(harris harrisKernel.cpp main.cpp)
target_link_libraries(harris benchmark)
llvm_test_data(harris harris.reference_output)
