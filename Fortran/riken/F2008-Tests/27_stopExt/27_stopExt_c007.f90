! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -std=f2008 -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: F2008 R855,R857

! ====================
! A-1 stop
! B-1 integer
! C-2 array
! D-1 constanta
! E-1 default
! ====================

program main
  implicit none
  integer, parameter :: val(5) = [1,2,3,4,5]
  integer :: i, r

  do i = 1, 10
    r = i * i
    if (r == 25) then
      stop val
    end if
  end do

end program

! GFORT: 27_stopExt_c007.f90:22:
! GFORT-NOT: .f90
! GFORT: Error:

! FLANG: 27_stopExt_c007.f90:22:
! FLANG-SAME: error:
