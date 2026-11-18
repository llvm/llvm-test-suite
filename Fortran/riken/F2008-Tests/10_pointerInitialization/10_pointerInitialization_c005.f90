! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: F2008 R505, R442, C510, C461

program main
    implicit none
    integer res

    res = func1()

contains
    integer function func1()
        type entry
            integer :: x = 5
        end type entry

        type (entry), allocatable, target, save :: arr(:)
        type (entry), pointer :: tmp => arr(1)

        allocate(arr(3))

        func1 = 1
    end function func1

end program

! FLANG: 10_pointerInitialization_c005.f90:19:
! FLANG-SAME: error:

! GFORT: 10_pointerInitialization_c005.f90:19:
! GFORT-NOT: .f90
! GFORT: Error: