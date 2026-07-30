include(External)

llvm_externals_find(TEST_SUITE_OPENCL_ROOT "opencl" "OpenCL prerequisites")
message(STATUS "TEST_SUITE_OPENCL_ROOT: ${TEST_SUITE_OPENCL_ROOT}")
get_filename_component(OPENCL_CLANG_PATH ${CMAKE_CXX_COMPILER} DIRECTORY)
string(REGEX REPLACE "bin$" "lib" OPENCL_LIB_PATH "${OPENCL_CLANG_PATH}")
message(STATUS "OPENCL_CLANG_PATH: ${OPENCL_CLANG_PATH}")
message(STATUS "OPENCL_LIB_PATH: ${OPENCL_LIB_PATH}")

macro(create_local_test TestName TestSources TestData VariantCPPFLAGS VariantLDFLAGS VariantLibs)
    set(_sources "${TestSources}")
    set(_executable ${TestName})
    set(_data "${TestData}")
    llvm_test_run(WORKDIR %S
      EXECUTABLE "LD_LIBRARY_PATH=${OPENCL_LIB_PATH}" ./${_executable} > %o
    )
    set(REFERENCE_OUTPUT)
    # Verify reference output if it exists.
    if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${TestName}.reference_output)
      set(REFERENCE_OUTPUT ${TestName}.reference_output)
      llvm_test_verify(WORKDIR %S
        %b/${FPCMP} %o ${REFERENCE_OUTPUT}
      )
      llvm_test_executable(${_executable} "${_sources}")
      llvm_test_data(${_executable} ${_data} ${REFERENCE_OUTPUT})
    else()
      llvm_test_executable(${_executable} "${_sources}")
      llvm_test_data(${_executable} ${_data})
    endif()
    target_compile_options(${_executable} PUBLIC ${VariantCPPFLAGS})
    target_link_options(${_executable} PUBLIC ${VariantLDFLAGS})
    if(VariantLibs)
      target_link_libraries(${_executable} ${VariantLibs})
    endif()
    add_dependencies(opencl-tests-simple-${TestName} ${_executable})
endmacro()

if(TEST_SUITE_OPENCL_ROOT)
  add_custom_target(opencl-tests-simple COMMENT "Build all simple OpenCL tests")
  # Add common OpenCL related flags
  list(APPEND LDFLAGS -lOpenCL -L${OPENCL_LIB_PATH})
  add_subdirectory(tests)
  message(STATUS "OPENCL_SIMPLE_TESTS_LIST: ${OPENCL_SIMPLE_TESTS_LIST}")
  add_custom_target(check-opencl-simple COMMENT "Run all simple OpenCL tests"
    COMMAND ${TEST_SUITE_LIT} ${TEST_SUITE_LIT_FLAGS} ${OPENCL_SIMPLE_TESTS_LIST}
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    DEPENDS opencl-tests-simple
    USES_TERMINAL)
endif()
