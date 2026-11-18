! SPEC: F2008:13.7.54 ERF (X)
  
program main
  use iso_fortran_env
  implicit none

  real(real32) :: x32, y32
  real(real64) :: x64, y64

  ! ====================
  ! A-1
  ! B-1
  ! ====================
  x32 = 1.0
  y32 = erf(x32)
  if (abs(0.843 - y32) < 0.001) then
    print *, "erf(x32): OK"
  else
    print *, "erf(x32): NG"
  end if

  ! ====================
  ! A-1
  ! B-2
  ! ====================
  x64 = 1.0
  y64 = erf(x64)
  if (abs(0.843 - y64) < 0.001) then
    print *, "erf(x64): OK"
  else
    print *, "erf(x64): NG"
  end if

end program main
