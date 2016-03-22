llvm_externals_find(TEST_SUITE_SKIDMARKS10_ROOT "skidmarks10" "Skidmarks 10")

if(TEST_SUITE_SKIDMARKS10_ROOT)
  set(PROG skidmarks)
  file(GLOB Source ${TEST_SUITE_SKIDMARKS10_ROOT}/source/*.c)
  list(APPEND CPPFLAGS -I${TEST_SUITE_SKIDMARKS10_ROOT}/source)
  if(ARCH STREQUAL "x86")
    list(APPEND CPPFLAGS -msse3)
  endif()

  llvm_test_run(0 ${TEST_SUITE_SKIDMARKS10_ROOT}/golden
    WORKDIR ${CMAKE_CURRENT_BINARY_DIR})
  llvm_test_verify(${FPCMP}
    %o
    ${CMAKE_CURRENT_SOURCE_DIR}/skidmarks.reference_output
  )
  llvm_multisource()
endif()
