! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: F2008 13.7.147

program main
    use iso_fortran_env
    use ieee_arithmetic
    implicit none
    real :: r

! ====================
! A-5, B-2, C-3
! ====================
    print *, ieee_selected_real_kind(10.5, 37, radix(r))

end program main


! FLANG: 28_ieeeSelectedRealKind_c001.f90:15:
! FLANG-SAME: error:

! GFORT: 28_ieeeSelectedRealKind_c001.f90:15:
! GFORT-NOT: .f90
! GFORT: Error: