macro(test_input run_type)
  llvm_test_run(RUN_TYPE ${run_type} WORKDIR ${CMAKE_CURRENT_BINARY_DIR}
    < data/${run_type}/input/inp.in > inp.out
  )
  llvm_test_verify(RUN_TYPE ${run_type} WORKDIR ${CMAKE_CURRENT_BINARY_DIR}
    ${FPCMP} -r 0.00001 data/${run_type}/output/inp.out inp.out
  )
endmacro()

test_input(test)
test_input(train)
test_input(ref)

llvm_test_executable(183.equake ${Source})
llvm_test_data_spec_default(183.equake)
