! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: F2008 R807, R808, C806, C807, C808, NOTE 8.5

! ====================
! A-2
! B-3
! C-1
! D-1
! E-1
! ====================
program sample
    implicit none
    integer n
    n = 8
    lbk1: block
        integer :: i
        real :: a(n)
        print "(a, *(f6.2))", "a :before =", a
        do i = 1,n
            a(i) = 2.5 * i
        end do
        print "(a, *(f6.2))", "a :after =", a
    end block blk2
end program sample

! FLANG: 25_blockConstruct_c001.f90:25:
! FLANG-SAME: error:

! GFORT: 25_blockConstruct_c001.f90:25:
! GFORT-NOT: .f90
! GFORT: Error: