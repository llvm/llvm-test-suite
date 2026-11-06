! SPEC: F2008 5.3.16

! ====================
! A-2 submodule
! B-1 variable
! C-1 automatically save
! ====================

module m
  implicit none
  interface
    module subroutine init(a)
      integer, intent(in) :: a
    end subroutine init

    module function func1(a) result(b)
      integer, intent(in) :: a
      integer :: b
    end function func1
  end interface
end module m

submodule (m) smod
  implicit none
  integer :: tmp   ! Implicit save attribute
contains
  module procedure init
    tmp = a
  end procedure init

  module procedure func1
    b = a + tmp
    tmp = b
  end procedure func1
end submodule smod

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
