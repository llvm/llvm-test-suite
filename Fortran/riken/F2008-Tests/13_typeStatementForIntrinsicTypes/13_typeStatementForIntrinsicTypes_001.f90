! SPEC: F2008 R403,R404,R405

program main
    use, intrinsic :: iso_fortran_env, only: int32, int64
    implicit none
    integer res
    
    res = func1()
    res = func2()
    res = func3()
    res = func4()

contains
    ! ====================
    ! A-1 TYPE
    ! B-1 INTEGER
    ! C-1 None
    ! E-1 type decl
    ! ====================
    integer function func1()
        type(integer) i1
        i1 = 500
        print *, 'i1 =', i1

        func1 = 1
    end function func1

    ! ====================
    ! A-1 TYPE
    ! B-1 INTEGER
    ! C-2 integer(long)
    ! E-1 type decl
    ! ====================
    integer function func2()
        integer, parameter :: long = selected_int_kind(18)
        type(integer(long)) i2
        i2 = 1234567890
        print *, 'i2 =', i2

        func2 = 1
    end function func2

    ! ====================
    ! A-1 TYPE
    ! B-1 INTEGER
    ! C-6 integer(int32)
    ! E-1 type decl
    ! ====================
    integer function func3()
        type(integer(int32)) i3
        i3 = 256
        print *, 'i3 =', i3

        func3 = 1
    end function func3

    ! ====================
    ! A-1 TYPE
    ! B-1 INTEGER
    ! C-6 integer(int32)
    ! E-2 type-param-name
    ! ====================
    integer function func4()
        type my_type
          type(integer(int64)) i4
        end type my_type
        type(my_type) :: t4
        t4%i4 = 1024
        print *, 't4%i4 =', t4%i4

        func4 = 1
    end function func4

end program
