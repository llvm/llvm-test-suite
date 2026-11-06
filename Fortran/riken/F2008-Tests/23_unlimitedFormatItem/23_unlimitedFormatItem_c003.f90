! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: F2008 R1001, R1002, R1005, C1002

program main
    implicit none
    integer iarray(10)
    integer rarray(10)
    integer :: i
    real :: x = 123.4567

    do i = 1,10
        iarray(i) = i*100
        rarray(i) = x*10
    enddo

    ! ====================
    ! A-3
    ! B-4
    ! C-1
    ! ====================
    print '("rarray :", *(f10.2, : "/"), "; iarray :", *(i0, :, "/"))', rarray, iarray

end program main

! FLANG: 23_unlimitedFormatItem_c003.f90:23:
! FLANG-SAME: error:

! GFORT: 23_unlimitedFormatItem_c003.f90:23:
! GFORT-NOT: .f90
! GFORT: Error: