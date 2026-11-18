! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: F2008 R1001, R1002, R1005, C1002

program main
    implicit none
    real rarray(6)
    integer :: i
    real :: x = 123.4567

    do i = 1,6
        rarray(i) = x * i
    enddo

    ! ====================
    ! A-1
    ! B-1
    ! C-6
    ! ====================
     write(*, 100) x, rarray

100 format('rarray = ', *(f10.2 1p, f12.4, :, " /"))

end program main

! FLANG: 23_unlimitedFormatItem_c001.f90:23:
! FLANG-SAME: error:

! GFORT: 23_unlimitedFormatItem_c001.f90:23:
! GFORT-NOT: .f90
! GFORT: Error: