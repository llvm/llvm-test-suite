! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: F2008 C904,C906

program main
  implicit none
  integer :: u
  character(len=7, kind=4) :: s

  s = 'SCRATCH'
  open(newunit=u, status=s) 
  write(u, *) "case10 NG", u
  close(u)

end program

! GFORT: 21_newunit_c003.f90:12:
! GFORT-NOT: .f90
! GFORT: Error:

! FLANG: 21_newunit_c003.f90:12:
! FLANG-SAME: error:
