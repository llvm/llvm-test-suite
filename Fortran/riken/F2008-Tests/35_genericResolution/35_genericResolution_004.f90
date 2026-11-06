! SPEC: F2008 12.4.3.4.5, R1207 C1212, C1213, C1214, C1215

! ====================
! A-1
! B-4
! C-1
! ====================
module mod4
    implicit none

    abstract interface
        real function i_func(x)
            integer, intent(in) :: x
        end function i_func
        real function r_func(x)
            real, intent(in) :: x
        end function r_func
    end interface

    interface mul
        module procedure r_proc, i_proc
    end interface mul

contains
    real function r_proc(f, a)
        procedure(r_func) :: f
        real, intent(in) :: a
        
        r_proc = f(a) * 2.0
    end function r_proc

    real function i_proc(f, a)
        procedure(i_func) :: f
        integer, intent(in) :: a
        
        i_proc = f(a) * 2
    end function i_proc

end module mod4

program main
    use mod4
    implicit none
    
    real :: res1
    integer :: res2
    
    res1 = mul(func1, 3.0)
    print "(a, f6.2)", "res1 =", res1

    res2 = mul(func2, 3)
    print *, "res2 =", res2

contains
    real function func1(x)
        real, intent(in) :: x
        func1 = x * x
    end function func1
    real function func2(x)
        integer, intent(in) :: x
        func2 = x * x
    end function func2
end program main
