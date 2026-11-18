! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: F2008 Error and gamma (HYPOT)
  
program main
  use iso_fortran_env
  implicit none

  real(real32) :: x32
  integer(int32) :: y32

  ! ====================
  ! A-5
  ! B-3
  ! C-1
  ! ====================
  x32 = 3.0
  y32 = 4
  print "(a, f10.5)", "real32: ", hypot(x32, y32)

end program main

! FLANG: 28_errorGamma_c008.f90:20:
! FLANG-SAME: error:

! GFORT: 28_errorGamma_c008.f90:20:
! GFORT-NOT: .f90
! GFORT: Error:
