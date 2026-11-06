! SPEC: F2008 R602 C602

module mod
  type :: t
     real :: v
  end type

  type(t), target :: obj1, obj2

contains

  function g(flag) result(res)
    real, intent(in) :: flag
    type(t), pointer :: res

    if (flag > 0.0) then
       res => obj1
    else
       res => obj2
    end if
  end function g

end module mod

program main
  use mod
  real :: a
  type(t) :: obj

  a = 1.0

  obj1%v = 5.0
  obj2%v = 9.0

  write(*,'(F5.2)') obj1%v

  obj%v = 10.0
  g(a) = obj

  write(*,'(F5.2)') obj1%v

end program main
