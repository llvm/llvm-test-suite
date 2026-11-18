! SPEC: F2008:16.9.5,15,19 acosh,asinh,atanh

program main
  use iso_fortran_env, only: real64
  implicit none

  integer, parameter :: r64 = real64
  real(r64), parameter :: pi = 3.1415926535897932_r64
  real(r64), parameter :: tol = 1.0e-14_r64

  real(r64) :: x, r1, r2

  ! =========================
  ! A-8 acosh(x)
  ! B-2 real64
  ! =========================
  x = 1.5430806_r64
  r1 = acosh(x)
  r2 = log(x + sqrt(x + 1.0) * sqrt(x - 1.0))
  call check("ACOSH", r1, r2, tol)

  ! =========================
  ! A-9 asinh(x)
  ! B-2 real64
  ! =========================
  x = 1.1752012_r64
  r1 = asinh(x)
  r2 = log(x + sqrt(x*x + 1.0))
  call check("ASINH", r1, r2, tol)

  ! =========================
  ! A-10 atanh(x)
  ! B-2 real64
  ! =========================
  x = 0.76159416_r64
  r1 = atanh(x)
  r2 = 0.5 * log((1.0 + x) / (1.0 - x))
  call check("ATANH", r1, r2, tol)

contains

  subroutine check(name, a, b, tol)
    character(*), intent(in) :: name
    real(real64), intent(in) :: a, b
    real(real64), intent(in) :: tol
    real(real64) :: err

    err = abs(a - b)

    if (err < tol) then
      write(*,'(A14,A)') name, " : OK"
    else
      write(*,'(A14,A)') name, " : NG"
      write(*,'(A14,F12.7)') "  result =", a
      write(*,'(A14,F12.7)') "  expect =", b
      write(*,'(A14,F12.7)') "  error  =", err
    end if
  end subroutine check

end program
