! SPEC: F2008 R752,C735

program main
    use, intrinsic :: iso_fortran_env, only: int32, int64
    implicit none
    integer res
    res = func1()
    res = func2()
    res = func3()

contains
    integer function func1()
        integer :: arr1(5, 3)
        forall ( integer :: i = 1:5, j = 1:3 )
            arr1(i, j) = i * j
        end forall
        print *, 'arr1 = ', arr1
        func1 = 1
    end function func1

    integer function func2()
        integer(kind=int32) :: arr2(3, 7)
        forall ( integer(kind=int32) :: i = 1:3, j = 1:7 )
            arr2(i, j) = i + j
        end forall
        print *, 'arr2 = ', arr2
        func2 = 1
    end function func2

    integer function func3()
        integer(kind=int64) :: arr3(2, 3)
        forall ( integer(kind=int64) :: i = 1:2, j = 1:3 )
            arr3(i, j) = j - i
        end forall
        print *, 'arr3 = ', arr3
        func3 = 1
    end function func3

end program
