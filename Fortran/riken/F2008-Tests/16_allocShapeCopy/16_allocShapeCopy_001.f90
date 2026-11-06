! SPEC: F2008 R627 R633

program main
  implicit none

  call sub1

contains

  ! ====================
  ! A-1 intrinsic
  ! B-1 scalar
  ! C-1 mold / C-2 source
  ! D-1 omitted
  ! E-1 rank same
  ! F-1 type compatible
  ! G-1 kind same
  ! ====================
  subroutine sub1
    integer, allocatable :: a, b
    integer :: x

    x = 10 

    allocate(a, mold=x)
    a = 20
    write(*,*) a

    allocate(b, source=x)
    write(*,*) b

  end subroutine

end program
