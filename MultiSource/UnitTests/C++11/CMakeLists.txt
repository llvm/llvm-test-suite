list(APPEND CPPFLAGS -std=c++11)

if(NOT MIPS_IS_MIPS16_ENABLED)
  add_subdirectory(frame_layout)
endif()
