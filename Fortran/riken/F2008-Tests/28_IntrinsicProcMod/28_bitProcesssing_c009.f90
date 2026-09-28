! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: F2008 3.3.2.5

! ====================
! A-1 SHIFTA / B-1 int32 / C-1 default / D-1 positive / E-4 BITSIZE < shift
! ====================
program main
  use iso_fortran_env
  implicit none
  integer(int32) :: i32

  i32 = 10
  print*, shifta(i32,33)
end program main

! GFORT: 28_bitProcesssing_c009.f90:16:
! GFORT-NOT: .f90
! GFORT: Error:

! FLANG: 28_bitProcesssing_c009.f90:16:
! FLANG-SAME: error:
  
