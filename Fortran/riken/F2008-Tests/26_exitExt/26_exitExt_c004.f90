! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: F2008 C844

! ====================
! A-2 block
! B-3 construct outside
! C-1 with construct-name
! ====================

program main
  implicit none
  integer :: i, cnt_i

  cnt_i = 0
  outer: block
    do i = 1, 5
      cnt_i = cnt_i + 1
      if (cnt_i == 3) exit other
    end do
    write(*,*) "cnt_i =",cnt_i
  end block outer

 other: block
   write(*,*) "NG"
 end block other

end program

! GFORT: 26_exitExt_c004.f90:20:
! GFORT-NOT: .f90
! GFORT: Error:

! FLANG: 26_exitExt_c004.f90:20:
! FLANG-SAME: error:
