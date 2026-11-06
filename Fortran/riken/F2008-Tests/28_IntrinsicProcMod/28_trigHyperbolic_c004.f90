! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: F2008:16.9.17 atan(Y,X)

program main
  use iso_fortran_env, only: real32,real64
  implicit none

  write(*,*) atan(1.5574077_real32,1.0_real64)

end program

! GFORT: 28_trigHyperbolic_c004.f90:10:
! GFORT-NOT: .f90
! GFORT: Error:

! FLANG: 28_trigHyperbolic_c004.f90:10:
! FLANG-SAME: error:
