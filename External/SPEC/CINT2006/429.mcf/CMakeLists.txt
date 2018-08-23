list(APPEND CPPFLAGS -DWANT_STDC_PROTO)

macro(test_input run_type)
  llvm_test_run(RUN_TYPE ${run_type} WORKDIR ${CMAKE_CURRENT_BINARY_DIR}
    data/${run_type}/input/inp.in > inp.out
  )
  llvm_test_verify(RUN_TYPE ${run_type} WORKDIR ${CMAKE_CURRENT_BINARY_DIR}
    ${FPCMP} data/${run_type}/output/inp.out inp.out
  )
  llvm_test_verify(RUN_TYPE ${run_type} WORKDIR ${CMAKE_CURRENT_BINARY_DIR}
    ${FPCMP} data/${run_type}/output/mcf.out mcf.out
  )
endmacro()

test_input(test)
test_input(train)
test_input(ref)

llvm_test_executable(429.mcf ${Source})
llvm_test_data_spec_default(429.mcf)
