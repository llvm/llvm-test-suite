! RUN: not %flang %s 2>&1 | FileCheck %s --check-prefix=FLANG
! RUN: not gfortran -std=f2008 %s 2>&1 | FileCheck %s --check-prefix=GFORT

! SPEC: F2008 C637

program main
  implicit none
  integer, allocatable :: a(:)
  integer :: x(3) = [10, 20, 30]

  ! ====================
  ! A-1 intrinsic
  ! B-2 array
  ! C-7 C637
  ! D-1 omitted
  ! E-1 rank same
  ! F-1 type compatible
  ! G-1 kind same
  ! ====================
  allocate (integer :: a(3) , mold = x)
  a = 9.9
  write(*,'(3(I0,1X))') lbound(a), ubound(a), size(a)
  write(*,'(3(I0,1X))') a
end program

! GFORT: 16_allocShapeCopy_c003.f90:20
! GFORT-NOT: .f90
! GFORT: Error:

! FLANG: 16_allocShapeCopy_c003.f90:20
! FLANG-SAME: error:
