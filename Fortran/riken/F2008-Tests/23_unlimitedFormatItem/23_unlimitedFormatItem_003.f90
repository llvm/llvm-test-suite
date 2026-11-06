! SPEC: F2008 R1001, R1002, R1005, C1002

program main
    implicit none
    real rarray(10)
    integer :: i
    real :: x = 123.4567

    do i = 1,10
        rarray(i) = x
    enddo

    ! ====================
    ! A-3
    ! B-1
    ! C-2
    ! ====================
    print '(*(1p f12.4))', rarray

end program main
