include(External)
llvm_externals_find(TEST_SUITE_SKIDMARKS10_ROOT "skidmarks10" "Skidmarks 10")

if(TEST_SUITE_SKIDMARKS10_ROOT)
  list(APPEND CPPFLAGS -I${TEST_SUITE_SKIDMARKS10_ROOT}/source)
  if(ARCH STREQUAL "x86")
    list(APPEND CFLAGS -msse3)
  endif()

  llvm_test_run(WORKDIR %S
    0 golden
  )
  file(GLOB SOURCES ${TEST_SUITE_SKIDMARKS10_ROOT}/source/*.c)
  llvm_test_executable(skidmarks ${SOURCES})
  llvm_test_data(skidmarks SOURCE_DIR ${TEST_SUITE_SKIDMARKS10_ROOT} golden)
endif()
