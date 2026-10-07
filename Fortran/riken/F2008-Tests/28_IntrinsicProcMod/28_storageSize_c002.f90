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

  type base
     integer :: i
  end type base

  class(base), pointer :: p

  print*, storage_size(p)

end program main

! CHECK: Segmentation fault
