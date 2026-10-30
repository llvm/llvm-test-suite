! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: F2008 3.3.2.5

! ====================
! A-1 MASKL / B-1 default / C-1 positive / D-4 zero
! ====================
program main
  use iso_fortran_env
  implicit none

  print*, maskl(1,0)
end program main

! GFORT: 28_bitProcesssing_c007.f90:13:
! GFORT-NOT: .f90
! GFORT: Error:

! FLANG: 28_bitProcesssing_c007.f90:13:
! FLANG-SAME: error:
