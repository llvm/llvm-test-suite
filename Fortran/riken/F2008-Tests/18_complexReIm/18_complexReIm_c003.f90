! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: F2008 R615

! ====================
! A-1 %re
! B-3 complex-func
! C-2 reference
! D-1 scalar
! ====================
program main
  implicit none
  complex :: r, x

  x = cmplx(3.75, -3.75)

  r%re = f(x)%re
  print *, r

contains

  elemental function f(z) result(res)
    complex, intent(in) :: z
    complex :: res
    res = 2.0*z + cmplx(1.25, -1.25)
  end function f

end program

! GFORT: 18_complexReIm_c003.f90:18:
! GFORT-NOT: .f90
! GFORT: Error:

! FLANG: 18_complexReIm_c003.f90:18:
! FLANG-SAME: error:
