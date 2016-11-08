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

test_input(train input.combined 32)
test_input(test input.compressed 2)
test_input(ref input.source 60)
test_input(ref input.log 60)
test_input(ref input.graphic 60)
test_input(ref input.random 60)
test_input(ref input.program 60)

llvm_test_executable(${PROG} ${Source})
