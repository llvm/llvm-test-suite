list(APPEND LDFLAGS -lm)

macro(test_input run_type stdout_reltol)
  llvm_test_run(RUN_TYPE ${run_type}
    SPEC-benchmark-${run_type}.ini
    WORKDIR ${CMAKE_CURRENT_BINARY_DIR}/data/${run_type}/input
  )
  llvm_test_verify(RUN_TYPE ${run_type} ${FPCMP}
    -r ${stdout_reltol}
    ${BENCHMARK_DIR}/data/${run_type}/output/SPEC-benchmark.log
    ${CMAKE_CURRENT_BINARY_DIR}/data/${run_type}/input/SPEC-benchmark.log
  )
  llvm_test_verify(RUN_TYPE ${run_type} ${FPCMP}
    ${BENCHMARK_DIR}/data/${run_type}/output/SPEC-benchmark.tga
    ${CMAKE_CURRENT_BINARY_DIR}/data/${run_type}/input/SPEC-benchmark.tga
  )
endmacro()

test_input(test 0.0002)
test_input(train 0.00005)
test_input(ref 0.00005)

llvm_test_executable(${PROG} ${Source})

include(CopyDir)
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
