! RUN: %flang %s -o %t && %t | FileCheck %s
! RUN: %gfortran %s -o %t && %t | FileCheck %s

! SPEC: F2008 Masking bits (MASKL,MASKR)

program main
  use iso_fortran_env
  implicit none

  integer(int32) :: i32
  integer(int64) :: i64

  ! ====================
  ! A-1 MASKL / B-1 default / C-1 positive / D-1 none
  ! ====================
  print*, maskl(3)

  ! ====================
  ! A-2 MASKR / B-2 int32 / C-1 positive / D-2 int32
  ! ====================
  i32 = 10
  print*, maskl(i32,int32)

  ! ====================
  ! A-1 MASKL / B-3 int64 / C-1 positive / D-3 int64
  ! ====================
  i64 = 60
  print*, maskl(i64,int64)

  ! ====================
  ! A-1 MASKL / B-3 int64 / C-1 positive / D-2 int32
  ! ====================
  i64 = 60
  print*, maskl(i64,int32)
  
  ! ====================
  ! A-2 MASKR / B-1 default / C-2 zero / D-1 none
  ! ====================
  print*, maskr(0)

end program main

! CHECK:      -536870912
! CHECK-NEXT: -4194304
! CHECK-NEXT: -16
! CHECK-NEXT: -16
! CHECK-NEXT: 0
