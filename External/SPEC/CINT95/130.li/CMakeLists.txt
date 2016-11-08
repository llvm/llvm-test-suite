# Work around usage of a reserved name (is* is reserved by the C standard and
# isnumber is posix function)
add_definitions(-Disnumber=my_isnumber)

macro(test_input run_type)
  llvm_test_run(RUN_TYPE ${run_type}
    ${ARGN}
    > ${CMAKE_CURRENT_BINARY_DIR}/${run_type}.out
    WORKDIR ${BENCHMARK_DIR}/data/${run_type}/input
  )
  llvm_test_verify(RUN_TYPE ${run_type} ${FPCMP}
    ${BENCHMARK_DIR}/data/${run_type}/output/${run_type}.out
    ${CMAKE_CURRENT_BINARY_DIR}/${run_type}.out
  )
endmacro()

test_input(test test.lsp)
test_input(train train.lsp)
test_input(ref au.lsp boyer.lsp browse.lsp ctak.lsp dderiv.lsp deriv.lsp
               destru0.lsp destru1.lsp destru2.lsp destrum0.lsp
               destrum1.lsp destrum2.lsp div2.lsp puzzle0.lsp puzzle1.lsp
               tak0.lsp tak1.lsp tak2.lsp takr.lsp triang.lsp xit.lsp)

llvm_test_executable(${PROG} ${Source})
