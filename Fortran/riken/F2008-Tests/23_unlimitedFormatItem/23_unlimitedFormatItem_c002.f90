! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: F2008 R1001, R1002, R1005, C1002

program main
    implicit none
    integer iarray(10)
    integer :: i
    real :: x = 123.4567

    do i = 1,10
        iarray(i) = i*100
    enddo

    ! ====================
    ! A-2
    ! B-3
    ! C-1
    ! ====================
    write(*, '("2. iarray :", *(i0, :, "/"), "x=", f10.2)') iarray, x

end program main

! FLANG: 23_unlimitedFormatItem_c002.f90:21:
! FLANG-SAME: error:

! GFORT: 23_unlimitedFormatItem_c002.f90:21:
! GFORT-NOT: .f90
! GFORT: Error: