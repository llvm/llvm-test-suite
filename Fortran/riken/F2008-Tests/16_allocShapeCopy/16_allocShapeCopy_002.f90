! SPEC: F2008 R627 R633

program main
  implicit none

  call sub1

contains

  ! ====================
  ! A-1 intrinsic
  ! B-2 array
  ! C-1 mold / C-2 source
  ! D-2 constant
  ! E-1 rank same
  ! F-1 type compatible
  ! G-1 kind same
  ! ====================
  subroutine sub1
    real, allocatable :: a(:), b(:)
    real :: x(3)
    integer :: i

    x = [1.1,2.2,3.3]

    allocate(a(1:3), mold=x)
    a = 9.9
    write(*,'(2I3,4F6.2)') lbound(a,1), ubound(a,1), a

    allocate(b(1:3), source=x)
    write(*,'(2I3,3F6.2)') lbound(b,1), ubound(b,1), b

  end subroutine

end program
