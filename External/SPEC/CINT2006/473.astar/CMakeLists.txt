list(APPEND CPPFLAGS -std=c++98)

macro(test_input run_type input output)
  llvm_test_run(RUN_TYPE ${run_type}
    WORKDIR ${CMAKE_CURRENT_BINARY_DIR}/data/${run_type}/input
    ${input} > ${CMAKE_CURRENT_BINARY_DIR}/${output}
  )
  llvm_test_verify(RUN_TYPE ${run_type} WORKDIR ${CMAKE_CURRENT_BINARY_DIR}
    ${FPCMP} -r 0.001 data/${run_type}/output/${output} ${output}
  )
endmacro()

test_input(test lake.cfg lake.out)
test_input(train BigLakes1024.cfg BigLakes1024.out)
test_input(train rivers1.cfg rivers1.out)
test_input(ref BigLakes2048.cfg BigLakes2048.out)
test_input(ref rivers.cfg rivers.out)

llvm_test_executable(473.astar ${Source})
llvm_test_data_spec_default(473.astar)
