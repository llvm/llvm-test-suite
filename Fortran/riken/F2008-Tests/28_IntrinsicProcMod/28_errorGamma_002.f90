! SPEC: F2008:13.7.55 ERFC (X)
  
program main
  use iso_fortran_env
  implicit none

  real(real32) :: x32, y32
  real(real64) :: x64, y64

  ! ====================
  ! A-2
  ! B-1
  ! ====================
  x32 = 1.0
  y32 = erfc(x32)
  if (abs(0.157 - y32) < 0.001) then
    print *, "erfc(x32): OK"
  else
    print *, "erfc(x32): NG"
  end if

  ! ====================
  ! A-2
  ! B-2
  ! ====================
  x64 = 1.0
  y64 = erfc(x64)
  if (abs(0.157 - y64) < 0.001) then
    print *, "erfc(x64): OK"
  else
    print *, "erfc(x64): NG"
  end if

end program main
