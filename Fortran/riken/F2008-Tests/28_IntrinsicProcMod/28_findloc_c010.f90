! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: F2008:13.7.61 FINDLOC

program main
  implicit none
  integer :: a(3) = [1,2,3]

  ! ====================
  ! E-4 kind real
  ! ====================
  print *, findloc(a, 2, kind=1.0)

end program

! GFORT: 28_findloc_c010.f90:13:
! GFORT-NOT: .f90
! GFORT: Error:

! FLANG: 28_findloc_c010.f90:13:
! FLANG-SAME: error:
