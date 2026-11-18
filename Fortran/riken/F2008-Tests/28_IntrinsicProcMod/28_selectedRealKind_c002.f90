! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: F2008 13.7.147

program main
    implicit none
    real :: r

! ====================
! A-2, B-5, C-3
! ====================
    print *, selected_real_kind(6, 37.8, radix(r))

end program main


! FLANG: 28_selectedRealKind_c002.f90:13:
! FLANG-SAME: error:

! GFORT: 28_selectedRealKind_c002.f90:13:
! GFORT-NOT: .f90
! GFORT: Error: