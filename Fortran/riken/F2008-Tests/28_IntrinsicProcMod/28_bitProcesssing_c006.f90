! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: F2008 3.3.2.5

! ====================
! A-2 MASKR / B-1 default / C-3 negative / D-2 int32
! ====================
program main
  use iso_fortran_env
  implicit none

  print*, maskr(-1,int32)
end program main

! GFORT: 28_bitProcesssing_c006.f90:13:
! GFORT-NOT: .f90
! GFORT: Error:
