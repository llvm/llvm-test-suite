! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: F2008 R752,C735

program main
    implicit none
    real, target :: arr(5, 3)
    forall ( real :: i = 1:5, j = 1:3 )
        arr(i, j) = i * j
    end forall
    print *, 'arr = ', arr
end program

! FLANG: 12_kindOfForallIndex_c001.f90:9:
! FLANG-SAME: error:

! GFORT: 12_kindOfForallIndex_c001.f90:9:
! GFORT-NOT: .f90
! GFORT: Error: