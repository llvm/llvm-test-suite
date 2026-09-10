! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: F2008 R516

program main
  implicit none

  integer, parameter :: a( &
       2,2,2,2,2, &
       2,2,2,2,2, &
       2,2,2,2,2, &
       2,2,2,2,2 ) = 1

  print *, size(shape(a))
  print *, sum(a)

end program

! GFORT: 06_maximumRank_c002.f90:15:
! GFORT-NOT: .f90
! GFORT: Error:

! FLANG: 06_maximumRank_c002.f90:9:
! FLANG-SAME: error:
