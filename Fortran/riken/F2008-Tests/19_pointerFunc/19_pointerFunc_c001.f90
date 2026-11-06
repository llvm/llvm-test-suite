! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: F2008 R602 C602

module mod
contains
  function f(x) result(res)
    real, intent(in) :: x
    real :: res
    res = x
  end function f
end module mod


program main
  use mod
  real :: a

  a = 3.0
  f(a) = 10.0
end program main

! GFORT: 19_pointerFunc_c001.f90:21:
! GFORT-NOT: .f90
! GFORT: Error:

! FLANG: 19_pointerFunc_c001.f90:21:
! FLANG-SAME: error:

