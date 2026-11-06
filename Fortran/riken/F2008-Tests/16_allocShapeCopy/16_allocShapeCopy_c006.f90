! RUN: not %flang %s 2>&1 | FileCheck %s --check-prefix=FLANG
! RUN: not gfortran -std=f2008 %s 2>&1 | FileCheck %s --check-prefix=GFORT

! SPEC: F2008 C639

program main
  use iso_fortran_env
  implicit none
  integer(int32), allocatable :: a(:)
  integer(int64) :: x(3) = [10, 20, 30]

  ! ====================
  ! A-1 intrinsic
  ! B-2 array
  ! C-1 mold
  ! D-1 omitted
  ! E-1 rank same
  ! F-1 type compatible
  ! G-2 kind diff
  ! ====================
  allocate (a, mold = x)
  a = 9.9
  write(*,'(3(I0,1X))') lbound(a), ubound(a), size(a)
  write(*,'(3(I0,1X))') a
end program

! GFORT: 16_allocShapeCopy_c006.f90:21
! GFORT-NOT: .f90
! GFORT: Error:

! FLANG: 16_allocShapeCopy_c006.f90:21
! FLANG-SAME: error:
