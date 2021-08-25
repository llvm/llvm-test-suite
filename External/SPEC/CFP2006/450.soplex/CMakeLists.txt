list(APPEND LDFLAGS -lm)
list(APPEND CXXFLAGS -std=gnu++98)

macro(test_input run_type input outname stdout_reltol info_reltol)
  llvm_test_run(RUN_TYPE ${run_type}
    WORKDIR %S/data/${run_type}/input
    ${ARGN} ${input} > ${outname}
  )
  llvm_test_verify(RUN_TYPE ${run_type}
    %b/${FPCMP} -r ${stdout_reltol} -a 1.0e-5
    %S/data/${run_type}/output/${outname}
    %S/data/${run_type}/input/${outname}
  )
  llvm_test_verify(RUN_TYPE ${run_type}
    %b/${FPCMP} -r ${info_reltol} -a 20
    %S/data/${run_type}/output/${input}.info
    %S/data/${run_type}/input/${input}.info
  )
endmacro()

test_input(test  test.mps   test.out       0.0001 1.0    -m10000)
test_input(train train.mps  train.out      0.02   0.0001 -m1200)
test_input(train pds-20.mps pds-20.mps.out 0.02   0.0001 -s1 -e -m5000)
test_input(ref   ref.mps    ref.out        0.02   0.0001 -m3500)
test_input(ref   pds-50.mps pds-50.mps.out 0.02   0.0001 -s1 -e -m45000)

llvm_test_executable(450.soplex ${Source})
llvm_test_data_spec(450.soplex MUST_COPY data)
