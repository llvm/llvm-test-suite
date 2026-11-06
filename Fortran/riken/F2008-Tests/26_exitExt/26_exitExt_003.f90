! SPEC: F2008 R850

! ====================
! A-2 block
! B-1 self construct
! C-1 with construct-name
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
    exit outer
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
