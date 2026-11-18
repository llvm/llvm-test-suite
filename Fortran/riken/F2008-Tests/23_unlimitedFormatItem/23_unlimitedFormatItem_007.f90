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
    ! A-3
    ! B-1
    ! C-2
    ! ====================
     write(*, 100), x, rarray

100 format('x =', (f10.2), /, 'rarray = ', *(1p f12.4, :, " /"))

end program main
