set(NO_REFERENCE_OUTPUT true)
if(ARCH STREQUAL "x86")
  add_subdirectory(vector_widen)

  # We need at least clang 5.0 to process the bitcode here.
  if(CMAKE_C_COMPILER_ID STREQUAL "Clang" AND
     CMAKE_CXX_COMPILER_ID STREQUAL "Clang" AND
     NOT CMAKE_C_COMPILER_VERSION VERSION_LESS "5.0" AND
     NOT CMAKE_CXX_COMPILER_VERSION VERSION_LESS "5.0")
  add_subdirectory(fft)
  endif()
endif()
