! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: F2008 R807, R808, C806, C807, C808, NOTE 8.5

! ====================
! A-1
! B-1
! C-6
! D-1
! E-1
! ====================
subroutine sub1(l, n, m, a)
    real, intent(in) :: l
    integer, intent(in) :: n, m
    real :: a(:)
    real :: b(8)

    b = a(n:m)
    print "(a, *(f6.2))", "b(out) =", b(1:m-(n-1))

    block
        integer :: i
        real :: c(8)
        common /shared_data/ c
        do i = n, m
            c(i) = l * i
        end do
        print "(a, *(f6.2))", "c(in) =", c
    end block
end subroutine sub1

program sample
    implicit none
    interface
        subroutine sub1(l, n, m, a)
            real, intent(in) :: l
            integer, intent(in) :: n, m
            real :: a(:)
        end subroutine sub1
    end interface
    integer i
    integer :: s = 8
    real  :: x(8)

    do i = 1,s
        x(i) = i
    end do
    print "(a, *(f6.2))", "x =", x

    call sub1(2.0, 1, s, x)
    call sub1(3.0, 5, 8, x)

end program sample

! FLANG: 25_blockConstruct_c002.f90:25:
! FLANG-SAME: error

! GFORT: 25_blockConstruct_c002.f90:25:
! GFORT-NOT: .f90
! GFORT: Error: