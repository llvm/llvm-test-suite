! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: F2008 3.3.2.5

! ====================
! A-2 DSHIFTR / B-3 int64 / C-2 int32 / D-1 decimal / E-1 decinal / F-1 positive
! ====================

program main
  use iso_fortran_env
  implicit none
  integer(int64) :: i64
  integer(int32) :: j32

  i64 = 2
  j32 = 10
  print*, dshiftr(i64,j32,10)
  
end program main

! GFORT: 28_bitProcesssing_c002.f90:18:
! GFORT-NOT: .f90
! GFORT: Error:

! FLANG: 28_bitProcesssing_c002.f90:18:
! FLANG-SAME: error:
