! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: F2008 C522

program main
  implicit none

  integer :: a( &
       2,2,2,2,2, &
       2,2,2,2,2, &
       2,2,2,2,2, &
       2,2,2,2,2 )

  a = 1
  print *, size(shape(a))
  print *, sum(a)

end program

! GFORT: 06_maximumRank_c001.f90:12:
! GFORT-NOT: .f90
! GFORT: Error:

! FLANG: 06_maximumRank_c001.f90:9:
! FLANG-SAME: error:
