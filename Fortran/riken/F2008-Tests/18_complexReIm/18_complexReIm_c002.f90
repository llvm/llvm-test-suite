! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: F2008 C621

! ====================
! A-2 %mi
! B-2 not complex
! C-2 reference
! D-2 array
! ====================
program main
  implicit none
  real :: x(3)

  print *, x%im

end program

! GFORT: 18_complexReIm_c002.f90:16:
! GFORT-NOT: .f90
! GFORT: Error:

! FLANG: 18_complexReIm_c002.f90:16:
! FLANG-SAME: error:
