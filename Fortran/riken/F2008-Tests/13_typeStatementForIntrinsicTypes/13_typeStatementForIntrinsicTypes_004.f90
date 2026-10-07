! SPEC: F2008 R403,R404,R405

program main
    implicit none
    integer res
    
    res = func1()
    res = func2()

contains
    ! ====================
    ! A-1 TYPE
    ! B-4 COMPLEX
    ! C-1 None
    ! E-1 type decl
    ! ====================
    integer function func1()
        type(complex) :: c1
        c1 = cmplx(1.5, 3.0)
        print '("c1 = (", f8.3, ", ", f8.3, ")")', real(c1), aimag(c1)

        func1 = 1
    end function func1

    ! ====================
    ! A-1 TYPE
    ! B-4 COMPLEX
    ! C-5 complex(kind=selected_real_kind(15))
    ! E-1 type decl
    ! ====================
    integer function func2()
        type(complex(kind=selected_real_kind(15))) :: c2
        c2 = cmplx(1.7, 6.0)
        print '("c2 = (", f8.3, ", ", f8.3, ")")', real(c2), aimag(c2)

        func2 = 1
    end function func2

end program
