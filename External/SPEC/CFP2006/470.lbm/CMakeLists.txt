include_directories(${BENCHMARK_DIR}/src)

list(APPEND LDFLAGS -lm)

macro(test_input run_type)
  llvm_test_run(RUN_TYPE ${run_type}
    WORKDIR ${CMAKE_CURRENT_BINARY_DIR}/data/${run_type}/input
    ${ARGN}
    > ${CMAKE_CURRENT_BINARY_DIR}/lbm.out
  )
  llvm_test_verify(RUN_TYPE ${run_type} WORKDIR ${CMAKE_CURRENT_BINARY_DIR}
    ${FPCMP} -a 0.0000001
    data/${run_type}/output/lbm.out
    lbm.out
  )
endmacro()

test_input(test   20 reference.dat 0 1 100_100_130_cf_a.of)
test_input(train 300 reference.dat 0 1 100_100_130_cf_b.of)
test_input(ref  3000 reference.dat 0 0 100_100_130_ldc.of)

llvm_test_executable(470.lbm ${Source})
llvm_test_data_spec_default(470.lbm)
