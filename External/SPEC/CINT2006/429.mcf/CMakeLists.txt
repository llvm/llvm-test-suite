list(APPEND CPPFLAS -DWANT_STDC_PROTO)

macro(test_input run_type)
  llvm_test_run(RUN_TYPE ${run_type}
    ${BENCHMARK_DIR}/data/${run_type}/input/inp.in
    > ${CMAKE_CURRENT_BINARY_DIR}/inp.out
    WORKDIR ${CMAKE_CURRENT_BINARY_DIR}
  )
  llvm_test_verify(RUN_TYPE ${run_type} ${FPCMP}
    ${BENCHMARK_DIR}/data/${run_type}/output/inp.out
    ${CMAKE_CURRENT_BINARY_DIR}/inp.out
  )
  llvm_test_verify(RUN_TYPE ${run_type} ${FPCMP}
    ${BENCHMARK_DIR}/data/${run_type}/output/mcf.out
    ${CMAKE_CURRENT_BINARY_DIR}/mcf.out
  )
endmacro()

test_input(test)
test_input(train)
test_input(ref)

llvm_test_executable(${PROG} ${Source})
