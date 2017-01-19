if(TARGET_OS STREQUAL "Darwin")
  # Work around built in -Werror=implicit-function-declaration default on iOS
  list(APPEND CPPFLAGS -Wno-implicit-function-declaration)
endif()

# SPEC supports three "run types": ref, train and test
if(NOT TEST_SUITE_RUN_TYPE STREQUAL "train" AND
   NOT TEST_SUITE_RUN_TYPE STREQUAL "test" AND
   NOT TEST_SUITE_RUN_TYPE STREQUAL "ref")
  message(FATAL_ERROR
          "TEST_SUITE_RUN_TYPE must be 'train', 'test' or 'ref' for SPEC")
endif()

llvm_externals_find(TEST_SUITE_SPEC95_ROOT "spec95" "SPEC CPU95")
if(TEST_SUITE_SPEC95_ROOT)
  add_subdirectory(CINT95)
  # Note that all CFP95 tests are fortran so not supported by cmake/lit yet
endif()

llvm_externals_find(TEST_SUITE_SPEC2000_ROOT "speccpu2000" "SPEC CPU2000")
if(TEST_SUITE_SPEC2000_ROOT)
  file(READ ${TEST_SUITE_SPEC2000_ROOT}/version VERSION)
  if (VERSION VERSION_LESS 1.3)
    message(WARNING "
    Expected SPEC2000 version 1.3 or newer, found ${VERSION}
")
  endif()
  add_subdirectory(CFP2000)
  add_subdirectory(CINT2000)
endif()

llvm_externals_find(TEST_SUITE_SPEC2006_ROOT "speccpu2006" "SPEC CPU2006")
if(TEST_SUITE_SPEC2006_ROOT)
  file(READ ${TEST_SUITE_SPEC2006_ROOT}/version.txt VERSION)
  if (VERSION VERSION_LESS 1.2)
    message(WARNING "
    Expected SPEC2006 version 1.2 or newer, found ${VERSION}
")
  endif()
  add_subdirectory(CINT2006)
  add_subdirectory(CFP2006)
endif()

file(COPY lit.local.cfg DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")
