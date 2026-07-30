add_subdirectory(AMDAPP_SDK)

# Propogate the list of tests to run.
set(OPENCL_SIMPLE_TESTS_LIST ${OPENCL_SIMPLE_TESTS_LIST} PARENT_SCOPE)
