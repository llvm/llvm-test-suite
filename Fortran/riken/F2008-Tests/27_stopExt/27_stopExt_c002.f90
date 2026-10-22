! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -std=f2008 -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: F2008 R856,R857,C850

! ====================
! A-2 error stop
! B-1 integer
! C-1 scalar
! D-1 constant-expr
! E-5 default kind=int64
! ====================

program main
  use iso_fortran_env
  implicit none
  integer(kind=int64), parameter :: a = 2 ,b = 3
  integer :: i, r

  do i = 1, 10
    r = i * i
    if (r == 25) then
      error stop a + b
    end if
  end do

end program

! GFORT: 27_stopExt_c002.f90:23:
! GFORT-NOT: .f90
! GFORT: Error:

! FLANG: 27_stopExt_c002.f90:23:
! FLANG-SAME: error:
