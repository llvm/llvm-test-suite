add_definitions(-DSPEC)
list(APPEND CPPFLAGS -idirafter ${BENCHMARK_DIR}/src/src.alt)

macro(test_input run_type input output)
  llvm_test_run(RUN_TYPE ${run_type}
    -quiet -funroll-loops -fforce-mem -fcse-follow-jumps
    -fcse-skip-blocks -fexpensive-optimizations -fstrength-reduce -fpeephole
    -fschedule-insns -finline-functions -fschedule-insns2
    -O ${BENCHMARK_DIR}/data/${run_type}/input/${input}
    -o ${CMAKE_CURRENT_BINARY_DIR}/${output}
  )
  llvm_test_verify(RUN_TYPE ${run_type} ${FPCMP}
    ${BENCHMARK_DIR}/data/${run_type}/output/${output}
    ${CMAKE_CURRENT_BINARY_DIR}/${output}
  )
endmacro()

test_input(test cccp.i cccp.s)
test_input(train amptjp.i amptjp.s)
file(GLOB inputs "${BENCHMARK_DIR}/data/ref/input/*.i")
foreach(input ${inputs})
  get_filename_component(basename "${input}" NAME_WE)
  test_input(ref ${basename}.o ${basename}.s)
endforeach()

llvm_test_executable(${PROG} ${Source})
