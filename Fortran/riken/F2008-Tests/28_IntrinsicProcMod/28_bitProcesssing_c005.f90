! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: F2008 3.3.2.5

! ====================
! A-1 MASKL / B-1 default / C-4 BITSIZE < value / D-1 none
! ====================
program main
  use iso_fortran_env
  implicit none
  
  print*, maskl(33)
end program main

! GFORT: 28_bitProcesssing_c005.f90:13:
! GFORT-NOT: .f90
! GFORT: Error:
