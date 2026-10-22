! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: 13.7.123 NORM2 (X [, DIM])

program main
  use iso_fortran_env
  implicit none

  real(real32) :: a
  data a/2.0/

  ! ====================
  ! A-2 scalar variable / B-1 real
  ! ====================
  print*, norm2(a)

end program main

! GFORT: 28_norm_c001.f90:16:
! GFORT-NOT: .f90
! GFORT: Error:

! FLANG: 28_norm_c001.f90:16:
! FLANG-SAME: error:  
