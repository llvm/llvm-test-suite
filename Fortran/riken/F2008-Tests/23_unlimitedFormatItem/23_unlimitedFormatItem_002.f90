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
    ! B-2
    ! C-1
    ! ====================
    write(*, '("x=", f10.2, "; 2. iarray :", *(i0, :, "/"))') x, iarray

end program main
