macro(test_input run_type)
  llvm_test_run(RUN_TYPE ${run_type} WORKDIR ${CMAKE_CURRENT_BINARY_DIR}
    data/${run_type}/input/inp.in > inp.out
  )
  llvm_test_verify(RUN_TYPE ${run_type} WORKDIR ${CMAKE_CURRENT_BINARY_DIR}
    ${FPCMP} data/${run_type}/output/mcf.out mcf.out
  )
  llvm_test_verify(RUN_TYPE ${run_type} WORKDIR ${CMAKE_CURRENT_BINARY_DIR}
    ${FPCMP} data/${run_type}/output/inp.out inp.out
  )
endmacro()

test_input(ref)
test_input(train)
test_input(test)

llvm_test_executable(181.mcf ${Source})
llvm_test_data_spec_default(181.mcf)
