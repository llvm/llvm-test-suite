! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: F2008:13.8.2.11 INT8, INT16, INT32, and INT64
  
program main
  use iso_fortran_env
  implicit none

  ! ====================
  ! A-5
  ! E-1
  ! ====================
  integer(int15) :: x

end program main

! FLANG: 28_constants_c001.f90:14:
! FLANG-SAME: error:

! GFORT: 28_constants_c001.f90:14:
! GFORT-NOT: .f90
! GFORT: Error:
