! SPEC: F2008:13.7.64 GAMMA (X) (GAMMA)

program main
  use iso_fortran_env
  implicit none

  real(real32) :: x32, y32
  real(real64) :: x64, y64

  ! ====================
  ! A-4
  ! B-1
  ! ====================
  x32 = 1.0
  y32 = gamma(x32)
  if (abs(1.000 - y32) < 0.001) then
    print *, "gamma(x32): OK"
  else
    print *, "gamma(x32): NG"
  end if

  ! ====================
  ! A-4
  ! B-2
  ! ====================
  x64 = 1.0
  y64 = gamma(x64)
  if (abs(1.000 - y64) < 0.001) then
    print *, "gamma(x64): OK"
  else
    print *, "gamma(x64): NG"
  end if

end program main
