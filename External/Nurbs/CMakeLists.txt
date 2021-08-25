# Nurbs uses SSE and only works on x86.
if(ARCH STREQUAL "x86")
  include(External)
  llvm_externals_find(TEST_SUITE_NURBS_ROOT "nurbs" "Nurbs")

  if(TEST_SUITE_NURBS_ROOT)
    if(CMAKE_SIZEOF_VOID_P EQUAL 8)
      list(APPEND CPPFLAGS -DDWORD_IS_ULL)
    endif()

    llvm_test_run(/k all timed /t 500 /vsteps 192 /usteps 192 /vcp 20 /ucp 20)
    llvm_test_verify(%b/${FPCMP} %o %S/nurbs.reference_output)

    file(GLOB SOURCES ${TEST_SUITE_NURBS_ROOT}/*.cpp)
    llvm_test_executable(nurbs ${SOURCES})
    llvm_test_data(nurbs nurbs.reference_output)

    file(COPY lit.local.cfg DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")
  endif()
endif()
