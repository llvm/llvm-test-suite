! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: F2008 3.3.2.5

program sample
    implicit none
    integer :: i
    i = 0
100; i = i + 1
    write(*,*) i
    if (i < 5) goto 100
    print *, "Done"

end program sample

! FLANG: 38_semicolonAtLineStart_c001.f90:10:
! FLANG-SAME: error:

! GFORT: 38_semicolonAtLineStart_c001.f90:10:
! GFORT-NOT: .f90
! GFORT: Error: