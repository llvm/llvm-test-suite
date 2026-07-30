! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: F2008 3.3.2.5

! ====================
! A-2 DSHIFTR / B-1 default / C-1 default / D-3 octal / E-1 decimal / F-3 minus
! ====================

program main
  use iso_fortran_env
  implicit none

  print*, dshiftr(O"10000",10,-1)

end program main

! GFORT: 28_bitProcesssing_c004.f90:14:
! GFORT-NOT: .f90
! GFORT: Error:

! FLANG: 28_bitProcesssing_c004.f90:14:
! FLANG-SAME: error:
