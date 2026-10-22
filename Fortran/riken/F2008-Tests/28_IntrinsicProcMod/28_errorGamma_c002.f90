! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: F2008 Error and gamma (ERFC)
  
program main
  use iso_fortran_env
  implicit none

  integer(int32) :: x32

  ! ====================
  ! A-2
  ! B-3
  ! ====================
  x32 = 1
  print "(a, f10.5)", "int32: ", erfc(x32)

end program main

! FLANG: 28_errorGamma_c002.f90:17:
! FLANG-SAME: error:

! GFORT: 28_errorGamma_c002.f90:17:
! GFORT-NOT: .f90
! GFORT: Error:
