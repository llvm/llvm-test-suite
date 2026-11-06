! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: F2008 R505, R442, C510, C461

program main
    implicit none
    integer res

    res = func1()

contains
    integer function func1()
        integer, target, save :: a(5) = (/10, 20, 30, 40, 50/)
        integer, pointer :: b(:) => a((/5, 2, 4/))
    
        print *, 'b =', b
        func1 = 1
    end function func1

end program

! FLANG: 10_pointerInitialization_c009.f90:15:
! FLANG-SAME: error:

! GFORT: 10_pointerInitialization_c009.f90:15:
! GFORT-NOT: .f90
! GFORT: Error: