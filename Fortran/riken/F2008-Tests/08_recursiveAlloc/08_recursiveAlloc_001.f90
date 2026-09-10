! SPEC: F2008 R437,C440

program main
  implicit none

  type :: Node
    integer :: value
    type(Node), allocatable :: next
  end type Node

  type(Node) :: n1

  allocate(n1%next)
  n1%next%value = 10

  print *, n1%next%value

end program
