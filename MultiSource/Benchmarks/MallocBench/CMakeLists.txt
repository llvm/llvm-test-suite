llvm_add_subdirectories(espresso gs)
if(NOT "${ARCH}" STREQUAL "Alpha")
  llvm_add_subdirectories(cfrac)
endif()
