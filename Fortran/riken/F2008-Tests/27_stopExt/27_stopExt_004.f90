! SPEC: F2008 R856

! ====================
! A-1 stop
! B-2 character
! C-1 scalar
! D-2 constant
! ====================

program main
  implicit none
  character(6), parameter :: msg = "Err999"
  integer :: i, r

  do i = 1, 10
    r = i * i
    if (r == 25) then
      stop msg
    end if
  end do

end program
