macro(test_input run_type)
  llvm_test_run(RUN_TYPE ${run_type}
    ${BENCHMARK_DIR}/data/${run_type}/input/inp.in
    > ${CMAKE_CURRENT_BINARY_DIR}/inp.out
    WORKDIR ${CMAKE_CURRENT_BINARY_DIR}
  )
  llvm_test_verify(RUN_TYPE ${run_type} ${FPCMP}
    ${BENCHMARK_DIR}/data/${run_type}/output/mcf.out
    ${CMAKE_CURRENT_BINARY_DIR}/mcf.out
  )
  llvm_test_verify(RUN_TYPE ${run_type} ${FPCMP}
    ${BENCHMARK_DIR}/data/${run_type}/output/inp.out
    ${CMAKE_CURRENT_BINARY_DIR}/inp.out
  )
endmacro()

test_input(ref)
test_input(train)
test_input(test)

llvm_test_executable(${PROG} ${Source})
