if(ENDIAN STREQUAL "big")
  list(APPEND CPPFLAGS -DHOST_WORDS_BIG_ENDIAN)
endif()
if(TARGET_OS STREQUAL "Darwin")
  # Necessary for iOS
  list(APPEND LDFLAGS -Xlinker -stack_size -Xlinker 0x800000)
endif()
list(APPEND CFLAGS -std=gnu89)
# We want reproducible builds
list(APPEND CPPFLAGS -D__DATE__="XXX" -D__TIME__="XXX")

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

test_input(ref 166.i 166.s)
test_input(ref 200.i 200.s)
test_input(ref expr.i expr.s)
test_input(ref integrate.i integrate.s)
test_input(ref scilab.i scilab.s)
test_input(train cp-decl.i cp-decl.s)
test_input(test cccp.i cccp.s)

llvm_test_executable(${PROG} ${Source})
