! SPEC: F2008 R856,R857

! ====================
! A-2 error stop
! B-1 integer
! C-1 scalar
! D-2 constant-expr
! E-3 default kind=int32
! ====================

program main
  use iso_fortran_env
  implicit none
  integer(kind=int32), parameter :: a = 2 ,b = 3
  integer :: i, r

  do i = 1, 10
    r = i * i
    if (r == 25) then
      error stop a + b
    end if
  end do

end program
