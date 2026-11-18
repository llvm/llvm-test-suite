! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: F2008 13.7.147

program main
    use iso_fortran_env
    use ieee_arithmetic
    implicit none

! ====================
! A-3, B-3, C-4
! ====================
    print *, ieee_selected_real_kind(15, 307, 2.0)

end program main


! FLANG: 28_ieeeSelectedRealKind_c003.f90:14:
! FLANG-SAME: error:

! GFORT: 28_ieeeSelectedRealKind_c003.f90:14:
! GFORT-NOT: .f90
! GFORT: Error: