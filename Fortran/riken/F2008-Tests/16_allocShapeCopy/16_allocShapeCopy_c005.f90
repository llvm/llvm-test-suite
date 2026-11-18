! RUN: not %flang %s 2>&1 | FileCheck %s --check-prefix=FLANG
! RUN: not gfortran -std=f2008 %s 2>&1 | FileCheck %s --check-prefix=GFORT

! SPEC: F2008 C638

program main
  implicit none
  integer, allocatable :: a(:)
  real :: x(3) = [10.1, 20.2, 30.3]

  ! ====================
  ! A-1 intrinsic
  ! B-2 array
  ! C-1 mold
  ! D-1 omitted
  ! E-2 rank diff
  ! F-1 type compatible
  ! G-1 kind same
  ! ====================
  allocate (a, mold = x)
  a = 9.9
  write(*,'(3(I0,1X))') lbound(a), ubound(a), size(a)
  write(*,'(3(I0,1X))') a
end program

! GFORT: 16_allocShapeCopy_c005.f90:20
! GFORT-NOT: .f90
! GFORT: Error:

! FLANG: 16_allocShapeCopy_c005.f90:20
! FLANG-SAME: error:
