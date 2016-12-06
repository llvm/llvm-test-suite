list(APPEND LDFLAGS -lm)

include_directories(${BENCHMARK_DIR}/src)
add_definitions(-DFN -DFAST -DCONGRAD_TMP_VECTORS -DDSLASH_TMP_LINKS)

macro(test_input run_type)
  llvm_test_run(RUN_TYPE ${run_type}
    < ${BENCHMARK_DIR}/data/${run_type}/input/su3imp.in
    > ${CMAKE_CURRENT_BINARY_DIR}/su3imp.out
  )
  llvm_test_verify(RUN_TYPE ${run_type} ${FPCMP}
    -r 0.0001 -a 0.0000002
    ${BENCHMARK_DIR}/data/${run_type}/output/su3imp.out
    ${CMAKE_CURRENT_BINARY_DIR}/su3imp.out
  )
endmacro()

test_input(test)
test_input(train)
test_input(ref)

llvm_test_executable(${PROG} ${Source})
