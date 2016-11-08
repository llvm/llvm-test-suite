# Nurbs uses SSE and only works on x86.
if(ARCH STREQUAL "x86")
  llvm_externals_find(TEST_SUITE_NURBS_ROOT "nurbs" "Nurbs")

  if(TEST_SUITE_NURBS_ROOT)
    list(APPEND LDFLAGS -lstdc++)
    if(CMAKE_SIZEOF_VOID_P EQUAL 8)
      list(APPEND CPPFLAGS -DDWORD_IS_ULL)
    endif()

    llvm_test_run(/k all timed /t 500 /vsteps 192 /usteps 192 /vcp 20 /ucp 20)
    llvm_test_verify(${FPCMP}
      %o
      ${CMAKE_CURRENT_SOURCE_DIR}/nurbs.reference_output
    )

    file(GLOB SOURCES ${TEST_SUITE_NURBS_ROOT}/*.cpp)
    llvm_test_executable(nurbs ${SOURCES})
  endif()
endif()
