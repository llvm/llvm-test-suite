! SPEC: F2008 5.3.16

! ====================
! A-1 module
! B-1 variable
! C-1 automatically save
! ====================

module m
  implicit none
  integer :: tmp ! Implicit save attribute
contains
  subroutine init(i)
    integer,intent(in) :: i
    tmp = i
  end subroutine init

  function func1(a) result(b)
    integer,intent(in) :: a
    integer :: b
    b = a + tmp
    tmp = b
  end function func1
end module m

program main
  use m
  implicit none
  integer :: x

  call init(0)

  x = 1
  write(*,*) func1(x)
  write(*,*) func1(x)
  write(*,*) func1(x)

end program main
