! SPEC: F2008 R807, R808, C806, C807, C808, NOTE 8.5

! ====================
! A-1
! B-1
! C-1
! D-1
! E-1
! F-6
! ====================
module mod8

contains

    integer function func1(l, n, m, a)
        real, intent(in) :: l
        integer, intent(in) :: n, m
        real :: a(:)
        real :: b(4)

        b = a(1:4)
        print "(a, *(f6.2))", "b(out) =", b

        block
            integer :: i
            real :: b(m-n)
            do i = 1, m-n
                b(i) = l * i
            end do
            print "(a, *(f6.2))", "b(in) =", b
        end block
        func1 = 1
    end function func1
end module mod8

program sample
    use mod8
    implicit none
    integer i, res
    integer :: s = 8
    real  :: x(8)

    do i = 1,s
        x(i) = i
    end do
    print "(a, *(f6.2))", "x =", x
    res = func1(2.0, 1, s, x)
    res = func1(3.0, 5, 8, x)

contains

end program sample
