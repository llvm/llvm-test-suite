! SPEC: F2008 R1232, R1236, C1258

program main
    implicit none
    integer :: res
    integer :: x = 100

    res = func1(x)

contains
    ! ====================
    ! A-1 function
    ! B-2 none
    ! C-1 internal
    ! ====================
    integer function func1(x)
      integer, intent(in) :: x
        print *, 'func1:', x * 3
        func1 = 1
    end

end program
