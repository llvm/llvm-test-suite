macro(test_input run_type)
  llvm_test_run(RUN_TYPE ${run_type} WORKDIR %S
    < data/${run_type}/input/inp.in > inp.out
  )
  llvm_test_verify(RUN_TYPE ${run_type}
    %b/${FPCMP} -r 0.00001 %S/data/${run_type}/output/inp.out %S/inp.out
  )
endmacro()

test_input(test)
test_input(train)
test_input(ref)

llvm_test_executable(183.equake ${Source})
llvm_test_data_spec_default(183.equake)
