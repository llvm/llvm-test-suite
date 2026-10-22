! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: F2008:13.7.61 FINDLOC

program main
  implicit none
  integer :: a(3) = [1,2,3]
  real :: m(3) = [1.0,0.0,1.0]

  ! ====================
  ! D-4 invalid mask type (REAL)
  ! ====================
  print *, findloc(a, 2, mask=m)

end program

! GFORT: 28_findloc_c008.f90:14:
! GFORT-NOT: .f90
! GFORT: Error:

! FLANG: 28_findloc_c008.f90:14:
! FLANG-SAME: error:
