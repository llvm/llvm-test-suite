! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: F2008 C844

! ====================
! A-8 forall
! B-1 self construct
! C-1 with construct-name
! ====================

program main
  implicit none
  integer :: i
  integer :: a(3) = 0

  outer: forall (i=1:3)
    exit outer
    a(i) = i
  end forall outer

  write(*,*)  "a =",a

end program

! GFORT: 26_exitExt_c001.f90:18:
! GFORT-NOT: .f90
! GFORT: Error:

! FLANG: 26_exitExt_c001.f90:18:
! FLANG-SAME: error:
