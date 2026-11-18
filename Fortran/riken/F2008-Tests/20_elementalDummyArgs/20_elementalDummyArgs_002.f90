! SPEC: Verify removal of F2003 C1279

! ====================
! A-2 user subroutine
! B-1/2/3/4 dummy args
! ====================

program main
  implicit none

  integer :: x
  integer :: r
  real :: z

  x = 8
  call func(r,x)
  print*, r

  x = 5
  call func1(r,x)
  print*, r
  
  x = -5
  call func2(r,x)
  print*, r
  
  x = 5
  call func3(r,x)
  print*, r
  
contains

  elemental subroutine func(r,n)
    integer,intent(out) :: r
    integer,intent(in) :: n
    r = n * 2
  end subroutine func

  elemental subroutine func1(r,n)
    integer,intent(out) :: r
    integer,intent(in) :: n
    integer,dimension(n) :: b
    r = n * 2
  end subroutine func1

  elemental subroutine func2(r,n)
    integer,intent(out) :: r
    integer,intent(in) :: n
    r = abs(n)
  end subroutine func2

  elemental subroutine func3(r,n)
    integer,intent(out) :: r
    integer,intent(in) :: n
    type :: zzz
       character(5) :: b
    end type zzz
    character(len=n) :: c
    type(zzz) :: a
    r = n * 2
  end subroutine func3
  
end program
