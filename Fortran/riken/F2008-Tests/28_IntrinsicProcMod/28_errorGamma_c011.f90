! RUN: %flang -c %s -o /dev/null 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: F2008 Error and gamma (LOG_GAMMA)
  
program main
  use iso_fortran_env
  implicit none

  ! ====================
  ! A-6
  ! B-4
  ! ====================
  print "(a, f10.5)", "int32: ", log_gamma(-3.0)

end program main

! FLANG: 28_errorGamma_c011.f90:14:
! FLANG-SAME: warning:

! GFORT: 28_errorGamma_c011.f90:14:
! GFORT-NOT: .f90
! GFORT: Error:
