macro(test_input run_type input output)
  llvm_test_run(RUN_TYPE ${run_type}
    ${input}
    > ${CMAKE_CURRENT_BINARY_DIR}/${output}
    WORKDIR ${BENCHMARK_DIR}/data/${run_type}/input
  )
  llvm_test_verify(RUN_TYPE ${run_type} ${FPCMP}
    -r 0.001
    ${BENCHMARK_DIR}/data/${run_type}/output/${output}
    ${CMAKE_CURRENT_BINARY_DIR}/${output}
  )
endmacro()

test_input(test lake.cfg lake.out)
test_input(train BigLakes1024.cfg BigLakes1024.out)
test_input(train rivers1.cfg rivers1.out)
test_input(ref BigLakes2048.cfg BigLakes2048.out)
test_input(ref rivers.cfg rivers.out)

llvm_test_executable(${PROG} ${Source})
