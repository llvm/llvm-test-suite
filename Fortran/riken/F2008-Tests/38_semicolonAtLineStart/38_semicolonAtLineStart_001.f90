! SPEC: F2008 3.3.2.5

program sample
    implicit none
    integer x, y

    x = 100

    y = func1(x)
    print *, 'func1 = ', y

    y = func2(x)
    print *, 'func2 = ', y

contains
    function func1(a)
        integer :: func1
        integer, intent(in) :: a
        ; func1 = a * 2
    end function func1

    function func2(b)
        integer :: func2
        integer, intent(in) :: b
        func2 = b / 5
        ;
    end function func2

end program sample
