! SPEC: F2008 Introduction, 12.2.2.2

program main
    implicit none

    abstract interface
        function func_interface(a, b)
            real :: func_interface, a, b
        end function func_interface
    end interface

    procedure(func_interface), pointer :: p_func => null()

    real :: n = 5.3

    p_func => add
    print "(a, f6.2)", "Add: ", p_func(10.0, 5.0)

    p_func => multiply
    print "(a, f6.2)", "Multiply: ", p_func(10.0, 5.0)

contains
    function add(a, b)
        real :: add, a, b
        add = a + b + n
    end function add

    function multiply(a, b)
        real :: multiply, a, b
        multiply = a * b * n
    end function multiply

end program main
