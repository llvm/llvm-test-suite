! SPEC: F2008 R627 R633

module m
  implicit none

  type :: t1
    real :: n1
  end type

  type, extends(t1) :: t2
    real :: n2
  end type

end module m

! ====================
! A-2 derived
! B-2 array
! C-1 mold / C-2 source
! D-2 constant
! E-1 rank same
! F-2 type extension
! G-1 kind same
! ====================
program main
  use m
  implicit none

  class(t1), allocatable :: p(:)
  type(t2) :: a(6)
  type(t2) :: b(3)
  integer :: i

  a%n1 = [1.1,2.2,3.3,4.4,5.5,6.6]
  a%n2 = [7.7,8.8,9.9,12.12,21.21,3.14]

  b%n1 = [1.1,2.2,3.3]
  b%n2 = [4.4,5.5,6.6]

  ! MOLD
  allocate(p(3:5), mold=b)

  select type (p)
  type is (t1)
    write(*,*) "NG1"
  type is (t2)
    do i = lbound(p,1), ubound(p,1)
      p(i)%n1 = a(i)%n1 * 10.0
      p(i)%n2 = a(i)%n2 * 10.0
    end do
    write(*,'(2I3,6F8.2)') lbound(p%n1,1), ubound(p%n1,1), p%n1
    write(*,'(2I3,6F8.2)') lbound(p%n2,1), ubound(p%n2,1), p%n2
  end select

  deallocate(p)

  ! SOURCE
  allocate(p(3:5), source=b)

  select type (p)
  type is (t1)
    write(*,*) "NG2"
  type is (t2)
    write(*,'(2I3,6F8.2)') lbound(p%n1,1), ubound(p%n1,1), p%n1
    write(*,'(2I3,6F8.2)') lbound(p%n2,1), ubound(p%n2,1), p%n2
  end select

  deallocate(p)

end program
