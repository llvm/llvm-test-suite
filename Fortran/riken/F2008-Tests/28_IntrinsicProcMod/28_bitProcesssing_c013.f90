! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: F2008 3.3.2.5

! ====================
! A-1 IALL / B-1 int32 / C-1 DIM > rank / D-1 none
! ====================
program main
  use iso_fortran_env
  implicit none
  integer(int32),dimension(5,3) :: a
  data a/1,3,5,7,9,2,4,6,8,10,4,3,5,7,9/

  print*, iall(a,3)
end program main

! GFORT: 28_bitProcesssing_c013.f90:15:
! GFORT-NOT: .f90
! GFORT: Error:

! FLANG: 28_bitProcesssing_c013.f90:15:
! FLANG-SAME: error:
