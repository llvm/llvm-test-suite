# Only enable verification of results if neither 'benchmarking only' has been
# selected nor -ffast-math is passed.
string(TOUPPER ${CMAKE_BUILD_TYPE} CMAKE_BUILD_TYPE_UPPER)
set(COMBINED_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_${CMAKE_BUILD_TYPE_UPPER}} ${CPPFLAGS}")
if (NOT TEST_SUITE_BENCHMARKING_ONLY AND
    NOT ${COMBINED_CXX_FLAGS} MATCHES ".*-ffast-math.*")
  list(APPEND CPPFLAGS -DBENCH_AND_VERIFY)
endif()

llvm_test_run()

llvm_test_executable(LoopVectorizationBenchmarks
  main.cpp
  MathFunctions.cpp
  RuntimeChecks.cpp
)

target_link_libraries(LoopVectorizationBenchmarks benchmark)
