! SPEC: F2008 Error and gamma (LOG_GAMMA)
  
program main
  use iso_fortran_env
  implicit none

  real(real32) :: x32, y32
  real(real64) :: x64, y64

  ! ====================
  ! A-6
  ! B-1
  ! ====================
  x32 = 3.0
  y32 = log_gamma(x32)
  if (abs(0.693 - y32) < 0.001) then
    print *, "log_gamma(x32): OK"
  else
    print *, "log_gamma(x32): NG"
  end if

  ! ====================
  ! A-6
  ! B-2
  ! ====================
  x64 = 3.0
  y64 = log_gamma(x64)
  if (abs(0.693 - y32) < 0.001) then
    print *, "log_gamma(x64): OK"
  else
    print *, "log_gamma(x64): NG"
  end if

end program main
