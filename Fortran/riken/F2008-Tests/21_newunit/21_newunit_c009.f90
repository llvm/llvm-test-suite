! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: F2008 C904,C906

program main
  implicit none
  integer :: u

  open(unit=10, newunit=u, status='SCRATCH')
  write(u, *) "case16 NG", u
  close(u)

end program

! GFORT: 21_newunit_c009.f90:10:
! GFORT-NOT: .f90
! GFORT: Error:

! FLANG: 21_newunit_c009.f90:10:
! FLANG-SAME: error:
