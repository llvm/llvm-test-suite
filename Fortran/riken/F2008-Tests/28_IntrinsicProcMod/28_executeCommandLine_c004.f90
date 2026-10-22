! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: F2008 EXECUTE_COMMAND_LINE

program main
  implicit none
  integer :: estat = 0
  real :: cstat = 0.0

! ====================
! A-1
! B-2
! C-2
! D-3
! E-1
! ====================
  call execute_command_line("ls", .true., estat, cstat)

end program main

! FLANG: 28_executeCommandLine_c004.f90:18:
! FLANG-SAME: error:

! GFORT: 28_executeCommandLine_c004.f90:18:
! GFORT-NOT: .f90
! GFORT: Error:
