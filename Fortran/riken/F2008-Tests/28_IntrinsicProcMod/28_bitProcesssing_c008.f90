! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: F2008 3.3.2.5

! ====================
! A-3 SHIFTR / B-1 default / C-1 default / D-1 positive / E-3 negative
! ====================
program main
  use iso_fortran_env
  implicit none

  print*, shiftr(1,-1)
end program main

! GFORT: 28_bitProcesssing_c008.f90:13:
! GFORT-NOT: .f90
! GFORT: Error:

! FLANG: 28_bitProcesssing_c008.f90:13:
! FLANG-SAME: error:
  
