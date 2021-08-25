add_definitions(-DSPEC)
list(APPEND CPPFLAGS -idirafter ${BENCHMARK_DIR}/src/src.alt)

macro(test_input run_type input output)
  llvm_test_run(RUN_TYPE ${run_type}
    WORKDIR %S
    -quiet -funroll-loops -fforce-mem -fcse-follow-jumps
    -fcse-skip-blocks -fexpensive-optimizations -fstrength-reduce -fpeephole
    -fschedule-insns -finline-functions -fschedule-insns2
    -O data/${run_type}/input/${input}
    -o ${output}
  )
  llvm_test_verify(RUN_TYPE ${run_type}
    %b/${FPCMP} %S/data/${run_type}/output/${output} %S/${output}
  )
endmacro()

test_input(test cccp.i cccp.s)
test_input(train amptjp.i amptjp.s)
file(GLOB inputs "${BENCHMARK_DIR}/data/ref/input/*.i")
foreach(input ${inputs})
  get_filename_component(basename "${input}" NAME_WE)
  test_input(ref ${basename}.o ${basename}.s)
endforeach()

llvm_test_executable(126.gcc ${Source})
llvm_test_data_spec_default(126.gcc)
