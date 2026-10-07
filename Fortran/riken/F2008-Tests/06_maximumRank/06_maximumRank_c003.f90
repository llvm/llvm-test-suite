! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: F2008 C522

program main
  implicit none
  integer :: total
  total = sum(f())

  print *, size(shape(f()))
  print *, total

contains
  function f() result(r)
    implicit none
    integer :: r( &
         2,2,2,2,2, &
         2,2,2,2,2, &
         2,2,2,2,2, &
         2,2,2,2,2 )
    r = 1
  end function
end program

! GFORT: 06_maximumRank_c003.f90:20:
! GFORT-NOT: .f90
! GFORT: Error:

! FLANG: 06_maximumRank_c003.f90:17:
! FLANG-SAME: error:
