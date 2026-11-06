! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: F2008:16.9.15 asinh(x)

program main
  implicit none
  integer, parameter :: x = 1

  ! =========================
  ! A-9 asinh(x)
  ! B-5 integer
  ! =========================
  write(*,*) asinh(x)

end program

! GFORT: 28_trigHyperbolic_c002.f90:14:
! GFORT-NOT: .f90
! GFORT: Error:

! FLANG: 28_trigHyperbolic_c002.f90:14:
! FLANG-SAME: error:
