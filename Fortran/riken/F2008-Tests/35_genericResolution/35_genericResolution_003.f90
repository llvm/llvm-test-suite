! SPEC: F2008 12.4.3.4.5, R1207 C1212, C1213, C1214, C1215

! ====================
! A-1
! B-3
! C-1
! ====================
module mod3
    implicit none

    abstract interface
        real function r_func(x)
            real, intent(in) :: x
        end function r_func
    end interface

    interface mul
        module procedure proc, data_obj
    end interface mul

contains
    real function proc(f, a)
        procedure(r_func) :: f
        real, intent(in) :: a
        
        proc = f(a) * 2.0
    end function proc

    real function data_obj(a, b)
        real, intent(in) :: a
        real, intent(in) :: b
        
        data_obj = a * b * 3.0
    end function data_obj

end module mod3

program main
    use mod3
    implicit none
    
    real :: result
    
    result = mul(func1, 3.0)
    print "(a, f6.2)", "Result =", result

    result = mul(0.5, 3.0)
    print "(a, f6.2)", "Result =", result

contains
    real function func1(x)
        real, intent(in) :: x
        func1 = x * x
    end function func1
end program main
