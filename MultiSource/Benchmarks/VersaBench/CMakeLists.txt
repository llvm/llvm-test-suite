llvm_add_subdirectories(beamformer bmm dbms ecbdes)
if(NOT "${ENDIAN}" STREQUAL "big")
  llvm_add_subdirectories(8b10b)
endif()
