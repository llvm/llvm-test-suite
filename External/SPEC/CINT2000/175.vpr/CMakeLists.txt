list(APPEND CPPFLAGS -DNO_GRAPHICSS)
list(APPEND LDFLAGS -lm)

macro(test_input run_type costs_tolerance)
  # The benchmark keeps appending to costs.out, so we have to make sure there
  # is none from previous runs
  llvm_test_prepare(RUN_TYPE ${run_type} WORKDIR %S
    rm -f data/${run_type}/input/costs.out
  )
  llvm_test_run(RUN_TYPE ${run_type}
    WORKDIR %S/data/${run_type}/input
    net.in arch.in place.out dum.out
    -nodisp -place_only -init_t 5 -exit_t 0.005 -alpha_t 0.9412 -inner_num 2
    > %S/place_log.out
  )
  llvm_test_verify(RUN_TYPE ${run_type}
    %b/${FPCMP} %S/data/${run_type}/output/place_log.out %S/place_log.out
  )
  llvm_test_run(RUN_TYPE ${run_type}
    WORKDIR %S/data/${run_type}/input
    net.in arch.in place.in route.out
    -nodisp -route_only -route_chan_width 15 -pres_fac_mult 2 -acc_fac 1 -first_iter_pres_fac 4 -initial_pres_fac 8
    > %S/route_log.out
  )
  llvm_test_verify(RUN_TYPE ${run_type}
    %b/${FPCMP} -r 0.015 %S/data/${run_type}/output/route_log.out %S/route_log.out
  )
  llvm_test_verify(RUN_TYPE ${run_type}
    %b/${FPCMP} -r 0.015
    %S/data/${run_type}/output/route.out
    %S/data/${run_type}/input/route.out
  )
  llvm_test_verify(RUN_TYPE ${run_type}
    %b/${FPCMP} -r ${costs_tolerance}
    %S/data/${run_type}/output/costs.out
    %S/data/${run_type}/input/costs.out
  )
endmacro()

test_input(ref 0.05)
test_input(train 0.05)
test_input(test 0.10)

llvm_test_executable(175.vpr ${Source})
llvm_test_data_spec(175.vpr MUST_COPY data)
