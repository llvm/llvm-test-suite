! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: F2008 R505, R442, C510, C461

program main
    implicit none
    integer res
    integer n

    n = 4
    res = func1()

contains
    integer function func1()
        integer, target :: a(5) = (/1, 2, 3, 4, 5/)
        integer, pointer :: b(:) => a(3:n)
    
        print *, 'b =', b
        func1 = 1
    end function func1

end program

! FLANG: 10_pointerInitialization_c007.f90:17:
! FLANG-SAME: error:

! GFORT: 10_pointerInitialization_c007.f90:17:
! GFORT-NOT: .f90
! GFORT: Error: