! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: F2008:13.7.61 FINDLOC

program main
  implicit none
  integer :: a(2,2) = reshape([1,2,3,4],[2,2])

  ! ====================
  ! C-3 dim < 1
  ! ====================
  print *, findloc(a, 2, dim=0)

end program

! GFORT: 28_findloc_c005.f90:13:
! GFORT-NOT: .f90
! GFORT: Error:

! FLANG: 28_findloc_c005.f90:13:
! FLANG-SAME: error:
