! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: F2008:13.7.61 FINDLOC

program main
  implicit none
  integer :: a(2,2) = reshape([1,2,3,4],[2,2])
  real :: v = 2.0

  ! ====================
  ! C-3 rank < dim
  ! ====================
  print *, findloc(a, 2, dim=v)

end program

! GFORT: 28_findloc_c006.f90:14:
! GFORT-NOT: .f90
! GFORT: Error:

! FLANG: 28_findloc_c006.f90:14:
! FLANG-SAME: error:
