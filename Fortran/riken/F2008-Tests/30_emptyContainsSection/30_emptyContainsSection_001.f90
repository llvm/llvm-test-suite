! SPEC: F2008 Introduction, Table 2.2

! ====================
! A-1 empty contains
! B-1 program
! ====================
program main
    implicit none
    integer :: x = 80;

    print *, 'x = ', x
    print *, "Done!"

    ! Empty contains section
    contains
    
end program main
