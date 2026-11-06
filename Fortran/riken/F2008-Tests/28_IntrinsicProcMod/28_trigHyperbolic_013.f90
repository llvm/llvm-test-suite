! SPEC: F2008:16.9.17 atan(Y,X)

program main
  use iso_fortran_env, only: real32
  implicit none

  integer, parameter :: r32 = real32
  real(r32), parameter :: tol = 1.0e-6_r32

  real(r32) :: x, y, r1, r2, err

  x = 1.0_r32
  y = 1.5574077_r32

  r1 = atan(y,x)
  r2 = atan2(y,x)

  ! check
  err = abs(r1 - r2)

  if (err < tol) then
    write(*,'(A,A)') "ATAN(y,x)", " : OK"
  else
    write(*,'(A,A)') "ATAN(y,x)", " : NG"
    write(*,'(A,2F18.16)') "  result =", r1
    write(*,'(A,2F18.16)') "  expect =", r2
    write(*,'(A,2F18.16)') "  error  =", err
  end if

end program
