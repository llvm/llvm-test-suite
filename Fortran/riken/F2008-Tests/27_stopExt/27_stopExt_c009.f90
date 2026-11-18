! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -std=f2008 -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: F2008 R855,R857

! ====================
! A-1 stop
! B-1 integer
! C-1 scalar
! D-4 variable-expr
! E-1 default
! ====================

program main
  implicit none
  integer :: i, r, a, b
  

  do i = 1, 10
    a = i + 1
    b = i * 2
    r = a + b
    if (r > 25) then
      stop a + b
    end if
  end do
end program

! GFORT: 27_stopExt_c009.f90:24:
! GFORT-NOT: .f90
! GFORT: Error:

! FLANG: 27_stopExt_c009.f90:24:
! FLANG-SAME: error:
