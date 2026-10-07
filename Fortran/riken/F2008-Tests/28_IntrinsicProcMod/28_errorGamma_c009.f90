! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: F2008 Error and gamma (HYPOT)
  
program main
  use iso_fortran_env
  implicit none

  real(real32) :: x32
  real(real64) :: y64

  ! ====================
  ! A-5
  ! B-3
  ! C-1
  ! ====================
  x32 = 3.0
  y64 = 4.0
  print "(a, f10.5)", "real32: ", hypot(x32, y64)

end program main

! FLANG: 28_errorGamma_c009.f90:20:
! FLANG-SAME: error:

! GFORT: 28_errorGamma_c009.f90:20:
! GFORT-NOT: .f90
! GFORT: Error:
