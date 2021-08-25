macro(test_input run_type filename size)
  llvm_test_run(RUN_TYPE ${run_type} WORKDIR %S
    data/${run_type}/input/${filename} ${size} > ${filename}.out
  )
  llvm_test_verify(RUN_TYPE ${run_type}
    %b/${FPCMP} %S/data/${run_type}/output/${filename}.out %S/${filename}.out
  )
endmacro()

test_input(train input.combined 32)
test_input(test input.compressed 2)
test_input(ref input.source 60)
test_input(ref input.log 60)
test_input(ref input.graphic 60)
test_input(ref input.random 60)
test_input(ref input.program 60)

llvm_test_executable(164.gzip ${Source})
llvm_test_data_spec_default(164.gzip)
