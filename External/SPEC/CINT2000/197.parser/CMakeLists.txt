if(TARGET_OS STREQUAL "Darwin")
  list(APPEND CPPFLAGS -D_ANSI_SOURCE=1)
endif()

macro(test_input run_type)
  llvm_test_run(RUN_TYPE ${run_type}
    2.1.dict -batch
    < ${BENCHMARK_DIR}/data/${run_type}/input/${run_type}.in
    > ${CMAKE_CURRENT_BINARY_DIR}/${run_type}.out
    WORKDIR ${BENCHMARK_DIR}/data/all/input
  )
  llvm_test_verify(RUN_TYPE ${run_type} ${FPCMP}
    ${BENCHMARK_DIR}/data/${run_type}/output/${run_type}.out
    ${CMAKE_CURRENT_BINARY_DIR}/${run_type}.out
  )
endmacro()

test_input(ref)
test_input(train)
test_input(test)

llvm_test_executable(${PROG} ${Source})
