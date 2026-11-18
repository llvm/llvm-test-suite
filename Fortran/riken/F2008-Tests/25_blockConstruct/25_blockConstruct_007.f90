! SPEC: F2008 R807, R808, C806, C807, C808, NOTE 8.5

! ====================
! A-2
! B-2
! C-1
! D-1
! E-1
! F-1
! ====================
program sample
    implicit none
    integer n
    n = 8
    blk1: block
        integer :: i
        real :: a(n)
        do i = 1,n
            a(i) = 2.5 * i
        end do
        print "(a, *(f6.2))", "a :after =", a
    end block blk1
end program sample
