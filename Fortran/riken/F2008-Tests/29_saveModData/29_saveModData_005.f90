! SPEC: F2008 5.3.16

! ====================
! A-2 submodule
! B-2 common
! C-1 automatically save
! ====================

module m
  implicit none
  interface
    module subroutine init(a)
      real, intent(in) :: a
    end subroutine init

    module function func1(a) result(b)
      real, intent(in) :: a
      real :: b
    end function func1
  end interface
end module m

submodule (m) smod
  common /dat/ com1, com2  ! Implicit save attribute
contains
  module procedure init
    com1 = a + 1.0
    com2 = a + 2.0
  end procedure init

  module procedure func1
    com1 = com1 + a
    com2 = com2 + a + a
    b = com1 + com2
  end procedure func1
end submodule smod

program main
  use m
  implicit none
  real :: x, y
  
  call init(0.0)

  x = 10.0

  write(*, '(f6.2)') func1(x)
  write(*, '(f6.2)') func1(x)
  write(*, '(f6.2)') func1(x)

end program main
