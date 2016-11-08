include_directories(${BENCHMARK_DIR}/src)

include(TestBigEndian)
if(IS_BIGENDIAN)
  list(APPEND CPPFLAGS -DHOST_WORDS_BIG_ENDIAN)
endif()
if(TARGET_OS STREQUAL "Darwin")
  # Necessary for iOS
  list(APPEND LDFLAGS -Xlinker -stack_size -Xlinker 0x8000000)
endif()
list(APPEND CPPFLAGS -DPOSIX -DSPEC_CPU_HAVE_BOOL)

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

test_input(test cccp.in cccp.s)
test_input(train integrate.in integrate.s)
test_input(ref 166.in 166.s)
test_input(ref 200.in 200.s)
test_input(ref c-typeck.in c-typeck.s)
test_input(ref cp-decl.in cp-decl.s)
test_input(ref expr.in expr.s)
test_input(ref expr2.in expr2.s)
test_input(ref g23.in g23.s)
test_input(ref s04.in s04.s)
test_input(ref scilab.in scilab.s)

llvm_test_executable(${PROG} ${Source})
