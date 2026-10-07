! SPEC: F2008 R403,R404,R405

program main
    use, intrinsic :: iso_fortran_env, only: real32
    implicit none
    integer res
    
    res = func1()
    res = func2()
    res = func3()

contains
    ! ====================
    ! A-1 TYPE
    ! B-2 REAL
    ! C-1 None
    ! E-1 type decl
    ! ====================
    integer function func1()
        type(real) r1
        r1 = 0.5
        print "(a, f6.2)", "r1 =", r1

        func1 = 1
    end function func1

    ! ====================
    ! A-1 TYPE
    ! B-2 REAL
    ! C-3 real(kind=float)
    ! E-1 type decl
    ! ====================
    integer function func2()
        integer, parameter :: float = selected_real_kind(15)
        type(real(kind=float)) r2
        r2 = 10.7
        print "(a, f6.2)", "r2 =", r2

        func2 = 1
    end function func2

    ! ====================
    ! A-1 TYPE
    ! B-2 REAL
    ! C-6 real(real32)
    ! E-2 type-param-name
    ! ====================
    integer function func3()
        type my_type
            type(real(real32)) r3
        end type my_type
        type(my_type) :: t3
        t3%r3 = 3.14
        print "(a, f6.2)", "t3%r3 =", t3%r3

        func3 = 1
    end function func3

end program
