! SPEC: F2008 12.4.3.4.5, R1207 C1212, C1213, C1214, C1215

! ====================
! A-1
! B-1
! C-1
! ====================
module mod1
    implicit none
    interface func
        module procedure func_a, func_b
    end interface func

contains
    function func_a(a, b, c)
        integer :: func_a
        integer, intent(in) :: a
        integer, intent(in) :: b
        real, intent(in) :: c
        func_a = a * b * int(c)
    end function func_a

    function func_b(a, b, c)
        integer :: func_b
        integer, intent(in) :: a
        integer, intent(in) :: b
        integer, intent(in) :: c
        func_b = a + b + c
    end function func_b
end module mod1

program main
    use mod1
    implicit none
    integer :: x = 3
    integer :: y = 5
    integer :: z = 7

    print *, 'func_a :', func(x, y, 3.0)
    print *, 'func_b :', func(x, y, z)
end program main
