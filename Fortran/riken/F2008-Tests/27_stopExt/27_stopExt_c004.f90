! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -std=f2008 -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: F2008 R855,R857

! ====================
! A-1 stop
! B-4 complex
! C-1 scalar
! D-1 constant
! ====================

program main
  implicit none
  complex, parameter :: val = (1.0, 2.0)
  integer :: i, r

  do i = 1, 10
    r = i * i
    if (r == 25) then
      stop val  ! << complex
    end if
  end do

end program

! GFORT: 27_stopExt_c004.f90:21:
! GFORT-NOT: .f90
! GFORT: Error:

! FLANG: 27_stopExt_c004.f90:21:
! FLANG-SAME: error:
