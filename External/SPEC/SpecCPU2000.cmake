include(External)
include(CheckCSourceCompiles)
llvm_externals_find(TEST_SUITE_SPEC2000_ROOT "speccpu2000" "SPEC CPU2000")
if(TEST_SUITE_SPEC2000_ROOT)
  # SPEC supports three "run types": ref, train and test
  if(NOT TEST_SUITE_RUN_TYPE STREQUAL "train" AND
     NOT TEST_SUITE_RUN_TYPE STREQUAL "test" AND
     NOT TEST_SUITE_RUN_TYPE STREQUAL "ref")
    message(FATAL_ERROR
            "TEST_SUITE_RUN_TYPE must be 'train', 'test' or 'ref' for SPEC")
  endif()

  file(READ ${TEST_SUITE_SPEC2000_ROOT}/version VERSION)
  if (VERSION VERSION_LESS 1.3)
    message(WARNING "
    Expected SPEC2000 version 1.3 or newer, found ${VERSION}
")
  endif()

  list(APPEND CPPFLAGS -DSPEC_CPU2000)
  if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    list(APPEND CPPFLAGS -DSPEC_CPU2000_LP64)
  endif()

  if(TARGET_OS STREQUAL "Darwin")
    # Work around built in -Werror=implicit-function-declaration default on iOS
    list(APPEND CPPFLAGS -Wno-implicit-function-declaration)
  endif()

  function(llvm_test_data_spec target)
    llvm_test_data(${target} SOURCE_DIR ${BENCHMARK_DIR} ${ARGN})
  endfunction()

  function(llvm_test_data_spec_default target)
    llvm_test_data_spec(${target} data)
  endfunction()

  function(check_supports_zmuldefs)
    # Does not check whether the option has an effect.
    # -z options are usually ignored if the particular option.
    # Alternative option is --allow-multiple-definition
    set(CMAKE_REQUIRED_LINK_OPTIONS "-Wl,-zmuldefs")
    check_c_source_compiles("int main() { return 0; };" LINKER_SUPPORTS_ZMULDEFS)
  endfunction()

  check_supports_zmuldefs()
  set(LD_MULTIDEF_FLAG)
  if(LINKER_SUPPORTS_ZMULDEFS)
    set(LD_MULTIDEF_FLAG "-Wl,-zmuldefs")
  endif()
endif()
