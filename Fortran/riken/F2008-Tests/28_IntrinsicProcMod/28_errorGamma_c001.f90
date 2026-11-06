! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: F2008 Error and gamma (ERF)
  
program main
  use iso_fortran_env
  implicit none

  integer(int32) :: x32

  ! ====================
  ! A-1
  ! B-3
  ! ====================
  x32 = 1
  print "(a, f10.5)", "int32: ", erf(x32)

end program main

! FLANG: 28_errorGamma_c001.f90:17:
! FLANG-SAME: error:

! GFORT: 28_errorGamma_c001.f90:17:
! GFORT-NOT: .f90
! GFORT: Error:
