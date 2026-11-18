! SPEC: F2008 R505, R442, C510, C461

module mod
character(len=10), target :: alpha = 'abcdefghij'

contains

integer function func3()
    character(len=3), pointer :: tmp => alpha(4:6)
    print *, 'tmp = ', tmp
    func3 = 1
end function func3

end module mod

program main
    use mod
    implicit none
    type entry
        integer :: x = 100
    end type entry
    integer res

    res = func1()
    res = func2()
    res = func3()

contains
    integer function func1()
        type (entry), target, save :: bottom(3)
        type (entry), pointer :: top => bottom(2)

        print *, 'top%x =', top%x

        func1 = 1
    end function func1

    integer function func2()
        integer, target :: a(5) = (/1, 2, 3, 4, 5/)
        integer, pointer :: b(:) => a(3:5)
    
        print *, 'b =', b

        func2 = 1
    end function func2

end program
