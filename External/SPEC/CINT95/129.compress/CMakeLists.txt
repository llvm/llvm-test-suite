# iOS compiler have -Werror=return-value, need to disable this explicitely
# (-w is not enough)
list(APPEND CFLAGS -Wno-return-type)

macro(test_input run_type input output)
  llvm_test_run(RUN_TYPE ${run_type}
    < ${BENCHMARK_DIR}/data/${run_type}/input/${input}
    > ${CMAKE_CURRENT_BINARY_DIR}/${output}
  )
  llvm_test_verify(RUN_TYPE ${run_type} ${FPCMP}
    ${BENCHMARK_DIR}/data/${run_type}/output/${output}
    ${CMAKE_CURRENT_BINARY_DIR}/${output}
  )
endmacro()

test_input(test test.in test.out)
test_input(train test.in test.out)
test_input(ref bigtest.in bigtest.out)

llvm_test_executable(${PROG} ${Source})
