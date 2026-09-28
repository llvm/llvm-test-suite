! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: F2008 C845

! ====================
! A-10 do concurrent
! B-1 self construct
! C-1 with construct-name
! ====================

program main
  implicit none
  integer :: i, j
  integer :: a(3,3)

  outer: do concurrent (i=1:3)
    inner: do j = 1,3
      if (j == 2) exit outer
    end do inner
  end do outer
end program

! GFORT: 26_exitExt_c003.f90:19:
! GFORT-NOT: .f90
! GFORT: Error:

! FLANG: 26_exitExt_c003.f90:19:
! FLANG-SAME: error:
