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
  llvm_add_subdirectories(CINT95)
  # Note that CFP95 tests are all fortran so not supported by cmake/lit yet
endif()

llvm_externals_find(TEST_SUITE_SPEC2000_ROOT "speccpu2000" "SPEC CPU2000")
if(TEST_SUITE_SPEC2000_ROOT)
  llvm_add_subdirectories(CFP2000 CINT2000)
endif()

llvm_externals_find(TEST_SUITE_SPEC2006_ROOT "speccpu2006" "SPEC CPU2006")
if(TEST_SUITE_SPEC2006_ROOT)
  llvm_add_subdirectories(CINT2006 CFP2006)
endif()

file(COPY lit.local.cfg DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")
