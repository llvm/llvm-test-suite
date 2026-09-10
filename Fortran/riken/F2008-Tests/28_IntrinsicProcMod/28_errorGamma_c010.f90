! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: F2008 Error and gamma (LOG_GAMMA)
  
program main
  use iso_fortran_env
  implicit none

  integer(int32) :: x32

  ! ====================
  ! A-6
  ! B-3
  ! ====================
  x32 = 3
  print "(a, f10.5)", "int32: ", log_gamma(x32)

end program main

! FLANG: 28_errorGamma_c010.f90:17:
! FLANG-SAME: error:

! GFORT: 28_errorGamma_c010.f90:17:
! GFORT-NOT: .f90
! GFORT: Error:
