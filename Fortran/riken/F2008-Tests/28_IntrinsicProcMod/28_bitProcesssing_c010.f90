! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: F2008 3.3.2.5

! ====================
! A-1 MERGE_BITS / B-1 int32 / C-1 int64 / D-1 default / E-1 decimal / F-1 decimal / G-1 decimal
! ====================
program main
  use iso_fortran_env
  implicit none
  integer(int32) :: i32
  integer(int64) :: j64

  i32 = 10
  j64 = 20
  print*, merge_bits(i32,j64,10)
end program main

! GFORT: 28_bitProcesssing_c010.f90:17:
! GFORT-NOT: .f90
! GFORT: Error:

! FLANG: 28_bitProcesssing_c010.f90:17:
! FLANG-SAME: error:
