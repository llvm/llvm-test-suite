! RUN: %flang %s -o %t 
! RUN: not --crash %t 2>&1 | FileCheck %s
! RUN: %gfortran %s -o %t 
! RUN: not --crash %t 2>&1 | FileCheck %s

! SPEC: F2008 13.7.160 STORAGE SIZE (A [, KIND])

! ====================
! 
! ====================
program main
  use iso_fortran_env
  implicit none

  type :: base(len)
     integer,len :: len
     character(len) :: str
  end type base


  type(base(:)),pointer :: a
  print*, storage_size(a)

end program main

! CHECK: Segmentation fault
