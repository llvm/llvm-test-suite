macro(test_input run_type input output size0 size1)
  llvm_test_run(RUN_TYPE ${run_type}
    ${size0} ${size1} ${input}
    > ${CMAKE_CURRENT_BINARY_DIR}/${output}
    WORKDIR ${BENCHMARK_DIR}/data/${run_type}/input
  )
  llvm_test_verify(RUN_TYPE ${run_type} ${FPCMP}
    ${BENCHMARK_DIR}/data/${run_type}/output/${output}
    ${CMAKE_CURRENT_BINARY_DIR}/${output}
  )
endmacro()

test_input(test null.in null.out 40 19)
test_input(train 2stone9.in 2stone9.out 50 9)
test_input(ref 5stone21.in 5stone21.out 50 21)
test_input(ref 9stone21.in 9stone21.out 50 21)
test_input(ref null.in null.out 50 21)

llvm_test_executable(${PROG} ${Source})
