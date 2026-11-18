! SPEC: F2008 R437,C440

program main
  implicit none

  type :: X
    type(Y), allocatable :: ycomp
  end type X

  type :: Y
    type(X), allocatable :: xcomp
    integer :: yval
  end type Y

  type(X)    :: x1

  allocate(x1%ycomp)
  x1%ycomp%yval = 30

  allocate(x1%ycomp%xcomp)

  allocate(x1%ycomp%xcomp%ycomp)
  x1%ycomp%xcomp%ycomp%yval = 40

  print *, x1%ycomp%yval, x1%ycomp%xcomp%ycomp%yval

end program
