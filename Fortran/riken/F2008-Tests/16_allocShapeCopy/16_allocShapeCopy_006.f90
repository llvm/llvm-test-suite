! SPEC: F2008 R627 R633

module m
  use iso_fortran_env
  implicit none

  type :: t1
    integer(int32) :: n1
  end type

  type, extends(t1) :: t2
    integer(int32) :: n2
  end type

end module m

! ====================
! A-2 derived
! B-2 array
! C-1 mold / C-2 source
! D-3 object
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

  a%n1 = [1,2,3,4,5,6]
  a%n2 = [7,8,9,10,11,12]

  b%n1 = [21,22,23]
  b%n2 = [24,25,26]

  ! MOLD
  allocate(p(lbound(b,1):ubound(b,1)), mold=b)

  select type (p)
  type is (t1)
    write(*,*) "NG1"
  type is (t2)
    do i = lbound(p,1), ubound(p,1)
      p(i)%n1 = a(i)%n1 * 10
      p(i)%n2 = a(i)%n2 * 10
    end do
    write(*,*) lbound(p%n1,1), ubound(p%n1,1), p%n1
    write(*,*) lbound(p%n2,1), ubound(p%n2,1), p%n2
  end select

  deallocate(p)

  ! SOURCE
  allocate(p(lbound(b,1):ubound(b,1)), source=b)

  select type (p)
  type is (t1)
    write(*,*) "NG2"
  type is (t2)
    write(*,*) lbound(p%n1,1), ubound(p%n1,1), p%n1
    write(*,*) lbound(p%n2,1), ubound(p%n2,1), p%n2
  end select

  deallocate(p)

end program
