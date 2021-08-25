macro(test_input run_type input output size0 size1)
  llvm_test_run(RUN_TYPE ${run_type}
    WORKDIR %S/data/${run_type}/input
    ${size0} ${size1} ${input}
    > %S/${output}
  )
  llvm_test_verify(RUN_TYPE ${run_type}
    %b/${FPCMP} %S/data/${run_type}/output/${output} %S/${output}
  )
endmacro()

test_input(test null.in null.out 40 19)
test_input(train 2stone9.in 2stone9.out 50 9)
test_input(ref 5stone21.in 5stone21.out 50 21)
test_input(ref 9stone21.in 9stone21.out 50 21)
test_input(ref null.in null.out 50 21)

llvm_test_executable(099.go ${Source})
llvm_test_data_spec_default(099.go)
