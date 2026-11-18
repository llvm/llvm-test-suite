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
    ! C-7
    ! ====================
     write(*, 100), x, rarray

100 format((f10.2), 'rarray = ' *(1p f12.4, :, " /"))

end program main

! FLANG: 23_unlimitedFormatItem_c002.f90:21:
! FLANG-SAME: error:

! GFORT: 23_unlimitedFormatItem_c002.f90:21:
! GFORT-NOT: .f90
! GFORT: Error: