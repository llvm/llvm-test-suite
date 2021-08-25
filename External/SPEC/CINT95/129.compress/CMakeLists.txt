# iOS compiler have -Werror=return-value, need to disable this explicitely
# (-w is not enough)
list(APPEND CFLAGS -Wno-return-type)

macro(test_input run_type input output)
  llvm_test_run(RUN_TYPE ${run_type}
    WORKDIR %S
    < data/${run_type}/input/${input} > ${output}
  )
  llvm_test_verify(RUN_TYPE ${run_type}
    %b/${FPCMP} %S/data/${run_type}/output/${output} %S/${output}
  )
endmacro()

test_input(test test.in test.out)
test_input(train test.in test.out)
test_input(ref bigtest.in bigtest.out)

llvm_test_executable(129.compress ${Source})
llvm_test_data_spec_default(129.compress)
