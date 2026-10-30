! SPEC: F2008 Introduction, Table 2.2

! ====================
! A-1 empty contains
! B-4 subprogram
! ====================
function func1(a, b) result(res)
    implicit none
    integer, intent(in) :: a, b
    integer :: res

    res = a * b

! Empty contains section
contains

end function func1

program main
    implicit none
    interface my_func
      function func1(a, b) result(res)
        implicit none
        integer, intent(in) :: a, b
        integer :: res
      end function func1
    end interface my_func
    integer :: x = 30
    integer :: y = 5
    integer :: res

    res = func1(x, y)

    print *, 'res =', res
    print *, "Done!"

end program main
