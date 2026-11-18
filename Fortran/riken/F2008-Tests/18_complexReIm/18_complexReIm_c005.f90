! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: F2008 R615

! ====================
! A-2 %im
! B-4 complex-expr
! C-2 reference
! D-1 scalar
! ====================
program main
  implicit none
  complex :: r, a, b

  r = cmplx(0.0, 0.0)
  a = cmplx(5.75, 5.75)
  b = cmplx(6.25, -6.25)

  r%re = (a+b)%re + 1.25
  print *, r

end program

! GFORT: 18_complexReIm_c005.f90:20:
! GFORT-NOT: .f90
! GFORT: Error:

! FLANG: 18_complexReIm_c005.f90:20:
! FLANG-SAME: error:
