macro(test_input run_type)
  llvm_test_run(RUN_TYPE ${run_type}
    ${BENCHMARK_DIR}/data/${run_type}/input/${run_type}.txt
    > ${CMAKE_CURRENT_BINARY_DIR}/${run_type}.out
  )
  llvm_test_verify(RUN_TYPE ${run_type} ${FPCMP}
    ${BENCHMARK_DIR}/data/${run_type}/output/${run_type}.out
    ${CMAKE_CURRENT_BINARY_DIR}/${run_type}.out
  )
endmacro()

test_input(test)
test_input(train)
test_input(ref)

llvm_test_executable(${PROG} ${Source})
