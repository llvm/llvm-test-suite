# This file should only contain add_subdirectory(...) one for each test
# directory

# Some tests need REAL128 (e.g. via SELECTED_REAL_KIND or the iso_fortran_env
# REAL128 constant). Not every compiler/platform combination supports it
# (e.g. this is not available in the flang build used to validate this
# integration on arm64 macOS), so probe for it once here and let affected
# directories gate on RIKEN_HAS_REAL128.
include(CheckFortranSourceCompiles)
CHECK_FORTRAN_SOURCE_COMPILES("
program t
  use iso_fortran_env
  implicit none
  real(real128) :: x
  x = 1.0_real128
end program
" RIKEN_HAS_REAL128)

add_subdirectory(F2008-Tests)
