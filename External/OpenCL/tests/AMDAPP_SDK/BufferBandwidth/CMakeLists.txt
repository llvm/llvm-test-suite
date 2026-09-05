# Test parameters
set(TestName BufferBandwidth)
set(TestSources BufferBandwidth.cpp Log.cpp Host.cpp Shared.cpp Timer.cpp)
set(TestData BufferBandwidth_Kernels.cl)
set(OpenCL_CPPFLAGS -std=c++14 -Wno-c++11-narrowing)
set(OpenCL_LDFLAGS "")
set(OpenCL_LIBS "")

# Target to build this specific test.
add_custom_target(opencl-tests-simple-${TestName})

# Add dependencies for target to build all the tests in opencl-tests-simple. 
add_dependencies(opencl-tests-simple opencl-tests-simple-${TestName})
create_local_test(${TestName} "${TestSources}" "${TestData}" "${OpenCL_CPPFLAGS}" "${OpenCL_LDFLAGS}" "${OpenCL_LIBS}")

# Populate & propogate list of tests to run them all using check-opencl-simple.
list(APPEND OPENCL_SIMPLE_TESTS_LIST "${CMAKE_CURRENT_BINARY_DIR}/${TestName}.test")
set(OPENCL_SIMPLE_TESTS_LIST ${OPENCL_SIMPLE_TESTS_LIST} PARENT_SCOPE)

# Target to run this specific test.
add_custom_target(check-opencl-simple-${TestName}
  COMMAND ${TEST_SUITE_LIT} ${TEST_SUITE_LIT_FLAGS} ${TestName}.test
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
  DEPENDS opencl-tests-simple-${TestName}
  USES_TERMINAL)
