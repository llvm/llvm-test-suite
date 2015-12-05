llvm_externals_find(TEST_SUITE_NURBS_ROOT "nurbs" "Nurbs")

if(TEST_SUITE_NURBS_ROOT)
  set(PROG nurbs)
  file(GLOB Source ${TEST_SUITE_NURBS_ROOT}/*.cpp)
  list(APPEND LDFLAGS -lstdc++)
  list(APPEND LIBS -lstdc++)
  if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    list(APPEND CPPFLAGS -DDWORD_IS_ULL)
  endif()

  llvm_test_run(/k all timed /t 500 /vsteps 192 /usteps 192 /vcp 20 /ucp 20)
  llvm_test_verify(${CMAKE_BINARY_DIR}/tools/fpcmp
    %o
    ${CMAKE_CURRENT_SOURCE_DIR}/nurbs.reference_output
  )

  llvm_multisource()
endif()
