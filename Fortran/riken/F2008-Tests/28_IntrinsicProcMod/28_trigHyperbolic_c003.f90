! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: F2008 16.9.19 atanh(x)

program main
  implicit none
  integer, parameter :: x = 1

  ! =========================
  ! A-10 atanh(x)
  ! B-5 integer
  ! =========================
  write(*,*) atanh(x)

end program

! GFORT: 28_trigHyperbolic_c003.f90:14:
! GFORT-NOT: .f90
! GFORT: Error:

! FLANG: 28_trigHyperbolic_c003.f90:14:
! FLANG-SAME: error:
