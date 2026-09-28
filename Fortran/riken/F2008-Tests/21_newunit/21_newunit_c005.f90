! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: F2008 C904,C906

program main
  implicit none
  integer :: u
  character(len=10) :: st_arr(2)
  
  st_arr= ['old', 'new']

  open(newunit=u, file="x12", status=st_arr)
  write(u, *) "case12 NG", u
  close(u)

end program

! GFORT: 21_newunit_c005.f90:13:
! GFORT-NOT: .f90
! GFORT: Error:

! FLANG: 21_newunit_c005.f90:13:
! FLANG-SAME: error:
