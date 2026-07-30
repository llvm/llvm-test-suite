! SPEC: F2008 R627 R633

module m
  type :: t1
    integer :: n1
  end type t1

  type, extends(t1) :: t2
    integer :: n2
  end type t2
end module m

! ====================
! A-2 derived
! B-1 scalar
! C-2 source (reallocate)
! F-2 type extension
! ====================
program main
  use m
  implicit none
  class(t1), allocatable :: p  ! polymorphic
  type(t1) :: a
  type(t2) :: b

  a%n1 = 1
  allocate(p, source=a)

  b%n1 = 100
  b%n2 = 200

  ! p was allocated as t1;
  ! assigning b (type t2) triggers automatic reallocation
  p = b  ! reallocate

  select type (p)
  type is (t2)
    write(*,*) "t2 =", p%n1, p%n2
  end select
end program
