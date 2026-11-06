! RUN: %flang -c %s -o /dev/null 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: F2008:16.9.17 atan(Y,X)

program main
  implicit none

  write(*,*) atan(0.0,0.0)

end program

! GFORT: 28_trigHyperbolic_c009.f90:9:
! GFORT-NOT: .f90
! GFORT: Error:

! FLANG: 28_trigHyperbolic_c009.f90:9:
! FLANG-SAME: warning:
