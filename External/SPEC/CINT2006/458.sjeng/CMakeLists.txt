macro(test_input run_type)
  llvm_test_run(RUN_TYPE ${run_type} WORKDIR %S
    data/${run_type}/input/${run_type}.txt > ${run_type}.out
  )
  llvm_test_verify(RUN_TYPE ${run_type}
    %b/${FPCMP} %S/data/${run_type}/output/${run_type}.out %S/${run_type}.out
  )
endmacro()

test_input(test)
test_input(train)
test_input(ref)

llvm_test_executable(458.sjeng ${Source})
llvm_test_data_spec_default(458.sjeng)
