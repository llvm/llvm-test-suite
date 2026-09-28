! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: F2008:16.9.17 atan(Y,X)

program main
  use iso_fortran_env, only: int32
  implicit none
  complex(int32) :: x = (1.0, 1.0)

  write(*,*) atan(0.0, x)

end program

! GFORT: 28_trigHyperbolic_c006.f90:11:
! GFORT-NOT: .f90
! GFORT: Error:

! FLANG: 28_trigHyperbolic_c006.f90:11:
! FLANG-SAME: error:
