list(APPEND LDFLAGS -lm)
if(CMAKE_SIZEOF_VOID_P EQUAL 8)
  add_definitions(-D__RISC_64__)
endif()
include(TestBigEndian)
if(IS_BIGENDIAN)
  set(INPUTNAME "vortex.in.big")
else()
  set(INPUTNAME "vortex.in.little")
endif()

macro(test_input run_type)
  llvm_test_run(RUN_TYPE ${run_type}
    ${INPUTNAME}
    WORKDIR ${CMAKE_CURRENT_BINARY_DIR}/data/${run_type}/input
  )
  llvm_test_verify(RUN_TYPE ${run_type} ${FPCMP}
    ${BENCHMARK_DIR}/data/${run_type}/output/vortex.out
    ${CMAKE_CURRENT_BINARY_DIR}/data/${run_type}/input/vortex.out
  )
endmacro()

test_input(test)
test_input(train)
test_input(ref)

llvm_test_executable(${PROG} ${Source})

# The benchmark writes the output where the input files are, so we have to
# copy the data over.
include(CopyDir)
llvm_copy_dir(${PROG} ${CMAKE_CURRENT_BINARY_DIR}/data ${BENCHMARK_DIR}/data)
