macro(test_input run_type)
  llvm_test_run(RUN_TYPE ${run_type}
    WORKDIR ${BENCHMARK_DIR}/data/${run_type}/input
    < ${BENCHMARK_DIR}/data/${run_type}/input/ammp.in
    > "${CMAKE_CURRENT_BINARY_DIR}/ammp.out"
  )
  llvm_test_verify(RUN_TYPE ${run_type} ${FPCMP}
    -r 0.003 -a 0.0001
    "${BENCHMARK_DIR}/data/${run_type}/output/ammp.out"
    "${CMAKE_CURRENT_BINARY_DIR}/ammp.out"
  )
endmacro()

test_input(test)
test_input(train)
test_input(ref)

llvm_test_executable(${PROG} ${Source})
