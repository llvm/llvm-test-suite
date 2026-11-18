! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: 13.7.123 NORM2 (X [, DIM])

program main
  use iso_fortran_env
  implicit none

  real(real32),dimension(2) :: a
  data a/1.0,2.0/

  call sub()
  
  contains

  subroutine sub(a)
  use iso_fortran_env
  implicit none
  real(real32),intent(in),optional,dimension(2) :: a

  if (present(a)) then
     print*, norm2(a)
  end if
     
  end subroutine sub
end program main

! GFORT: 28_norm_c006.f90:23:
! GFORT-NOT: .f90
! GFORT: Error:

! FLANG: 28_norm_c006.f90:23:
! FLANG-SAME: error:
