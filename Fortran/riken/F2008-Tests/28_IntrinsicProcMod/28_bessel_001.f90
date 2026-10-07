! RUN: %flang %s -o %t && %t | FileCheck %s
! RUN: %gfortran %s -o %t && %t | FileCheck %s

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
  data r4/1.1_4/
  real(real64) :: r8
  data r8/1.2_8/
  integer(int32) :: i4
  integer(int64) :: i8
  i4 = 1
  i8 = 2

  ! ====================
  ! A-1 : bessel_j0 / D-2 : real / G-1 : positive
  ! ====================
  write(*,'(F7.5)') bessel_j0(1.0)

  ! ====================
  ! A-1 : bessel_j1 / D-2 : real / G-1 : zero
  ! ====================
  write(*,'(F3.1)') bessel_j1(0.0)

  ! ====================
  ! A-4 : bessel_y0 / D-2 : real / G-1 : positive
  ! ====================
  write(*,'(F9.7)') bessel_y0(r4)

  ! ====================
  ! A-5 : bessel_y1 / D-2 : real / G-2 : positive
  ! ====================
  write(*,'(F19.16)') bessel_y1(r8)
  
  ! ====================
  ! A-3 : bessel_jn / B-1 : int / D-2 : real / E-1 : positive / G-1 : positive
  ! ====================
  write(*,'(F18.16)') bessel_jn(0,r8)

  ! ====================
  ! A-3 : bessel_jn / B-1 : int / C-1 : int / D-2 : real / E-1 : positive / F-1 : positive / G-3 : negative
  ! ====================
  write(*,'(F11.8,F10.7)') bessel_jn(i4,i8,-1.0)

  ! ====================
  ! A-6 : bessel_y / B-1 : int / C-1 : int / D-2 : real / E-1 : positive / F-1 : positive / G-1 : positive
  ! ====================
  write(*,'(F19.16,F20.16)') bessel_yn(i4,i8,r8)
end program main

! CHECK:      0.76520
! CHECK-NEXT:  0.0
! CHECK-NEXT:  0.1621632
! CHECK-NEXT:  -0.6211363797488479
! CHECK-NEXT:  0.6711327442643628
! CHECK-NEXT:  -0.44005057 0.1149035
! CHECK-NEXT:  -0.6211363797488479 -1.2633108028086102
