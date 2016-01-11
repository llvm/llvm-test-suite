include_directories(${BENCHMARK_DIR}/src)

include(TestBigEndian)
if(IS_BIGENDIAN)
  list(APPEND CPPFLAGS -DHOST_WORDS_BIG_ENDIAN)
endif()

macro(test_input run_type ifile sfile)
  llvm_test_run(RUN_TYPE ${run_type}
    ${BENCHMARK_DIR}/data/${run_type}/input/${ifile}
    -o ${CMAKE_CURRENT_BINARY_DIR}/${sfile}
  )
  llvm_test_verify(RUN_TYPE ${run_type} ${FPCMP}
    ${BENCHMARK_DIR}/data/${run_type}/output/${sfile}
    ${CMAKE_CURRENT_BINARY_DIR}/${sfile}
  )
endmacro()

test_input(test cccp.i cccp.s)
test_input(train integrate.i integrate.s)
test_input(ref 166.i 166.s)
test_input(ref 200.i 200.s)
test_input(ref c-typeck.i c-typeck.s)
test_input(ref cp-decl.i cp-decl.s)
test_input(ref expr.i expr.s)
test_input(ref expr2.i expr2.s)
test_input(ref g23.i g23.s)
test_input(ref s04.i s04.s)
test_input(ref scilab.i scilab.s)

llvm_multisource()
