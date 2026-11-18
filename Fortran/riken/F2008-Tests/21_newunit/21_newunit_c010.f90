! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: F2008 C904,C906

program main
  implicit none
  integer :: u

  open(10 ,newunit=u, file='x17.txt', status='replace')
  write(u, *) "case17 NG", u
  close(u)

end program

! GFORT: 21_newunit_c010.f90:10:
! GFORT-NOT: .f90
! GFORT: Error:

! FLANG: 21_newunit_c010.f90:10:
! FLANG-SAME: error:
