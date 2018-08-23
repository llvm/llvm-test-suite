add_definitions(-DHAVE_STRERROR -DHAS_MKDIR -DHAS_RMDIR -DI_TIME)

macro(test_input run_type basename)
  llvm_test_run(RUN_TYPE ${run_type}
    WORKDIR ${CMAKE_CURRENT_BINARY_DIR}/data/${run_type}/input
    ${basename}.pl
    < ${basename}.in
    > ${CMAKE_CURRENT_BINARY_DIR}/${basename}.out
  )
  llvm_test_verify(RUN_TYPE ${run_type} WORKDIR ${CMAKE_CURRENT_BINARY_DIR}
    ${FPCMP} data/${run_type}/output/${basename}.out ${basename}.out
  )
endmacro()

test_input(test jumble)
test_input(test primes)
test_input(train jumble)
test_input(train primes)
test_input(train scrabbl)
test_input(ref primes)
test_input(ref scrabbl)

llvm_test_executable(134.perl ${Source})
llvm_test_data_spec_default(134.perl)
