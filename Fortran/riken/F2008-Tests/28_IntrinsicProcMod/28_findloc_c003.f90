! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: F2008:13.7.61 FINDLOC

program main
  implicit none
  integer :: a(3) = [1,2,3]
  integer :: v(2) = [2,3]

  ! ====================
  ! B-2 non-comparable : array
  ! ====================
  print *, findloc(a, v)

end program

! GFORT: 28_findloc_c003.f90:14:
! GFORT-NOT: .f90
! GFORT: Error:

! FLANG: 28_findloc_c003.f90:14:
! FLANG-SAME: error:
