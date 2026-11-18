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
! C-1 mold
! F-2 type extension
! ====================
program main
  use m
  implicit none
  class(t1), allocatable :: p  ! polymorphic
  type(t2) :: a

  a%n1 = 10
  a%n2 = 20

  allocate(p, mold=a)

  select type (p)
  type is (t1)
    write(*,*) "NG1"
  type is (t2)
    p%n1 = 30
    p%n2 = 40
    write(*,*) "t1,t2 =", p%n1, p%n2
  end select

end program
