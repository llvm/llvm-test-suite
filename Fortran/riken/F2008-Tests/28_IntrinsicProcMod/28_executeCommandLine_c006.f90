! RUN: %flang %s -o %t && %t | FileCheck %s
! RUN: %gfortran %s -o %t && %t | FileCheck %s

! SPEC: F2008 EXECUTE_COMMAND_LINE

program main
  implicit none
  integer :: estat
  integer :: cstat
  character :: cmsg

! ====================
! A-1
! B-2
! C-2
! D-2
! E-2
! F-2
! ====================
  estat = 0
  cstat = 0
  cmsg = '-'
  call execute_command_line("ls -zzz", .true., estat, cstat, cmsg)
  if (cstat < 0) then
    print *, 'CMDSTAT: NG'
  else
    print *, 'CMDSTAT: OK'
  end if

end program main

! CHECK:  CMDSTAT: OK
