! RUN: %flang -c %s -o /dev/null 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: F2008 Error and gamma (GAMMA)
  
program main
  use iso_fortran_env
  implicit none

  ! ====================
  ! A-4
  ! B-5
  ! ====================
  print "(a, f10.5)", "int32: ", gamma(0.0)

end program main

! FLANG: 28_errorGamma_c006.f90:14:
! FLANG-SAME: warning:

! GFORT: 28_errorGamma_c006.f90:14:
! GFORT-NOT: .f90
! GFORT: Error:
