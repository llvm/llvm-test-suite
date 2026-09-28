! RUN: %flang %s -o %t && %t | FileCheck %s
! RUN: ls test-001.txt
! RUN: ls test-002.txt
! RUN: ls test-003.txt
! RUN: ls test-004.txt
! RUN: ls test-005.txt
! RUN: rm test-*.txt
! RUN: %gfortran %s -o %t && %t | FileCheck %s
! RUN: ls test-001.txt
! RUN: ls test-002.txt
! RUN: ls test-003.txt
! RUN: ls test-004.txt
! RUN: ls test-005.txt
! RUN: rm test-*.txt

! SPEC: F2008 EXECUTE_COMMAND_LINE

program main
  implicit none
  integer :: estat
  integer :: cstat
  character :: cmsg

! ====================
! A-1
! B-1
! C-1
! D-1
! E-1
! ====================
  call execute_command_line("ls > test-001.txt")
  print *, '[test-001]'

! ====================
! A-1
! B-2
! C-2
! D-2
! E-2
! ====================
  estat = 0
  cstat = 0
  cmsg = '-'
  call execute_command_line("ls > test-002.txt", .true., estat, cstat, cmsg)
  print *, '[test-002]'
  print *, 'EXITSTAT: ', estat
  print *, 'CMDSTAT: ', cstat
  print *, 'CMDMSG: ', cmsg

! ====================
! A-1
! B-2
! C-2
! D-1
! E-2
! ====================
  estat = 0
  cmsg = '-'
  call execute_command_line("ls > test-003.txt", .true., estat, cmdmsg=cmsg)
  print *, '[test-003]'
  print *, 'EXITSTAT: ', estat
  print *, 'CMDMSG: ', cmsg

! ====================
! A-1
! B-2
! C-1
! D-2
! E-2
! ====================
  cstat = 0
  cmsg = '-'
  call execute_command_line("ls > test-004.txt", .true., cmdstat=cstat, cmdmsg=cmsg)
  print *, '[test-004]'
  print *, 'CMDSTAT: ', cstat
  print *, 'CMDMSG: ', cmsg

! ====================
! A-1
! B-1
! C-2
! D-2
! E-2
! ====================
  estat = 0
  cstat = 0
  cmsg = '-'
  call execute_command_line("ls > test-005.txt", exitstat=estat, cmdstat=cstat, cmdmsg=cmsg)
  print *, '[test-005]'
  print *, 'EXITSTAT: ', estat
  print *, 'CMDSTAT: ', cstat
  print *, 'CMDMSG: ', cmsg

end program main

! CHECK:  [test-001]
! CHECK-NEXT:  [test-002]
! CHECK-NEXT:  EXITSTAT:            0
! CHECK-NEXT:  CMDSTAT:            0
! CHECK-NEXT:  CMDMSG: -
! CHECK-NEXT:  [test-003]
! CHECK-NEXT:  EXITSTAT:            0
! CHECK-NEXT:  CMDMSG: -
! CHECK-NEXT:  [test-004]
! CHECK-NEXT:  CMDSTAT:            0
! CHECK-NEXT:  CMDMSG: -
! CHECK-NEXT:  [test-005]
! CHECK-NEXT:  EXITSTAT:            0
! CHECK-NEXT:  CMDSTAT:            0
! CHECK-NEXT:  CMDMSG: -
