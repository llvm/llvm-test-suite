! RUN: not %flang %s 2>&1 | FileCheck %s --check-prefix=FLANG
! RUN: not gfortran -std=f2008 %s 2>&1 | FileCheck %s --check-prefix=GFORT

! SPEC: F2008 C636

program main
  implicit none
  integer, allocatable :: a(:)
  integer :: x(3) = [10, 20, 30]
  integer :: y(3) = [40, 50, 60]

  ! ====================
  ! A-1 intrinsic
  ! B-2 array
  ! C-6 C636
  ! D-1 omitted
  ! E-1 rank same
  ! F-1 type compatible
  ! G-1 kind same
  ! ====================
  allocate (a, mold = x, mold = y)
  a = 9.9
  write(*,'(3(I0,1X))') lbound(a), ubound(a), size(a)
  write(*,'(3(I0,1X))') a
end program

! GFORT: 16_allocShapeCopy_c002.f90:21
! GFORT-NOT: .f90
! GFORT: Error:

! FLANG: 16_allocShapeCopy_c002.f90:21
! FLANG-SAME: error:
