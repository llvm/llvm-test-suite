! SPEC: F2008 R855,R857

! ====================
! A-1 stop
! B-1 integer
! C-1 scalar
! D-2 constant-expr
! E-2 default selected_int_kind(9)
! ====================

program main
  use iso_fortran_env
  implicit none
  integer(selected_int_kind(9)), parameter :: a = 2 ,b = 3
  integer :: i, r

  do i = 1, 10
    r = i * i
    if (r == 25) then
      stop a + b
    end if
  end do

end program
