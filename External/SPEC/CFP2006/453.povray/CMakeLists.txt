list(APPEND LDFLAGS -lm)

macro(test_input run_type stdout_reltol)
  llvm_test_run(RUN_TYPE ${run_type}
    WORKDIR ${CMAKE_CURRENT_BINARY_DIR}/data/${run_type}/input
    SPEC-benchmark-${run_type}.ini
  )
  llvm_test_verify(RUN_TYPE ${run_type} WORKDIR ${CMAKE_CURRENT_BINARY_DIR}
    ${FPCMP} -r ${stdout_reltol}
    data/${run_type}/output/SPEC-benchmark.log
    data/${run_type}/input/SPEC-benchmark.log
  )
  llvm_test_verify(RUN_TYPE ${run_type} WORKDIR ${CMAKE_CURRENT_BINARY_DIR}
    ${FPCMP}
    data/${run_type}/output/SPEC-benchmark.tga
    data/${run_type}/input/SPEC-benchmark.tga
  )
endmacro()

test_input(test 0.0002)
test_input(train 0.00005)
test_input(ref 0.00005)

llvm_test_executable(453.povray ${Source})
llvm_test_data_spec(453.povray
  data/test/output
  data/train/output
  data/ref/output
)

llvm_copy_dir(453.povray ${CMAKE_CURRENT_BINARY_DIR}/data/test/input
  ${BENCHMARK_DIR}/data/test/input
  ${BENCHMARK_DIR}/data/all/input
)
llvm_copy_dir(453.povray ${CMAKE_CURRENT_BINARY_DIR}/data/train/input
  ${BENCHMARK_DIR}/data/train/input
  ${BENCHMARK_DIR}/data/all/input
)
llvm_copy_dir(453.povray ${CMAKE_CURRENT_BINARY_DIR}/data/ref/input
  ${BENCHMARK_DIR}/data/ref/input
  ${BENCHMARK_DIR}/data/all/input
)
