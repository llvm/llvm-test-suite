include_directories(${BENCHMARK_DIR}/src/include)
add_definitions(-DBOOST_DISABLE_THREADS -Ddeal_II_dimension=3)
list(APPEND LDFLAGS -lm)

macro(verify_n run_type dir n)
  # Note that the official SPEC fp tolarence is only "-a .0000001", however this
  # has proven to only work reliably for x86 targets/libm.
  llvm_test_verify(RUN_TYPE ${run_type} ${FPCMP}
    -a 1e-5 -r 1e-5
    ${BENCHMARK_DIR}/data/${dir}/output/grid-${n}.eps
    ${CMAKE_CURRENT_BINARY_DIR}/grid-${n}.eps
  )
  llvm_test_verify(RUN_TYPE ${run_type} ${FPCMP}
    -a 1e-5 -r 1e-5
    ${BENCHMARK_DIR}/data/${dir}/output/solution-${n}.gmv
    ${CMAKE_CURRENT_BINARY_DIR}/solution-${n}.gmv
  )
endmacro()

macro(test_input run_type size)
  llvm_test_run(RUN_TYPE ${run_type}
    ${size}
    > ${CMAKE_CURRENT_BINARY_DIR}/log
    WORKDIR ${CMAKE_CURRENT_BINARY_DIR}
  )
  llvm_test_verify(RUN_TYPE ${run_type} ${FPCMP}
    ${BENCHMARK_DIR}/data/${run_type}/output/log
    ${CMAKE_CURRENT_BINARY_DIR}/log
  )
  foreach(i RANGE 0 8)
    verify_n(${run_type} all ${i})
  endforeach()
  if(${size} GREATER 8)
    foreach(i RANGE 9 ${size})
      verify_n(${run_type} ${run_type} ${i})
    endforeach()
  endif()
endmacro()

test_input(test 8)
test_input(train 10)
test_input(ref 23)

llvm_test_executable(${PROG} ${Source})
