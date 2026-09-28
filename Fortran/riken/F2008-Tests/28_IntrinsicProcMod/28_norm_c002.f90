! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: 13.7.123 NORM2 (X [, DIM])

program main
  use iso_fortran_env
  implicit none

  integer(int32),dimension(2) :: a
  data a/1,2/

  ! ====================
  ! A-1 array / B-2 int
  ! ====================
  print*, norm2(a)

end program main

! GFORT: 28_norm_c002.f90:16:
! GFORT-NOT: .f90
! GFORT: Error:

! FLANG: 28_norm_c002.f90:16:
! FLANG-SAME: error:  
