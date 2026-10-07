! SPEC: F2008 R1232, R1236, C1258

module mod

contains

! ====================
! A-2 subroutine
! B-2 none
! C-2 module procedure
! ====================
subroutine sub1(x)
    integer, intent(in) :: x
    print *, 'sub1:', x * 25
end

end module mod

program main
    use mod
    implicit none
    integer :: x = 100
    integer res

    call sub1(x)

end program
