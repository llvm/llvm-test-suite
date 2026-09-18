! SPEC: F2008 R1232, R1236, C1258

module mod

contains

! ====================
! A-1 function
! B-1 name
! C-2 module procedure
! ====================
integer function func1(x)
    integer, intent(in) :: x
    func1 = x * 100
end function func1

end module mod

program main
    use mod
    implicit none
    integer :: x = 100
    integer res

    res = func1(x)
    print *, 'func1:', res

end program
