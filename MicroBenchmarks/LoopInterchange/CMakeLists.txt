llvm_test_run(WORKDIR %S)
llvm_test_verify(%b/${FPCMP} %S/LoopInterchange.reference_output %S/LoopInterchange.txt)

llvm_test_executable(LoopInterchange main.cpp)
llvm_test_data(LoopInterchange LoopInterchange.reference_output)

target_link_libraries(LoopInterchange benchmark)
