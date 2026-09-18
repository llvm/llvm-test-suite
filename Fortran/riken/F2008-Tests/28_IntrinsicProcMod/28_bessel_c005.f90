! RUN: %flang -c %s -o /dev/null 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: F2008 13.7.22 BESSEL J0 (X)
!             13.7.23 BESSEL J1 (X)
!             13.7.24 BESSEL JN (N, X) or BESSEL JN (N1, N2, X)
!             13.7.25 BESSEL Y0 (X)
!             13.7.26 BESSEL Y1 (X)
!             13.7.27 BESSEL YN (N, X) or BESSEL YN (N1, N2, X)
program main
  use iso_fortran_env
  implicit none

  ! ====================
  ! A-5 : bessel_y1 / D-2 : real / G-2 : zero
  ! ====================
  print*, bessel_y1(0.0)
end program main

! GFORT: 28_bessel_c005.f90:17:
! GFORT-NOT: .f90
! GFORT: Error:

! FLANG: 28_bessel_c005.f90:17:
! FLANG-SAME: warning:
