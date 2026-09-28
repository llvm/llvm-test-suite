! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: F2008 13.7.147

program main
    implicit none

! ====================
! A-3, B-3, C-4
! ====================
    print *, selected_real_kind(15, 307, 2.0)

end program main


! FLANG: 28_selectedRealKind_c003.f90:12:
! FLANG-SAME: error:

! GFORT: 28_selectedRealKind_c003.f90:12:
! GFORT-NOT: .f90
! GFORT: Error: