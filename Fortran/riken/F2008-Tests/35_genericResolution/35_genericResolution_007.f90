! SPEC: F2008 12.4.3.4.5, R1207 C1212, C1213, C1214, C1215

! ====================
! A-3
! B-1
! C-1
! ====================
module mod7
    implicit none

    type :: t1
        integer :: id
        real, allocatable :: values(:)
    end type t1

    type :: t2
        integer :: id
        integer, allocatable :: values(:)
    end type t2

    interface assignment(=)
        module procedure assign_t1, assign_t2
    end interface assignment(=)

contains

    subroutine assign_t1(lhs, rhs)
        type(t1), intent(out) :: lhs
        type(t1), intent(in) :: rhs

        lhs%id = rhs%id
        if (allocated(rhs%values)) then
            if (allocated(lhs%values)) deallocate(lhs%values)
            allocate(lhs%values(size(rhs%values)))
            lhs%values = rhs%values
        end if
    end subroutine assign_t1

    subroutine assign_t2(lhs, rhs)
        type(t2), intent(out) :: lhs
        type(t2), intent(in) :: rhs

        lhs%id = rhs%id
        if (allocated(rhs%values)) then
            if (allocated(lhs%values)) deallocate(lhs%values)
            allocate(lhs%values(size(rhs%values)))
            lhs%values = rhs%values
        end if
    end subroutine assign_t2

end module mod7

program main
    use mod7
    implicit none
    type(t1) :: d1, d2
    type(t2) :: d3, d4

    d1%id = 1
    allocate(d1%values(2))
    d1%values = [10.5, 20.5]

    d2 = d1 

    print *, "d2%id = ", d2%id
    print "(a, f6.2, f6.2)", "d2%values = ", d2%values

    d3%id = 2
    allocate(d3%values(2))
    d3%values = [10, 20]

    d4 = d3 

    print *, "d4%id = ", d4%id
    print *, "d4%values = ", d4%values
end program main
