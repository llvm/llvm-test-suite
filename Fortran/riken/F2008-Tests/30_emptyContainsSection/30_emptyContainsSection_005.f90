! SPEC: F2008 Introduction, Table 2.2

! ====================
! A-1 empty contains
! B-5 module subprogram
! ====================
module mod
  implicit none

contains
  function func1(a, b) result(res)
    integer, intent(in) :: a, b
    integer :: res

    res = a / b

! Empty contains section
  contains

  end function func1

end module mod

program main
    use mod
    implicit none
    integer :: x = 100
    integer :: y = 5
    integer :: res

    res = func1(x, y)

    print *, 'res =', res
    print *, "Done!"

end program main
