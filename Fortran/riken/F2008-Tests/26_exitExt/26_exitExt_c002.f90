! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: F2008 C844

! ====================
! A-9 where
! B-1 self construct
! C-1 with construct-name
! ====================

program main
  implicit none
  integer :: a(7) = [1,-1,2,-2,3,-3,4]

  outer: where (a > 0)
    a = a * 10
    exit outer
    write(*,*) "NG"
  end where outer

  write(*,*)  "a =",a

end program

! GFORT: 26_exitExt_c002.f90:18:
! GFORT-NOT: .f90
! GFORT: Error:

! FLANG: 26_exitExt_c002.f90:18:
! FLANG-SAME: error:
