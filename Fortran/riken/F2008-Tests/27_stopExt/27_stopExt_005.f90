! SPEC: F2008 R856

! ====================
! A-2 error stop
! B-2 character
! C-1 scalar
! D-2 constant-exp literal
! ====================

program main
  implicit none
  integer :: i, r

  do i = 1, 10
    r = i * i
    if (r == 25) then
      error stop 'Err'//'999'
    end if
  end do

end program
