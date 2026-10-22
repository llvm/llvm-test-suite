! SPEC: F2008:16.9.4,187,188 tan,tanh

program main
  use iso_fortran_env, only: real32
  implicit none

  integer, parameter :: r32 = real32
  real(r32), parameter :: tol = 1.0e-6_r32

  complex(r32) :: i, x, r1, r2
  real(r32) :: err_re, err_im

  i = (0.0_r32, 1.0_r32)
  x = (0.5_r32, 0.5_r32)

  ! =========================
  ! A-6 tan(x)
  ! A-7 tanh(x)
  ! B-2 real32
  ! tanh(x) = -i * tan(i*x)
  ! =========================
  r1 = tanh(x)
  r2 = - i * tan(i*x)

  ! check
  err_re = abs(real(r1) - real(r2))
  err_im = abs(aimag(r1) - aimag(r2))

  if (err_re < tol .and. err_im < tol) then
    write(*,'(A,A)') "TANH", " : OK"
  else
    write(*,'(A,A)') "TANH", " : NG"
    write(*,'(A,2F18.16)') "  result =", r1
    write(*,'(A,2F18.16)') "  expect =", r2
    write(*,'(A,2F18.16)') "  error  =", err_re, err_im
  end if

end program
