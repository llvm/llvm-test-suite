add_subdirectory(BufferBandwidth)
add_subdirectory(HelloWorld)
add_subdirectory(Template)

# Propogate the list of tests to run.
set(OPENCL_SIMPLE_TESTS_LIST ${OPENCL_SIMPLE_TESTS_LIST} PARENT_SCOPE)
