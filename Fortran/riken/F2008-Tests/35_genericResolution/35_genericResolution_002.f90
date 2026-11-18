! SPEC: F2008 12.4.3.4.5, R1207 C1212, C1213, C1214, C1215

! ====================
! A-1
! B-2
! C-2
! ====================
module mod_b
    implicit none
    interface func
        module procedure func_a, func_b
    end interface func

contains
    function func_a(a, b, c, d)
        integer :: func_a
        integer, intent(in) :: a
        integer, intent(in) :: b
        integer, intent(in) :: c
        integer, intent(in) :: d
        func_a = a * b * c * d
    end function func_a

    function func_b(x, y, z)
        integer :: func_b
        integer, intent(in) :: x
        integer, intent(in) :: y
        integer, intent(in) :: z
        func_b = x + y + z
    end function func_b
end module mod_b

program main
    use mod_b
    implicit none
    integer :: x = 3
    integer :: y = 5
    integer :: z = 7

    print *, 'func_a :', func(x, y, z, 10)
    print *, 'func_b :', func(x, y, z)
end program main
