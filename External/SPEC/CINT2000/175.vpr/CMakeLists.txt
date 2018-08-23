list(APPEND CPPFLAGS -DNO_GRAPHICSS)
list(APPEND LDFLAGS -lm)

macro(test_input run_type costs_tolerance)
  # The benchmark keeps appending to costs.out, so we have to make sure there
  # is none from previous runs
  llvm_test_prepare(RUN_TYPE ${run_type} WORKDIR ${CMAKE_CURRENT_BINARY_DIR}
    rm -f data/${run_type}/input/costs.out
  )
  llvm_test_run(RUN_TYPE ${run_type}
    WORKDIR ${CMAKE_CURRENT_BINARY_DIR}/data/${run_type}/input
    net.in arch.in place.out dum.out
    -nodisp -place_only -init_t 5 -exit_t 0.005 -alpha_t 0.9412 -inner_num 2
    > ${CMAKE_CURRENT_BINARY_DIR}/place_log.out
  )
  llvm_test_verify(RUN_TYPE ${run_type} WORKDIR ${CMAKE_CURRENT_BINARY_DIR}
    ${FPCMP} data/${run_type}/output/place_log.out place_log.out
  )
  llvm_test_run(RUN_TYPE ${run_type}
    WORKDIR ${CMAKE_CURRENT_BINARY_DIR}/data/${run_type}/input
    net.in arch.in place.in route.out
    -nodisp -route_only -route_chan_width 15 -pres_fac_mult 2 -acc_fac 1 -first_iter_pres_fac 4 -initial_pres_fac 8
    > ${CMAKE_CURRENT_BINARY_DIR}/route_log.out
  )
  llvm_test_verify(RUN_TYPE ${run_type} WORKDIR ${CMAKE_CURRENT_BINARY_DIR}
    ${FPCMP} -r 0.015 data/${run_type}/output/route_log.out route_log.out
  )
  llvm_test_verify(RUN_TYPE ${run_type} WORKDIR ${CMAKE_CURRENT_BINARY_DIR}
    ${FPCMP} -r 0.015
    data/${run_type}/output/route.out
    data/${run_type}/input/route.out
  )
  llvm_test_verify(RUN_TYPE ${run_type} WORKDIR ${CMAKE_CURRENT_BINARY_DIR}
    ${FPCMP} -r ${costs_tolerance}
    data/${run_type}/output/costs.out
    data/${run_type}/input/costs.out
  )
endmacro()

test_input(ref 0.05)
test_input(train 0.05)
test_input(test 0.10)

llvm_test_executable(175.vpr ${Source})
llvm_test_data_spec(175.vpr MUST_COPY data)
