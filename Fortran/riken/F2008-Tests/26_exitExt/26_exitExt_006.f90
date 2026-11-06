! SPEC: F2008 R850

! ====================
! A-5 associate
! B-1 self construct
! C-1 with construct-name
! ====================

program main
  implicit none
  integer :: a = 10

  outer: associate(x => a)
    x = 20
    exit outer
    x = 30
  end associate outer

  write(*,*)  "a =",a

end program
