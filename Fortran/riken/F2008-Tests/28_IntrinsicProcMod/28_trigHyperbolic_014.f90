! SPEC: F2008:16.9.17 atan(Y,X)

program main
  use iso_fortran_env, only: real64
  implicit none

  integer, parameter :: r64 = real64
  real(r64), parameter :: tol = 1.0e-14_r64

  real(r64) :: x, y, r1, r2, err

  x = 1.0_r64
  y = 1.5574077_r64

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
