macro(test_input run_type filename size)
  llvm_test_run(RUN_TYPE ${run_type}
    WORKDIR ${CMAKE_CURRENT_BINARY_DIR}
    data/${run_type}/input/${filename} ${size} > ${filename}.out
  )
  llvm_test_verify(RUN_TYPE ${run_type} WORKDIR ${CMAKE_CURRENT_BINARY_DIR}
    ${FPCMP} data/${run_type}/output/${filename}.out ${filename}.out
  )
endmacro()

test_input(train input.compressed 8)
test_input(test input.random 2)
test_input(ref input.source 58)
test_input(ref input.graphic 58)
test_input(ref input.program 58)

llvm_test_executable(256.bzip2 ${Source})
llvm_test_data_spec_default(256.bzip2)
