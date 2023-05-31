# The benchmark library build system uses try_run tests to determine regex
# Circumvent these tests and enforce std::regex
set(CMAKE_CXX_STANDARD 11)
set(HAVE_STD_REGEX 1)
# When enforcing c++11 we need to disable one of the benchmark library's tests
set(BENCHMARK_HAS_CXX03_FLAG 0)
# Tests fail build on system with just "python3" but no "python" executable.
set(BENCHMARK_ENABLE_GTEST_TESTS OFF)
set(BENCHMARK_ENABLE_ASSEMBLY_TESTS OFF)

add_subdirectory(benchmark)
test_suite_add_build_dependencies(benchmark)
