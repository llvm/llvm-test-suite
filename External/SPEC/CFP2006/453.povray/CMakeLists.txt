list(APPEND LDFLAGS -lm)

if(ARCH STREQUAL "AArch64" OR ARCH STREQUAL "LoongArch")
  # On AArch64/LoongArch and for C/C++ the new behavior is to flip
  # '-ffp-contract' to 'on'. This breaks floating point comparison
  # of results.
  # Turn off the flag so that the result image matches the reference
  # output.
  list(APPEND CXXFLAGS -ffp-contract=off)
endif()

macro(test_input run_type stdout_reltol)
  llvm_test_run(RUN_TYPE ${run_type}
    WORKDIR %S/data/${run_type}/input
    SPEC-benchmark-${run_type}.ini
  )
  llvm_test_verify(RUN_TYPE ${run_type}
    %b/${FPCMP} -r ${stdout_reltol}
    %S/data/${run_type}/output/SPEC-benchmark.log
    %S/data/${run_type}/input/SPEC-benchmark.log
  )
  llvm_test_verify(RUN_TYPE ${run_type}
    %b/${FPCMP}
    %S/data/${run_type}/output/SPEC-benchmark.tga
    %S/data/${run_type}/input/SPEC-benchmark.tga
  )
endmacro()

test_input(test 0.0002)
test_input(train 0.00005)
test_input(ref 0.00005)

llvm_test_executable(453.povray ${Source})
set_property(TARGET 453.povray PROPERTY CXX_STANDARD 14)
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
