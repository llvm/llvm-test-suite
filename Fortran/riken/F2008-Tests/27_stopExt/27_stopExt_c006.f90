! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -std=f2008 -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: F2008 R855,R857

! ====================
! A-2 error stop
! B-6 type
! C-1 scalar
! D-1 constant
! ====================

program main
  implicit none
  integer :: i, r
 
 type :: t
    integer :: x
  end type

  type(t), parameter :: val = t(5)

  do i = 1, 10
    r = i * i
    if (r == 25) then
      error stop val   ! << type
    end if
  end do
end program

! GFORT: 27_stopExt_c006.f90:26:
! GFORT-NOT: .f90
! GFORT: Error:

! FLANG: 27_stopExt_c006.f90:26:
! FLANG-SAME: error:
