include(External)
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
endif()
