! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: F2008 3.3.2.5

! ====================
! A-1 MERGE_BITS / B-1 default / C-1 default / D-1 default / E-3 octal / F-4 hex / G-1 decimal
! ====================
program main
  use iso_fortran_env
  implicit none
  integer(int32) :: i32
  integer(int64) :: m64

  print*, merge_bits(O"10",Z"A",10)
end program main

! GFORT: 28_bitProcesssing_c012.f90:15:
! GFORT-NOT: .f90
! GFORT: Error:

! FLANG: 28_bitProcesssing_c012.f90:15:
! FLANG-SAME: error:
