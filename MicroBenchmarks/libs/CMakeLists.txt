# The benchmark library build system uses try_run tests to determine regex
# Circumvent these tests and enforce std::regex
set(CMAKE_CXX_STANDARD 11)
set(HAVE_STD_REGEX 1)
# When enforcing c++11 we need to disable one of the benchmark library's tests
set(BENCHMARK_HAS_CXX03_FLAG 0)

add_subdirectory(benchmark)
test_suite_add_build_dependencies(benchmark)
test_suite_add_build_dependencies(output_test_helper)
test_suite_add_build_dependencies(gtest)
test_suite_add_build_dependencies(gmock)

# These tests, when built with BENCHMARK_ENABLE_ASSEMBLY_TESTS is on.
# They don't depend on the above, so we need to list them explicitly.
if (BENCHMARK_ENABLE_ASSEMBLY_TESTS)
  test_suite_add_build_dependencies(donotoptimize_assembly_test)
  test_suite_add_build_dependencies(state_assembly_test)
  test_suite_add_build_dependencies(clobber_memory_assembly_test)
endif()

