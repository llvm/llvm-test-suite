! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: F2008:13.8.2.11 INT8, INT16, INT32, and INT64
  
program main
  implicit none

  ! ====================
  ! A-1
  ! E-2
  ! ====================
  integer(int8) :: x

end program main

! FLANG: 28_constants_c002.f90:13:
! FLANG-SAME: error:

! GFORT: 28_constants_c002.f90:13:
! GFORT-NOT: .f90
! GFORT: Error:
