include(External)
llvm_externals_find(TEST_SUITE_SPEC95_ROOT "spec95" "SPEC CPU95")
if(TEST_SUITE_SPEC95_ROOT)
  # SPEC supports three "run types": ref, train and test
  if(NOT TEST_SUITE_RUN_TYPE STREQUAL "train" AND
     NOT TEST_SUITE_RUN_TYPE STREQUAL "test" AND
     NOT TEST_SUITE_RUN_TYPE STREQUAL "ref")
    message(FATAL_ERROR
            "TEST_SUITE_RUN_TYPE must be 'train', 'test' or 'ref' for SPEC")
  endif()

  list(APPEND CPPFLAGS -DSPEC_CPU95)

  if(TARGET_OS STREQUAL "Darwin")
    # Work around built in -Werror=implicit-function-declaration default on iOS
    list(APPEND CPPFLAGS -Wno-implicit-function-declaration)
  endif()

  macro(cint95_subdir BENCHMARK)
    set(BENCHMARK_DIR ${TEST_SUITE_SPEC95_ROOT}/benchspec/CINT95/${BENCHMARK})
    file(GLOB Source ${BENCHMARK_DIR}/src/*.c ${BENCHMARK_DIR}/src/*.cpp)
    add_subdirectory(${BENCHMARK})
  endmacro()

  function(llvm_test_data_spec target)
    llvm_test_data(${target} SOURCE_DIR ${BENCHMARK_DIR} ${ARGN})
  endfunction()

  function(llvm_test_data_spec_default target)
    llvm_test_data_spec(${target} data)
  endfunction()
endif()
