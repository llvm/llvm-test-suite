! SPEC: F2008:16.9.4,14 acos,asin

program main
  use iso_fortran_env, only: real64
  implicit none

  integer, parameter :: r64 = real64
  real(r64), parameter :: pi = 3.1415926535897932_r64
  real(r64), parameter :: tol = 1.0e-14_r64

  complex(r64) :: x, r1, r2
  real(r64) :: err_re, err_im

  x = (0.5_r64, 0.5_r64)

  ! =========================
  ! A-1 asin(x)
  ! A-2 acos(x)
  ! B-3 real64
  ! asin(x) + acos(x) = pi/2
  ! =========================
  r1 = asin(x) + acos(x)
  r2 = cmplx(pi/2.0_r64, 0.0_r64, kind=r64)

  ! check
  err_re = abs(real(r1) - real(r2))
  err_im = abs(aimag(r1) - aimag(r2))

  if (err_re < tol .and. err_im < tol) then
    write(*,'(A,A)') "ASIN+ACOS", " : OK"
  else
    write(*,'(A,A)') "ASIN+ACOS", " : NG"
    write(*,'(A,2F18.16)') "  result =", r1
    write(*,'(A,2F18.16)') "  expect =", r2
    write(*,'(A,2F18.16)') "  error  =", err_re, err_im
  end if

end program
