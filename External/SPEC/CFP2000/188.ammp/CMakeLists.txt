macro(test_input run_type)
  llvm_test_run(RUN_TYPE ${run_type}
    WORKDIR ${CMAKE_CURRENT_BINARY_DIR}/data/${run_type}/input
    < ammp.in > ${CMAKE_CURRENT_BINARY_DIR}/ammp.out
  )
  llvm_test_verify(RUN_TYPE ${run_type} WORKDIR ${CMAKE_CURRENT_BINARY_DIR}
    ${FPCMP} -r 0.003 -a 0.0001 data/${run_type}/output/ammp.out ammp.out
  )
endmacro()

test_input(test)
test_input(train)
test_input(ref)

llvm_test_executable(188.ammp ${Source})
llvm_test_data_spec_default(188.ammp)
