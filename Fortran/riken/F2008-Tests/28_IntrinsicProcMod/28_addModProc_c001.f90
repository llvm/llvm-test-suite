! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: F2008:15.2.3.7 C SIZEOF

program main
  implicit none

  !========================
  ! A-1 compiler_options
  ! B-2 without module
  !========================
  print *, "OPTIONS:", compiler_options()

end program

! GFORT: 28_addModProc_c001.f90:13:
! GFORT-NOT: .f90
! GFORT: Error:

! FLANG: 28_addModProc_c001.f90:13:
! FLANG-SAME: error:
