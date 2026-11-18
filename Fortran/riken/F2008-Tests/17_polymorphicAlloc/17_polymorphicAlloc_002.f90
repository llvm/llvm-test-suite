! SPEC: F2008 R627 R633

module m1
  type :: t1
    integer :: n1
  end type t1
end module m1

! ====================
! A-2 derived
! B-1 scalar
! C-1 source
! F-1 same type
! ====================
program main
  use m1
  implicit none
  class(t1), allocatable :: p  ! polymorphic
  type(t1) :: a

  a%n1 = 10
  allocate(p, source=a)
  write(*,*) p%n1

end program
