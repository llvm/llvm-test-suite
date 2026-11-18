! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: F2008:13.7.61 FINDLOC

program main
  use iso_fortran_env, only: int32
  implicit none
  integer :: a(3) = [1,2,3]
  integer :: k
  
  k = 4

  ! ====================
  ! E-3 invalid kind argument (variable)
  ! ====================
  print *, findloc(a, 2, kind=k)

end program

! GFORT: 28_findloc_c009.f90:17:
! GFORT-NOT: .f90
! GFORT: Error:

! FLANG: 28_findloc_c009.f90:17:
! FLANG-SAME: error:
