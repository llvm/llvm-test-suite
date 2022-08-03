macro(test_input run_type input size output)
  llvm_test_run(RUN_TYPE ${run_type} WORKDIR %S
    ${input} ${size} > ${output}
  )
  llvm_test_verify(RUN_TYPE ${run_type}
    %b/${FPCMP} %S/data/${run_type}/output/${output} %S/${output}
  )
endmacro()

test_input(test data/all/input/input.program 5 input.program.out)
test_input(test data/test/input/dryer.jpg 2 dryer.jpg.out)

test_input(train data/all/input/input.program 10 input.program.out)
test_input(train data/train/input/byoudoin.jpg 5 byoudoin.jpg.out)
test_input(train data/all/input/input.combined 80 input.combined.out)

test_input(ref data/ref/input/input.source 280 input.source.out)
test_input(ref data/ref/input/chicken.jpg 30 chicken.jpg.out)
test_input(ref data/ref/input/liberty.jpg 30 liberty.jpg.out)
test_input(ref data/all/input/input.program 280 input.program.out)
test_input(ref data/ref/input/text.html 280 text.html.out)
test_input(ref data/all/input/input.combined 200 input.combined.out)


list(APPEND CFLAGS -Wno-int-conversion)
llvm_test_executable(401.bzip2 ${Source})
llvm_test_data_spec_default(401.bzip2)
