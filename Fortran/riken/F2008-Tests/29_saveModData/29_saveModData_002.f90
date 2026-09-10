! SPEC: F2008 5.3.16

! ====================
! A-1 module
! B-2 common
! C-1 automatically save
! ====================

module m
  common /dat/ com1, com2  ! Implicit save attribute
contains
  subroutine init(i)
    real,intent(in) :: i
    common /dat/ com1, com2
    com1 = i
    com2 = i
  end subroutine init

  function func1(a) result(b)
    real, intent(in) :: a
    real b
    common /dat/ com1, com2

    com1 = com1 + a
    com2 = com2 + a + a
    b = com1 + com2
  end function func1
end module m

program main
  use m
  real a, b

  call init(0.0)

  a = 10.0
  com1 = 1.0
  com2 = 2.0

  b = func1(a)
  write (*, '(3f6.2)'), com1, com2, b

  b = func1(a)
  write (*, '(3f6.2)'), com1, com2, b

  b = func1(a)
  write (*, '(3f6.2)'), com1, com2, b

end program main
