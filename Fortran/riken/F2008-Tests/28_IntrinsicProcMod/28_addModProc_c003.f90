! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: F2008:15.2.3.7 C SIZEOF

program main
  use iso_fortran_env, only: real32
  implicit none
  real(real32),dimension(10) :: a

  !========================
  ! A-3 x_sizeof(x)
  ! B-2 without module
  ! C-1 not assumed-size array 
  ! D-1 interoperable data
  !========================
  print*, c_sizeof(a)
  
end program

! GFORT: 28_addModProc_c003.f90:17:
! GFORT-NOT: .f90
! GFORT: Error:

! FLANG: 28_addModProc_c003.f90:17:
! FLANG-SAME: error:
