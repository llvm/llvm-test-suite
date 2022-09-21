list(APPEND CFLAGS -Wno-implicit-int)

macro(test_input run_type)
  llvm_test_run(RUN_TYPE ${run_type}
    WORKDIR %S/data/${run_type}/input
    < ammp.in > %S/ammp.out
  )
  llvm_test_verify(RUN_TYPE ${run_type}
    %b/${FPCMP} -r 0.003 -a 0.0001 %S/data/${run_type}/output/ammp.out %S/ammp.out
  )
endmacro()

test_input(test)
test_input(train)
test_input(ref)

llvm_test_executable(188.ammp ${Source})
llvm_test_data_spec_default(188.ammp)
