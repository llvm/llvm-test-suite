llvm_test_run(WORKDIR ${CMAKE_CURRENT_BINARY_DIR})

llvm_test_verify(WORKDIR ${CMAKE_CURRENT_BINARY_DIR}
    ${FPCMP} LoopInterchange.reference_output LoopInterchange.txt
)
llvm_test_executable(LoopInterchange main.cpp)
llvm_test_data(LoopInterchange LoopInterchange.reference_output)

target_link_libraries(LoopInterchange benchmark)
