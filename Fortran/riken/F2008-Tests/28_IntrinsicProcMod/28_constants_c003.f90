! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: F2008:13.8.2.12 INTEGER KINDS
  
program main
  implicit none

  ! ====================
  ! C-1
  ! E-2
  ! ====================
  print *, integer_kinds

end program main

! FLANG: 28_constants_c003.f90:13:
! FLANG-SAME: error:

! GFORT: 28_constants_c003.f90:13:
! GFORT-NOT: .f90
! GFORT: Error:
