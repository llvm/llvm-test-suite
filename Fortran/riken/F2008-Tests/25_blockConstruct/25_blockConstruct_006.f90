! SPEC: F2008 R807, R808, C806, C807, C808, NOTE 8.5

program sample
    implicit none
    integer i
    integer :: s = 8
    real  :: x(8)

    do i = 1,s
        x(i) = i
    end do
    print "(a, *(f6.2))", "x =", x

    call sub1(1, 5, x)
    call sub1(4, 8, x)

contains

! ====================
! A-1
! B-1
! C-1
! D-2
! E-3
! F-5
! ====================
    subroutine sub1(n, m, a)
        integer, intent(in) :: n, m
        real :: a(:)
        real, save :: b(4)

        print "(a, *(f6.2))", "b(out) :before =", b
        b = a(1:4)

        block
            integer :: i
            real, save :: b(8)
            print "(a, *(f6.2))", "b(in) :before =", b
            do i = n, m
                b(i) = 2.5 * i
            end do
            print "(a, *(f6.2))", "b(in) :after =", b
        end block

        print "(a, *(f6.2))", "b(out) :after =", b

    end
end program sample
