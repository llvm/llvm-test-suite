! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: F2008 EXECUTE_COMMAND_LINE

program main
  implicit none
  integer :: estat = 0
  integer :: cstat = 0
  integer :: cmsg = 0

! ====================
! A-1
! B-2
! C-2
! D-2
! E-3
! ====================
  call execute_command_line("ls", .true., estat, cstat, cmsg)

end program main

! FLANG: 28_executeCommandLine_c005.f90:19:
! FLANG-SAME: error:

! GFORT: 28_executeCommandLine_c005.f90:19:
! GFORT-NOT: .f90
! GFORT: Error:
