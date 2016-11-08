macro(test_input run_type input size output)
  llvm_test_run(RUN_TYPE ${run_type}
    ${input}
    ${size}
    > ${CMAKE_CURRENT_BINARY_DIR}/${output}
  )
  llvm_test_verify(RUN_TYPE ${run_type} ${FPCMP}
    ${BENCHMARK_DIR}/data/${run_type}/output/${output}
    ${CMAKE_CURRENT_BINARY_DIR}/${output}
  )
endmacro()

test_input(test ${BENCHMARK_DIR}/data/all/input/input.program 5 input.program.out)
test_input(test ${BENCHMARK_DIR}/data/test/input/dryer.jpg 2 dryer.jpg.out)

test_input(train ${BENCHMARK_DIR}/data/all/input/input.program 10 input.program.out)
test_input(train ${BENCHMARK_DIR}/data/train/input/byoudoin.jpg 5 byoudoin.jpg.out)
test_input(train ${BENCHMARK_DIR}/data/all/input/input.combined 80 input.combined.out)

test_input(ref ${BENCHMARK_DIR}/data/ref/input/input.source 280 input.source.out)
test_input(ref ${BENCHMARK_DIR}/data/ref/input/chicken.jpg 30 chicken.jpg.out)
test_input(ref ${BENCHMARK_DIR}/data/ref/input/liberty.jpg 30 liberty.jpg.out)
test_input(ref ${BENCHMARK_DIR}/data/all/input/input.program 280 input.program.out)
test_input(ref ${BENCHMARK_DIR}/data/ref/input/text.html 280 text.html.out)
test_input(ref ${BENCHMARK_DIR}/data/all/input/input.combined 200 input.combined.out)

llvm_test_executable(${PROG} ${Source})
