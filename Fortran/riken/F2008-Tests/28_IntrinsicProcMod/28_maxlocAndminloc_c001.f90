! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: F2008 13.7.108 MAXLOC (ARRAY, DIM [, MASK, KIND, BACK]) or
!                      MAXLOC (ARRAY [, MASK, KIND, BACK])
!             13.7.114 MINLOC (ARRAY, DIM [, MASK, KIND, BACK]) or
!                      MINLOC (ARRAY [, MASK, KIND, BACK])

program main
  use iso_fortran_env
  implicit none

  integer(int32),dimension(10) :: a
  data a/10*10/

  ! ====================
  ! A-1 maxloc / B-2 int
  ! ====================
  print*, maxloc(a,back=1)

end program main

! GFORT: 28_maxlocAndminloc_c001.f90:19
! GFORT-NOT: .f90
! GFORT: Error:

! FLANG: 28_maxlocAndminloc_c001.f90:19
! FLANG-SAME: error:
