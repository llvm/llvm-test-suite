! SPEC: Verify removal of F2003 C1279

! ====================
! A-1 user function
! B-1/2/3/4 dummy args
! ====================

program main
  implicit none

  integer :: x
  integer :: r
  real :: z

  x = 8
  r = func(x)
  print *, r

  x = 5
  r = func1(x)
  print *, r

  x = -5
  r = func2(x)
  print *, r

  x = 5
  r = func3(x)
  print *, r

contains

  elemental function func(n) result(r)
    integer,intent(in) :: n
    integer :: r
    r = n * 2
  end function func

  elemental function func1(n) result(r)
    integer,intent(in) :: n
    integer,dimension(n) :: b
    integer :: r
    r = n * 2
  end function func1

  elemental function func2(n) result(r)
    integer,intent(in) :: n
    integer :: r
    r = abs(n)
  end function func2

  elemental function func3(n) result(r)
    integer,intent(in) :: n
    type :: zzz
       character(5) :: b
    end type zzz
    character(len=n) :: c
    type(zzz) :: a
    integer :: r
    r = n * 2
  end function func3
  
end program
