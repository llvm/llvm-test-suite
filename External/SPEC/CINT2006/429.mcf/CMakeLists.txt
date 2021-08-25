list(APPEND CPPFLAGS -DWANT_STDC_PROTO)

macro(test_input run_type)
  llvm_test_run(RUN_TYPE ${run_type} WORKDIR %S
    data/${run_type}/input/inp.in > inp.out
  )
  llvm_test_verify(RUN_TYPE ${run_type}
    %b/${FPCMP} %S/data/${run_type}/output/inp.out %S/inp.out
  )
  llvm_test_verify(RUN_TYPE ${run_type}
    %b/${FPCMP} %S/data/${run_type}/output/mcf.out %S/mcf.out
  )
endmacro()

test_input(test)
test_input(train)
test_input(ref)

llvm_test_executable(429.mcf ${Source})
llvm_test_data_spec_default(429.mcf)
