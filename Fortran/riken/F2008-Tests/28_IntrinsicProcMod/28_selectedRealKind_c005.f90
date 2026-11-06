! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: F2008 13.7.147

program main
    implicit none
    real :: r

! ====================
! A-1, B-1, C-1 (no arguments)
! ====================
    print *, selected_real_kind()

end program main


! FLANG: 28_selectedRealKind_c005.f90:13:
! FLANG-SAME: error:

! GFORT: 28_selectedRealKind_c005.f90:13:
! GFORT-NOT: .f90
! GFORT: Error: