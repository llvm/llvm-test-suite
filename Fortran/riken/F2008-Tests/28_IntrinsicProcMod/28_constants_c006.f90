! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: F2008:13.8.2.21 REAL32, REAL64, and REAL128
  
program main
  implicit none

  ! ====================
  ! C-2
  ! E-2
  ! ====================
  print *, real_kinds

end program main

! FLANG: 28_constants_c006.f90:13:
! FLANG-SAME: error:

! GFORT: 28_constants_c006.f90:13:
! GFORT-NOT: .f90
! GFORT: Error:
