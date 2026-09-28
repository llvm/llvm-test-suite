! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: F2008 EXECUTE_COMMAND_LINE

program main
  implicit none
  real :: wait = 0.0

! ====================
! A-1
! B-4
! C-1
! D-1
! E-1
! ====================
  call execute_command_line("ls", wait)

end program main

! FLANG: 28_executeCommandLine_c002.f90:17:
! FLANG-SAME: error:

! GFORT: 28_executeCommandLine_c002.f90:17:
! GFORT-NOT: .f90
! GFORT: Error:
