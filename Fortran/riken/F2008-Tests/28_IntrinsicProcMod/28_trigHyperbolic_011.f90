! SPEC: F2008:16.9.5,15,19 acosh,asinh,atanh

program main
  use iso_fortran_env, only: real32
  implicit none

  integer, parameter :: r32 = real32
  real(r32), parameter :: pi = 3.14159265_r32
  real(r32), parameter :: tol = 1.0e-6_r32

  complex(r32) :: i, x, r1, r2

  x = (0.5_r32, 0.5_r32)

  ! =========================
  ! A-8 acosh(x)
  ! B-3 complex(real32)
  ! =========================
  r1 = acosh(x)
  r2 = log(x + sqrt(x + cmplx(1.0_r32,0.0_r32,kind=real32)) &
              * sqrt(x - cmplx(1.0_r32,0.0_r32,kind=real32)))
  call check("ACOSH", r1, r2, tol)
  call check_im("ACOSH range", acosh(x), -pi, pi)

  ! =========================
  ! A-9 asinh(x)
  ! B-3 complex(real32)
  ! =========================
  r1 = asinh(x)
  r2 = log(x + sqrt(x*x + cmplx(1.0_r32,0.0_r32,kind=real32)))
  call check("ASINH", r1, r2, tol)
  call check_im("ASINH range", asinh(x), -pi/2.0_r32, pi/2.0_r32)

  ! =========================
  ! A-10 atanh(x)
  ! B-3 complex(real32)
  ! =========================
  r1 = atanh(x)
  r2 = 0.5_r32 * log((cmplx(1.0_r32,0.0_r32,kind=real32) + x) / &
                       (cmplx(1.0_r32,0.0_r32,kind=real32) - x))
  call check("ATANH", r1, r2, tol)
  call check_im("ATANH range", atanh(x), -pi/2.0_r32, pi/2.0_r32)

contains

  subroutine check(name, a, b, tol)
    character(*), intent(in) :: name
    complex(real32), intent(in) :: a, b
    real(real32), intent(in) :: tol

    real(real32) :: err_re, err_im

    err_re = abs(real(a) - real(b))
    err_im = abs(aimag(a) - aimag(b))

    if (err_re < tol .and. err_im < tol) then
      write(*,'(A14,A)') name, " : OK"
    else
      write(*,'(A14,A)') name, " : NG"
      write(*,'(A14,2F12.7)') "  result =", a
      write(*,'(A14,2F12.7)') "  expect =", b
      write(*,'(A14,2F12.7)') "  error  =", err_re, err_im
    end if
  end subroutine check

  subroutine check_im(name, val, minv, maxv)
    character(*), intent(in) :: name
    complex(real32), intent(in) :: val
    real(real32), intent(in) :: minv, maxv

    real(real32) :: im

    im = aimag(val)

    if (im >= minv .and. im <= maxv) then
      write(*,'(A14,A)') name, " : OK"
    else
      write(*,'(A14,A)') name, " : NG"
      write(*,'(A14,F12.7)') "  imag =", im
    end if
  end subroutine check_im

end program
