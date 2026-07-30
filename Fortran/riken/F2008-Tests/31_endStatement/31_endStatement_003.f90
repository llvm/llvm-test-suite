! SPEC: F2008 R1232, R1236, C1258

program main
    implicit none
    integer :: res
    integer :: x = 100

    call sub1(x)

contains
    ! ====================
    ! A-2 subroutine
    ! B-2 none
    ! C-1 internal
    ! ====================
    subroutine sub1(x)
      integer, intent(in) :: x
      print *, 'sub1:', x * 3
    end

end program
