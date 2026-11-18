! SPEC: F2008 R850

! ====================
! A-6 while
! B-1 self construct
! C-1 with construct-name
! ====================

program main
  implicit none
  integer :: i = 0

  outer: do while (i < 5)
    i = i + 1
    exit outer
    write(*,*) "NG"
  end do outer

  write(*,*)  "i =",i

end program
