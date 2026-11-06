! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: F2008:16.9.17 atan(Y,X)

program main
  implicit none

  type :: t
    real :: v
  end type

  type(t) :: y
  y%v = 1.5574077

  write(*,*) atan(y, 0.0)

end program

! GFORT: 28_trigHyperbolic_c008.f90:16:
! GFORT-NOT: .f90
! GFORT: Error:

! FLANG: 28_trigHyperbolic_c008.f90:16:
! FLANG-SAME: error:
