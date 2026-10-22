! RUN: not %gfortran -c %s 2>&1 | FileCheck --check-prefix=GFORT %s
! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s

! SPEC: F2008 R404, R426, C426

! ====================
! A-1 TYPE
! B-7 DOUBLEPRECISION or the same as the name of any intrinsic type
! E-1 type decl
! ====================
program main
    implicit none
    integer res
    
    res = func1()
    res = func2()

contains
    integer function func1()
        type :: integer
            integer :: val
        end type integer
        integer :: a1
        type(integer) :: b1

        a1 = 100
        b1%val = 200

        print *, 'a1 =', a1
        print *, 'b1 =', b1%val

        func1 = 1
    end function func1

    integer function func2()
        type :: real
            real(8) :: val
        end type real
        real :: a2
        type(real) :: b2 

        a2 = 3.14
        b2%val = 0.5

        print "(a, f6.2)", "a2 =", a2
        print "(a, f6.2)", "b2 =", b2%val

        func2 = 1
    end function func2

end program

! GFORT: 13_typeStatementForIntrinsicTypes_c001.f90:20:
! GFORT-NOT: .f90
! GFORT: Error:
! GFORT: 13_typeStatementForIntrinsicTypes_c001.f90:36:
! GFORT-NOT: .f90
! GFORT: Error:

! FLANG: 13_typeStatementForIntrinsicTypes_c001.f90:20:
! FLANG-SAME: error:
! FLANG: 13_typeStatementForIntrinsicTypes_c001.f90:36:
! FLANG-SAME: error: