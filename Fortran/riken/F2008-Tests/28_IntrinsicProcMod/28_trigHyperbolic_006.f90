! SPEC: F2008:16.9.17,187 atan,tan

program main
  use iso_fortran_env, only: real64
  implicit none

  integer, parameter :: r64 = real64
  real(r64), parameter :: tol = 1.0e-14_r64

  complex(r64) :: x, r1, r2
  real(r64) :: err_re, err_im

  x = (0.5_r64, 0.5_r64)

  ! =========================
  ! A-6 tan(x)
  ! A-3 atan(x)
  ! B-3 real64
  ! tan(atan(x)) = x
  ! =========================
  r1 = tan(atan(x))
  r2 = x

  ! check
  err_re = abs(real(r1) - real(r2))
  err_im = abs(aimag(r1) - aimag(r2))

  if (err_re < tol .and. err_im < tol) then
    write(*,'(A,A)') "TAN(ATAN)", " : OK"
  else
    write(*,'(A,A)') "TAN(ATAN)", " : NG"
    write(*,'(A,2F18.16)') "  result =", r1
    write(*,'(A,2F18.16)') "  expect =", r2
    write(*,'(A,2F18.16)') "  error  =", err_re, err_im
  end if

end program
