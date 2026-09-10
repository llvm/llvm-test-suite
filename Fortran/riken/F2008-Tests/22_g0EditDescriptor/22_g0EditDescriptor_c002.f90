! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -std=f2008 -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: F2008 Introduction, 10.7.5

! ====================
! A-8 Derived type
! B-1 g0
! C-2 pointer
! ====================
program main
  implicit none

  type t
    real, pointer :: p
  end type
  type(t) :: x
  real, target :: y = 1.5
  x%p => y
  
  print '(g0)', x

end program

! FLANG: 22_g0EditDescriptor_c002.f90:21:
! FLANG-SAME: error:

! GFORT: 22_g0EditDescriptor_c002.f90:21:
! GFORT-NOT: .f90
! GFORT: Error: