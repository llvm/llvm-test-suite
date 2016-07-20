set(NO_REFERENCE_OUTPUT true)
if(ARCH STREQUAL "x86")
  add_subdirectory(vector_widen)
endif()
