! RUN: not %flang %s 2>&1 | FileCheck %s --check-prefix=FLANG
! RUN: not gfortran -std=f2008 %s 2>&1 | FileCheck %s --check-prefix=GFORT

! SPEC: F2008 R627

program main
  implicit none
  integer(int64), allocatable :: a(:)
  integer(int64) :: x(3) = [10, 20, 30]
  integer(int64) :: y(3) = [40, 50, 60]

  ! ====================
  ! A-1 intrinsic
  ! B-2 array
  ! C-5 mold + source
  ! D-1 omitted
  ! E-1 rank same
  ! F-1 type compatible
  ! G-1 kind same
  ! ====================
  allocate (a, source = x, mold = y)
  a = 9.9
  write(*,'(3(I0,1X))') lbound(a), ubound(a), size(a)
  write(*,'(3(I0,1X))') a
end program

! GFORT: 16_allocShapeCopy_c001.f90:21
! GFORT-NOT: .f90
! GFORT: Error:

! FLANG: 16_allocShapeCopy_c001.f90:21
! FLANG-SAME: error:
