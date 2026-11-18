! SPEC: F2008 R403,R404,R405

program main
    implicit none
    integer res
    
    res = func1()
    res = func2()

contains
    ! ====================
    ! A-1 TYPE
    ! B-6 LOGICAL
    ! C-1 None
    ! E-1 type decl
    ! ====================
    integer function func1()
        type(logical) l1
        l1 = .true.
        print *, 'l1 =', l1

        func1 = 1
    end function func1

    ! ====================
    ! A-1 TYPE
    ! B-6 LOGICAL
    ! C-2 logical(log)
    ! E-1 type decl
    ! ====================
    integer function func2()
        integer, parameter :: log = 8
        type(logical(log)) l2
        l2 = .false.
        print *, 'l2 =', l2

        func2 = 1
    end function func2

end program
