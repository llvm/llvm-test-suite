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
! B-2 array(2D)
! C-2 source
! F-2 type extension
! ====================
program main
  use m
  implicit none
  class(t1), allocatable :: p(:,:) ! polymorphic
  type(t2) :: a(2,2)
  integer :: i, j

  do i = 1, 2
    do j = 1, 2
      a(i,j)%n1 = i * 10 + j
      a(i,j)%n2 = i * 100 + j
    end do
  end do

  allocate(p, source=a)

  select type (p)
  type is (t1)
    write(*,*) "NG1"
  type is (t2)
    do i = 1, 2
      do j = 1, 2
        write(*,*) p(i,j)%n1, p(i,j)%n2
      end do
    end do
  end select

end program
