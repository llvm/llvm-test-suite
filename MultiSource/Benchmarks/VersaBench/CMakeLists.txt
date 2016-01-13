set(DIRS)
set(PARALLEL_DIRS)

if("${ENDIAN}" STREQUAL "big")
  set(PARALLEL_DIRS beamformer bmm dbms ecbdes)
else()
  set(PARALLEL_DIRS 8b10b beamformer bmm dbms ecbdes)
endif()

llvm_add_subdirectories(${DIRS} ${PARALLEL_DIRS})
