! SPEC: F2008 R850

! ====================
! A-1 do
! B-2 nested construct(innermost do)
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

  do i = 1, 3
    cnt_i = cnt_i + 1
    do j = 1, 3
      sum = sum + a(i,j) ! << 0 + 1 + 4 + 7
      exit
    end do
  end do

  write(*,*) "sum =",sum
  write(*,*) "cnt_i =",cnt_i

end program
