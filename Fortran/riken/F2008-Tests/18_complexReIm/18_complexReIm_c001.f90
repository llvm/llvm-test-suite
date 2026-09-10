! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: F2008 C621

! ====================
! A-1 %re
! B-2 not complex
! C-1 define
! D-1 scalar
! ====================
program main
  implicit none
  real :: x

  x%re = 1.25
  print *, x%re

end program

! GFORT: 18_complexReIm_c001.f90:16:
! GFORT-NOT: .f90
! GFORT: Error:

! FLANG: 18_complexReIm_c001.f90:16:
! FLANG-SAME: error:
