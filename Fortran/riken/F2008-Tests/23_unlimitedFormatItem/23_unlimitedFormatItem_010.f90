! SPEC: F2008 R1001, R1002, R1005, C1002

program main
    implicit none
    integer iarray(10)
    integer :: i

    do i = 1,10
        iarray(i) = i*50
    enddo

    ! ====================
    ! A-1
    ! B-2
    ! C-5
    ! ====================
    write(*, 100) iarray

100 format('iarray :', *(i0, : "/")) 

end program main
