include(CheckFortranSourceCompiles)

CHECK_FORTRAN_SOURCE_COMPILES("
real(kind=16)::r
integer(kind=16)::i
end
" FORTRAN_HAS_R16)

list(APPEND FFLAGS -funsigned)

if(FORTRAN_HAS_R16)
  message(STATUS "Fortran compiler supports real(kind=16)")
  set(Source fp_convert_r16.f90)
  llvm_singlesource()
else()
  message(STATUS "Fortran compiler does not support real(kind=16)")
endif()

set(Source fp_convert.f90)
llvm_singlesource()
file(COPY lit.local.cfg DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")
