! SPEC: F2008 12.4.3.4.5, R1207 C1212, C1213, C1214, C1215

! ====================
! A-2
! B-1
! C-1
! ====================
module mod_d
    implicit none

    type :: r_vec
        real :: x, y
    end type r_vec

    interface operator(+)
        module procedure add_1, add_2
    end interface operator(+)

contains

    function add_1(a1, b1) result(c1)
        type(r_vec), intent(in) :: a1, b1
        type(r_vec) :: c1
        c1%x = a1%x + b1%x
        c1%y = a1%y + b1%y
    end function add_1

    function add_2(a) result(b)
        type(r_vec), intent(in) :: a
        type(r_vec) :: b
        b%x = a%x + a%x
        b%y = a%y + a%y
    end function add_2

end module mod_d

program main
    use mod_d
    implicit none
    type(r_vec) :: r1, r2, r3, r4

    r1 = r_vec(1.0, 2.0)
    r2 = r_vec(3.0, 4.0)

    r3 = r1 + r2

    print "(a, f6.2, f6.2)", "r3 =", r3%x, r3%y

    r4 = r1 + r2 + r3

    print "(a, f6.2, f6.2)", "r4 =", r4%x, r4%y

end program main
