! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: F2008:16.9.17 atan(Y,X)

program main
  implicit none

  integer :: y = 1

  write(*,*) atan(y, 0.0)

end program

! GFORT: 28_trigHyperbolic_c007.f90:11:
! GFORT-NOT: .f90
! GFORT: Error:

! FLANG: 28_trigHyperbolic_c007.f90:11:
! FLANG-SAME: error:
