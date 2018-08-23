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
    WORKDIR ${CMAKE_CURRENT_BINARY_DIR}/data/${run_type}/input
    ${INPUTNAME}
  )
llvm_test_verify(RUN_TYPE ${run_type} WORKDIR ${CMAKE_CURRENT_BINARY_DIR}
    ${FPCMP}
    data/${run_type}/output/vortex.out
    data/${run_type}/input/vortex.out
  )
endmacro()

test_input(test)
test_input(train)
test_input(ref)

llvm_test_executable(147.vortex ${Source})
llvm_test_data_spec(147.vortex MUST_COPY data)
