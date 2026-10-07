! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: F2008 3.3.2.5

! ====================
! A-2 DSHIFTR / B-1 default / C-1 default / D-2 binary / E-2 binary / F-1 positive
! ====================

program main
  use iso_fortran_env
  implicit none

  print*, dshiftr(B"10",B"1000000000000000000000000000000",30)
  
end program main

! GFORT: 28_bitProcesssing_c001.f90:14:
! GFORT-NOT: .f90
! GFORT: Error:

! FLANG: 28_bitProcesssing_c001.f90:14:
! FLANG-SAME: error:
