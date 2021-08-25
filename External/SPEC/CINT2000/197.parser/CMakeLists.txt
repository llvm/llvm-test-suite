if(TARGET_OS STREQUAL "Darwin")
  list(APPEND CPPFLAGS -D_ANSI_SOURCE=1)
endif()

macro(test_input run_type)
  llvm_test_run(RUN_TYPE ${run_type}
    WORKDIR %S/data/all/input
    2.1.dict -batch
    < %S/data/${run_type}/input/${run_type}.in
    > %S/${run_type}.out
  )
  llvm_test_verify(RUN_TYPE ${run_type}
    %b/${FPCMP} %S/data/${run_type}/output/${run_type}.out %S/${run_type}.out
  )
endmacro()

test_input(ref)
test_input(train)
test_input(test)

llvm_test_executable(197.parser ${Source})
llvm_test_data_spec_default(197.parser)
