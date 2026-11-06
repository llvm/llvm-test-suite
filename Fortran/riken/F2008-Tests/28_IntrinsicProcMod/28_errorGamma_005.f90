! SPEC: F2008:13.7.69 HYPOT (X, Y)
  
program main
  use iso_fortran_env
  implicit none

  real(real32) :: x32, y32, z32
  real(real64) :: x64, y64, z64

  ! ====================
  ! A-5
  ! B-1
  ! C-1
  ! ====================
  x32 = 3.0
  y32 = 4.0
  z32 = hypot(x32, y32)
  if (abs(5.0 - z32) < 0.001) then
    print *, "hypot(x32, y32): OK"
  else
    print *, "hypot(x32, y32): NG"
  end if

  ! ====================
  ! A-5
  ! B-2
  ! C-2
  ! ====================
  x64 = 3.0
  y64 = 4.0
  z64 = hypot(x64, y64)
  if (abs(5.0 - z64) < 0.001) then
    print *, "hypot(x64, y64): OK"
  else
    print *, "hypot(x64, y64): NG"
  end if

end program main
