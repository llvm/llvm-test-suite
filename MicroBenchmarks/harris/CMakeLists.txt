list(APPEND CPPFLAGS -std=c++11 -ffast-math)

set(REFERENCE_OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/harris.reference_output)
llvm_test_verify("${CMAKE_SOURCE_DIR}/HashProgramOutput.sh ${CMAKE_CURRENT_BINARY_DIR}/output.txt")
llvm_test_verify("${FPCMP} ${CMAKE_CURRENT_BINARY_DIR}/output.txt ${REFERENCE_OUTPUT}")
llvm_test_run(WORKDIR ${CMAKE_CURRENT_BINARY_DIR})
llvm_test_executable(harris harrisKernel.cpp  main.cpp)
target_link_libraries(harris benchmark)
