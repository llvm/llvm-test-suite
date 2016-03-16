llvm_add_subdirectories(C++11)
if(ARCH STREQUAL "Mips")
  llvm_add_subdirectories(Mips)
endif()
