list(APPEND LDFLAGS -lm)

macro(test_input run_type input outfile)
  llvm_test_run(RUN_TYPE ${run_type}
    WORKDIR ${CMAKE_CURRENT_BINARY_DIR}/data/${run_type}/input
    ${input}
  )
  llvm_test_verify(RUN_TYPE ${run_type} ${FPCMP}
    ${BENCHMARK_DIR}/data/${run_type}/output/${outfile}
    ${CMAKE_CURRENT_BINARY_DIR}/data/${run_type}/input/${outfile}
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

llvm_test_executable(${PROG} ${Source})

# The benchmark writes the output where the input files are, so we have to
# copy the data over.
include(CopyDir)
llvm_copy_dir(${PROG} ${CMAKE_CURRENT_BINARY_DIR}/data ${BENCHMARK_DIR}/data)
