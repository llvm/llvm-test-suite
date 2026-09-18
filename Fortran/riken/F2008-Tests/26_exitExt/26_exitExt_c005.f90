! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: F2008 C844

! ====================
! A-2 block
! B-1 self construct
! C-2 no construct-name
! ====================

program main
  implicit none
  integer :: a(3,3)
  integer :: i, j ,cnt_i, sum

  do i = 1, 3
    do j = 1, 3
      a(i,j) = (i-1)*3 + j  ! << 1,2,3,4,5,6,7,8,9
    end do
  end do
  
  sum = 0
  cnt_i = 0

  outer: block
    exit
    do i = 1, 3
      cnt_i = cnt_i + 1
      do j = 1, 3
        sum = sum + a(i,j)
      end do
    end do
    write (*,*) "NG"
  end block outer

  write(*,*) "sum =",sum
  write(*,*) "cnt_i =",cnt_i

end program

! GFORT: 26_exitExt_c005.f90:27:
! GFORT-NOT: .f90
! GFORT: Error:

! FLANG: 26_exitExt_c005.f90:27:
! FLANG-SAME: error:
