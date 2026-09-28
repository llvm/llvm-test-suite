! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: F2008 13.7.160 STORAGE SIZE (A [, KIND])

! ====================
! A-1 constant B-2 real C-2 real
! ====================
program main
  use iso_fortran_env
  implicit none
  real(real32) :: r1

  r1 = 4

  print*, storage_size(1.1,r1)
  
end program main

! GFORT: 28_storageSize_c001.f90:16:
! GFORT-NOT: .f90
! GFORT: Error:

! FLANG: 28_storageSize_c001.f90:16:
! FLANG-SAME: error:
