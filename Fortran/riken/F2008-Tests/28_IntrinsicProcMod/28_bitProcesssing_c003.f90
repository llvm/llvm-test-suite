! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: F2008 3.3.2.5

! ====================
! A-1 DSHIFTL / B-1 default / C-1 default / D-2 binary / E-1 decimal / F-4 BITSIZE < shift
! ====================

program main
  use iso_fortran_env
  implicit none

  print*, dshiftr(B"10000",10,33)

end program main

! GFORT: 28_bitProcesssing_c003.f90:14:
! GFORT-NOT: .f90
! GFORT: Error:

! FLANG: 28_bitProcesssing_c003.f90:14:
! FLANG-SAME: error:
