! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: F2008:13.8.2.21 REAL32, REAL64, and REAL128
  
program main
  use iso_fortran_env
  implicit none

  ! ====================
  ! B-4
  ! E-1
  ! ====================
  real(real31) :: x

end program main

! FLANG: 28_constants_c004.f90:14:
! FLANG-SAME: error:

! GFORT: 28_constants_c004.f90:14:
! GFORT-NOT: .f90
! GFORT: Error:
