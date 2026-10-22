! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: F2008:13.7.61 FINDLOC

program main
  implicit none

  type :: p
    integer :: x
  end type

  type, extends(p) :: c
    integer :: y
  end type

  type(c) :: a(3)
  type(c) :: v
  integer :: pos(1)
  integer :: i

  do i=1,3
    a(i)%x = i
    a(i)%y = i * 10
  end do

  v%x = 2
  v%y = 20

  ! ====================
  ! A-6 type
  ! ====================
  pos = findloc(a, v)
  print *, pos

end program

! GFORT: 28_findloc_c001.f90:33:
! GFORT-NOT: .f90
! GFORT: Error:

! FLANG: 28_findloc_c001.f90:33:
! FLANG-SAME: error:
