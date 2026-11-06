! SPEC: F2008 12.4.3.4.5, R1207 C1212, C1213, C1214, C1215

! ====================
! A-2
! B-1
! C-1
! ====================
module mod2
    implicit none

    type :: r_vec
        real :: x, y
    end type r_vec
    type :: i_vec
        integer :: x, y
    end type i_vec

    interface operator(+)
        module procedure add_r, add_i
    end interface operator(+)

contains

    function add_r(a, b) result(c)
        type(r_vec), intent(in) :: a, b
        type(r_vec) :: c
        c%x = a%x + b%x
        c%y = a%y + b%y
        print *, '---> add_r()'
    end function add_r

    function add_i(a, b) result(c)
        type(i_vec), intent(in) :: a, b
        type(i_vec) :: c
        c%x = a%x + b%x
        c%y = a%y + b%y
        print *, '---> add_i()'
    end function add_i

end module mod2

program main
    use mod2
    implicit none
    type(r_vec) :: r1, r2, r3
    type(i_vec) :: i1, i2, i3

    r1 = r_vec(1.0, 2.0)
    r2 = r_vec(3.0, 4.0)

    print *, 'r3 = r1 + r2:'
    r3 = r1 + r2
    print *, 'r3 = r1 + r2 + r3:'
    r3 = r1 + r2 + r3

    print "(a, f6.2, f6.2)", "r3 =", r3%x, r3%y

    i1 = i_vec(10, 20)
    i2 = i_vec(30, 40)

    print *, 'i3 = i1 + i2:'
    i3 = i1 + i2
    print *, 'i3 = i1 + i2 + i3:'
    i3 = i1 + i2 + i3

    print *, "i3 = ", i3%x, i3%y

end program main
