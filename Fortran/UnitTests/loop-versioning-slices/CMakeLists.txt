if(NOT CMAKE_Fortran_COMPILER_ID MATCHES "LLVMFlang")
  return()
endif()

# Exercise slice versioning with the ordinary frontend defaults.
set(Source loop-versioning-unit-slices.f90)
set(FFLAGS -O3 -fversion-loops-for-stride)
llvm_singlesource()
set_target_properties(loop-versioning-unit-slices PROPERTIES
  Fortran_MODULE_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/default-mod")

# Verify slices whose descriptor is produced by frontend array repacking.
set(Source loop-versioning-unit-slices-repack.f90)
set(FFLAGS
  -O3
  -fversion-loops-for-stride
  -frepack-arrays
  -frepack-arrays-contiguity=whole)
llvm_singlesource()
set_target_properties(loop-versioning-unit-slices-repack PROPERTIES
  Fortran_MODULE_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/repack-mod")

file(COPY lit.local.cfg DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")
