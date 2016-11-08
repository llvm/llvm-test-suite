add_definitions(-DHAVE_STRERROR -DHAS_MKDIR -DHAS_RMDIR -DI_TIME)

macro(test_input run_type basename)
  llvm_test_run(RUN_TYPE ${run_type}
    ${basename}.pl
    < ${BENCHMARK_DIR}/data/${run_type}/input/${basename}.in
    > ${CMAKE_CURRENT_BINARY_DIR}/${basename}.out
    WORKDIR ${BENCHMARK_DIR}/data/${run_type}/input
  )
  llvm_test_verify(RUN_TYPE ${run_type} ${FPCMP}
    ${BENCHMARK_DIR}/data/${run_type}/output/${basename}.out
    ${CMAKE_CURRENT_BINARY_DIR}/${basename}.out
  )
endmacro()

test_input(test jumble)
test_input(test primes)
test_input(train jumble)
test_input(train primes)
test_input(train scrabbl)
test_input(ref primes)
test_input(ref scrabbl)

llvm_test_executable(${PROG} ${Source})
