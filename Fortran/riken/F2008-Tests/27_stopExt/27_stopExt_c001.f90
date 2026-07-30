! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -std=f2008 -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: F2008 R855,R857,C850

! ====================
! A-1 stop
! B-1 integer
! C-1 scalar
! D-1 constant
! E-4 default selected_int_kind(18)
! ====================

program main
  use iso_fortran_env
  implicit none
  integer :: i, r

  do i = 1, 10
    r = i * i
    if (r == 25) then
      stop int(5,selected_int_kind(18))
    end if
  end do

end program

! GFORT: 27_stopExt_c001.f90:22:
! GFORT-NOT: .f90
! GFORT: Error:

! FLANG: 27_stopExt_c001.f90:22:
! FLANG-SAME: error:
