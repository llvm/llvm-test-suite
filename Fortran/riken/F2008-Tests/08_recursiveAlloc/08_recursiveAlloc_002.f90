! SPEC: F2008 R437,C440

program main
  implicit none

  type :: A
    type(B), allocatable :: bcomp
  end type A

  type :: B
     integer :: data
  end type B

  type(A)    :: a1

  allocate(a1%bcomp)
  a1%bcomp%data = 20

  print *, a1%bcomp%data

end program
