! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: F2008 C904,C906

program main
  implicit none
  integer :: u

  open(newunit=u, file='x8.txt', status='SCRATCH')
  write(u, *) "case8 NG", u
  close(u)

end program

! GFORT: 21_newunit_c001.f90:10:
! GFORT-NOT: .f90
! GFORT: Error:

! FLANG: 21_newunit_c001.f90:10:
! FLANG-SAME: error:
