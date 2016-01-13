llvm_add_subdirectories(distray mason pcompress2 fourinarow neural pifft)
if(NOT "${ARCH}" STREQUAL "Sparc")
  llvm_add_subdirectories(analyzer)
endif()
