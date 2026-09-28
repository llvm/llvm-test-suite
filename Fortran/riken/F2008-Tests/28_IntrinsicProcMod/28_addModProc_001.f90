! RUN: %flang %s -o %t && %t | FileCheck %s
! RUN: %gfortran %s -o %t && %t | FileCheck %s

! SPEC: F2008:13.8.2.6 COMPILER OPTIONS 13.8.2.7 COMPILER VERSION 

program main
  use iso_fortran_env
  implicit none

  !========================
  ! A-1 compiler_options
  ! B-1 use module
  !========================
  print *, "OPTIONS:", compiler_options()

  !========================
  ! A-2 compiler_version
  ! B-1 use module
  !========================
  print *, "VERSION:", compiler_version()

end program

! CHECK: OPTIONS:
! CHECK: VERSION:
