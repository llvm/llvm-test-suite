! SPEC: F2008:13.7.56 ERFC_SCALED (X)
  
program main
  use iso_fortran_env
  implicit none

  real(real32) :: x32, y32
  real(real64) :: x64, y64

  ! ====================
  ! A-3
  ! B-1
  ! ====================
  x32 = 20.0
  y32 = erfc_scaled(x32)

  if (abs(0.02817434874 - y32) < 0.00000001) then
    print *, "erfc_scaled(x32): OK"
  else
    print *, "erfc_scaled(x32): NG"
  end if

  ! ====================
  ! A-3
  ! B-2
  ! ====================
  x64 = 20.0
  y64 = erfc_scaled(x64)
  if (abs(0.02817434874 - y64) < 0.00000001) then
    print *, "erfc_scaled(x64): OK"
  else
    print *, "erfc_scaled(x64): NG"
  end if

end program main
