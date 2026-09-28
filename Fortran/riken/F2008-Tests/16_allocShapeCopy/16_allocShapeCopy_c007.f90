! RUN: not %flang %s 2>&1 | FileCheck %s --check-prefix=FLANG
! RUN: not gfortran -std=f2008 %s 2>&1 | FileCheck %s --check-prefix=GFORT

! SPEC: F2008 R627 R633

program main
  implicit none

  call sub1

contains

  ! ====================
  ! A-1 intrinsic
  ! B-2 array
  ! C-1 mold
  ! D-4 constant diff
  ! E-1 rank same
  ! F-1 type compatible
  ! G-1 kind same
  ! ====================
  subroutine sub1
    real, allocatable :: a(:)
    real :: x(4)
    integer :: i

    x = [1.1,2.2,3.3,4.4]

    allocate(a(1:3), mold=x)
    a = 9.9
    write(*,'(2I3,4F6.2)') lbound(a,1), ubound(a,1), a
  end subroutine

end program

! GFORT: 16_allocShapeCopy_c007.f90:29
! GFORT-NOT: .f90
! GFORT: Error:

! FLANG: 16_allocShapeCopy_c007.f90:29
! FLANG-SAME: error:
