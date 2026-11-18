! SPEC: F2008 R403,R404,R405

program main
    implicit none
    integer res
    
    res = func1()
    res = func2()

contains
    ! ====================
    ! A-1 TYPE
    ! B-3 DOUBLE PRECISION
    ! C-1 None
    ! E-1 type decl
    ! ====================
    integer function func1()
        type(double precision) :: r1
        r1 = 1.0d0 / 3.0d0
        print '("r1 =", f20.10 )', r1

        func1 = 1
    end function func1

    ! ====================
    ! A-1 TYPE
    ! B-3 DOUBLE PRECISION
    ! C-4 real(selected_real_kind(18))
    ! E-1 type decl
    ! ====================
    integer function func2()
        type(real(selected_real_kind(18))) :: r2
        r2 = 1.0d0 / 7.0d0
        print '("r2 =", f20.10 )', r2

        func2 = 1
    end function func2

end program
