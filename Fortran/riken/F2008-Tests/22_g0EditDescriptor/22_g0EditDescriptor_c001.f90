! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -std=f2008 -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: F2008 Introduction, 10.7.5

! ====================
! A-8 Derived type
! B-1 g0
! C-1 not pointer
! ====================
program main
  implicit none

  type t
    real :: a = 111.1
    real :: b = 222.2
  end type
  type(t) :: x
  
  print '(g0)', x

end program

! FLANG: 22_g0EditDescriptor_c001.f90:20:
! FLANG-SAME: error:

! GFORT: 22_g0EditDescriptor_c001.f90:20:
! GFORT-NOT: .f90
! GFORT: Error: