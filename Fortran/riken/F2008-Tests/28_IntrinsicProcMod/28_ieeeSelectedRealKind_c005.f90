! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: F2008 14.11.18

program main
    use iso_fortran_env
    use ieee_arithmetic
    implicit none
    real :: r

! ====================
! A-1, B-1, C-1 (no arguments)
! ====================
    print *, ieee_selected_real_kind()

end program main


! FLANG: 28_ieeeSelectedRealKind_c005.f90:15:
! FLANG-SAME: error:

! GFORT: 28_ieeeSelectedRealKind_c005.f90:15:
! GFORT-NOT: .f90
! GFORT: Error: