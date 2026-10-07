! SPEC: F2008 R850

! ====================
! A-7 if
! B-1 self construct
! C-1 with construct-name
! ====================

program main
  implicit none
  integer :: i = 2
 
  outer: if (i == 2) then
    exit outer
    i = i + 1
    write(*,*) "NG"
  end if outer

  write(*,*) "i =",i

end program
