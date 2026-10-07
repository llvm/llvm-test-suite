! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: F2008:16.9.17 atan(Y,X)

program main
  use iso_fortran_env, only: real32
  implicit none

  complex :: x = (1.0_real32, 1.0_real32)
  real :: y = 1.5574077_real32

  write(*,*) atan(y,x)

end program

! GFORT: 28_trigHyperbolic_c005.f90:13:
! GFORT-NOT: .f90
! GFORT: Error:

! FLANG: 28_trigHyperbolic_c005.f90:13:
! FLANG-SAME: error:
