! RUN: %flang %s -o %t && %t | FileCheck %s
! RUN: ls test-011.txt
! RUN: rm test-*.txt
! RUN: %gfortran %s -o %t && %t | FileCheck %s
! RUN: ls test-011.txt
! RUN: rm test-*.txt

! SPEC: F2008 EXECUTE_COMMAND_LINE

program main
  implicit none
  integer :: estat
  integer :: cstat
  character :: cmsg

! ====================
! A-1
! B-3
! C-2
! D-2
! E-1
! ====================
  estat = 0
  cstat = 0
  call execute_command_line("ls > test-011.txt", .false., estat, cstat)
  print *, '[test-011]'
  print *, 'EXITSTAT: ', estat
  print *, 'CMDSTAT: ', cstat


end program main

! CHECK:  [test-011]
! CHECK-NEXT:  EXITSTAT:            0
! CHECK-NEXT:  CMDSTAT:            0
