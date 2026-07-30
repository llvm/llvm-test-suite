! SPEC: F2008 R807, R808, C806, C807, C808, NOTE 8.5

! ====================
! A-1
! B-1
! C-3
! D-1
! E-1
! F-3
! ====================
subroutine sub
    implicit none
    integer :: n1, n10, n100, n1000, n10000
    integer :: i
    integer, asynchronous :: buf(10000)
    integer :: id1

    open(10, file="data.bin", form="unformatted")
    write(10) (i*4,i=1,10000)
    close(10)

    open(20, file="data.bin", asynchronous="yes", form="unformatted")
    read(20, asynchronous="yes", id=id1) buf

    block
        call sub2()
    end block

    wait(20, id=id1)

    n10000 = buf(10000)
    n1000 = buf(1000)
    n100 = buf(100)
    n10 = buf(10)
    n1 = buf(1)

    print *, n1, n10, n100, n1000, n10000

end subroutine sub

subroutine sub2
end subroutine sub2

program main
    implicit none

    call sub
end program main
