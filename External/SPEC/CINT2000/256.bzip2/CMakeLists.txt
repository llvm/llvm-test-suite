macro(test_input run_type filename size)
  llvm_test_run(RUN_TYPE ${run_type}
    ${BENCHMARK_DIR}/data/${run_type}/input/${filename}
    ${size}
    > ${CMAKE_CURRENT_BINARY_DIR}/${filename}.out
  )
  llvm_test_verify(RUN_TYPE ${run_type} ${FPCMP}
    ${BENCHMARK_DIR}/data/${run_type}/output/${filename}.out
    ${CMAKE_CURRENT_BINARY_DIR}/${filename}.out
  )
endmacro()

test_input(train input.compressed 8)
test_input(test input.random 2)
test_input(ref input.source 58)
test_input(ref input.graphic 58)
test_input(ref input.program 58)

llvm_test_executable(${PROG} ${Source})
