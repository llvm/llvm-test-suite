list(APPEND CPPFLAGS -std=c++11)

if(NOT MIPS_IS_MIPS16_ENABLED)
  llvm_add_subdirectories(frame_layout)
endif()
