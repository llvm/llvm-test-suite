! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s
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
  integer(int32) :: i4
  real(real32) :: r4
  i4 = 1
  r4 = 1.0

  ! ====================
  ! A-6 : bessel_yn / B-1 : int / C-2 : real / D-2 : real / E-1 : positive / F-1 : positive / G-1 : positive
  ! ====================
  print*, bessel_yn(i4,r4,1.1)
end program main

! GFORT: 28_bessel_c002.f90:21:
! GFORT-NOT: .f90
! GFORT: Error:

! FLANG: 28_bessel_c002.f90:21:
! FLANG-SAME: error:
