! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -std=f2008 -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: F2008 R855,R857

! ====================
! A-2 error stop
! B-2 character
! C-1 scalar
! D-3 variable
! E-1 default
! ====================

program main

  implicit none
  character(6) :: msg
  integer :: i, r

  msg = "Err999"

  do i = 1, 10
    r = i * i
    if (r == 25) then
      error stop msg 
    end if
  end do

end program

! GFORT: 27_stopExt_c010.f90:25:
! GFORT-NOT: .f90
! GFORT: Error:

! FLANG: 27_stopExt_c010.f90:25:
! FLANG-SAME: error:
