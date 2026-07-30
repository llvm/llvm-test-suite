! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: F2008 R807, R808, C806, C807, C808, NOTE 8.5

! ====================
! A-1
! B-1
! C-10
! D-1
! E-1
! ====================
program sample
    implicit none
    integer n
    n = 8
    block
        integer :: i
        real :: a(8)
        real :: b
        namelist /input_params/ a, b
        do i = 1,n
            a(i) = 2.5 * i
        end do
        print "(a, *(f6.2))", "a =", a
    end block
end program sample

! FLANG: 25_blockConstruct_c006.f90:21:
! FLANG-SAME: error

! GFORT: 25_blockConstruct_c006.f90:21:
! GFORT-NOT: .f90
! GFORT: Error: