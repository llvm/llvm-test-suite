! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: F2008 12.4.3.4.5, R1207 C1212, C1213, C1214, C1215

! ====================
! A-1
! B-1
! C-2
! ====================
module mod2
    implicit none
    interface func
        module procedure func_a, func_b
    end interface func

contains
    function func_a(a, b, c)
        integer :: func_a
        integer, intent(in) :: a
        integer, intent(in) :: b
        real, optional, intent(in) :: c
        if (present(c)) then
            func_a = a * int(b) * int(c)
        else
            func_a = a * b
        end if
    end function func_a

    function func_b(a, b)
        integer :: func_b
        integer, intent(in) :: a
        integer, intent(in) :: b
        func_b = a + b
    end function func_b
end module mod2

program main
    use mod2
    implicit none
    integer :: x = 3
    integer :: y = 5
    integer :: z = 7

    print *, 'func_a :', func(x, y, z)
    print *, 'func_b :', func(x, y)
end program main

! FLANG: 35_genericResolution_c002.f90:13:
! FLANG-SAME: error:

! GFORT: 35_genericResolution_c002.f90:18:
! GFORT-NOT: .f90
! GFORT: Error:
