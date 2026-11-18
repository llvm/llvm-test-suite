! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -std=f2008 -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: F2008 13.7.22 BESSEL J0 (X)
!             13.7.23 BESSEL J1 (X)
!             13.7.24 BESSEL JN (N, X) or BESSEL JN (N1, N2, X)
!             13.7.25 BESSEL Y0 (X)
!             13.7.26 BESSEL Y1 (X)
!             13.7.27 BESSEL YN (N, X) or BESSEL YN (N1, N2, X)
program main
  use iso_fortran_env
  implicit none
  real(real32) :: r4
  r4 = -1.1

  ! ====================
  ! A-3 : bessel_jn / B-1 : int / D-2 : real / E-3 : negative / G-3 : negative
  ! ====================
  print*, bessel_jn(-1,r4)
end program main

! GFORT: 28_bessel_c003.f90:19:
! GFORT-NOT: .f90
! GFORT: Error:

! FLANG: 28_bessel_c003.f90:19:
! FLANG-SAME: error:
