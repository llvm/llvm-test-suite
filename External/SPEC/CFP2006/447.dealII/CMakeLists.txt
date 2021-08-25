include_directories(${BENCHMARK_DIR}/src/include)
add_definitions(-DBOOST_DISABLE_THREADS -Ddeal_II_dimension=3)
list(APPEND LDFLAGS -lm)
list(APPEND CXXFLAGS -std=gnu++98)

macro(verify_n run_type dir n)
  # Note that the official SPEC fp tolarence is only "-a .0000001", however this
  # has proven to only work reliably for x86 targets/libm.
  llvm_test_verify(RUN_TYPE ${run_type}
    %b/${FPCMP} -a 1e-5 -r 1e-5
    %S/data/${dir}/output/grid-${n}.eps
    %S/grid-${n}.eps
  )
  llvm_test_verify(RUN_TYPE ${run_type}
    %b/${FPCMP} -a 1e-5 -r 1e-5
    %S/data/${dir}/output/solution-${n}.gmv
    %S/solution-${n}.gmv
  )
endmacro()

macro(test_input run_type size)
  llvm_test_run(RUN_TYPE ${run_type} WORKDIR %S
    ${size}
    > log
  )
  llvm_test_verify(RUN_TYPE ${run_type}
    %b/${FPCMP} -a 1e-5 -r 1e-5
    %S/data/${run_type}/output/log
    %S/log
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

llvm_test_executable(447.dealII ${Source})
llvm_test_data_spec_default(447.dealII)
