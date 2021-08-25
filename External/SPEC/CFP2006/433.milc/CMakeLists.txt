list(APPEND LDFLAGS -lm)

include_directories(${BENCHMARK_DIR}/src)
add_definitions(-DFN -DFAST -DCONGRAD_TMP_VECTORS -DDSLASH_TMP_LINKS)

macro(test_input run_type)
  llvm_test_run(RUN_TYPE ${run_type} WORKDIR %S
    < data/${run_type}/input/su3imp.in
    > su3imp.out
  )
  llvm_test_verify(RUN_TYPE ${run_type}
    %b/${FPCMP} -r 0.0001 -a 0.0000002
    %S/data/${run_type}/output/su3imp.out
    %S/su3imp.out
  )
endmacro()

test_input(test)
test_input(train)
test_input(ref)

llvm_test_executable(433.milc ${Source})
llvm_test_data_spec_default(433.milc)
