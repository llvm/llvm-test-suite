! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: F2008 R505, R442, C510, C461

program main
    implicit none
    type entry
        integer :: x = 100
    end type entry
    integer res

    res = func1()

contains
    integer function func1()
        type (entry), target, save :: bottom(3)
        type (entry) :: top => bottom(1)
        print *, 'top%x =', top%x
        func1 = 1
    end function func1

end program

! FLANG: 10_pointerInitialization_c002.f90:18:
! FLANG-SAME: error:

! GFORT: 10_pointerInitialization_c002.f90:18:
! GFORT-NOT: .f90
! GFORT: Error: