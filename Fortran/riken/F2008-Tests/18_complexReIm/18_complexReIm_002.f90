! SPEC: F2008 R615

! ====================
! A-1/2 %re,%im
! B-1 complex
! C-1/2 def,ref
! D-2 struct
! ====================
program main
  implicit none

  type :: base
    complex :: z
  end type

  type, extends(base) :: ext
    integer :: x
  end type

  type(ext) :: a(3)
  
  integer :: i

  do i=1,3
    ! def
    a(i)%z%re = 1.25 * i
    a(i)%z%im = -1.25 * i
    ! ref
    write(*,'("(",F0.3,",",F0.3,")")') a(i)%z%re, a(i)%z%im
  end do

end program
