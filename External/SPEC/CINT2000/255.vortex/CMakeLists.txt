list(APPEND LDFLAGS -lm)
list(APPEND CFLAGS -Wno-implicit-int)

macro(test_input run_type input outfile)
  llvm_test_run(RUN_TYPE ${run_type}
    WORKDIR %S/data/${run_type}/input
    ${input}
  )
  llvm_test_verify(RUN_TYPE ${run_type}
    %b/${FPCMP}
    %S/data/${run_type}/output/${outfile}
    %S/data/${run_type}/input/${outfile}
  )
endmacro()

include(TestBigEndian)
test_big_endian(IS_BIGENDIAN)
if(IS_BIGENDIAN)
  set(endianname "bendian")
else()
  set(endianname "lendian")
endif()

test_input(test ${endianname}.raw vortex.out)
test_input(train ${endianname}.raw vortex.out)
test_input(ref ${endianname}1.raw vortex1.out)
test_input(ref ${endianname}2.raw vortex2.out)
test_input(ref ${endianname}3.raw vortex3.out)

llvm_test_executable(255.vortex ${Source})
llvm_test_data_spec(255.vortex MUST_COPY data)
