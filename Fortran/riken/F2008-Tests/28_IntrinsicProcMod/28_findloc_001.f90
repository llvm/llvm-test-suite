! SPEC: F2008:13.7.61 FINDLOC

program main
  implicit none

  call test_integer()
  call test_real()
  call test_complex()
  call test_character()
  call test_logical()

contains

  !========================
  ! A-1 integer
  !========================
  subroutine test_integer()
    integer :: a(3) = [1,2,3]
    integer :: pos(1)
    integer :: v(2) = [2,3]

    pos = findloc(a, 2)
    write(*,'(A,1X,I5)') "INTEGER:", pos
    pos = findloc(a, v(1))
    write(*,'(A,1X,I5)') "INTEGER(array(1)):", pos
  end subroutine
  
  !========================
  ! A-2 real
  !========================
  subroutine test_real()
    real :: a(3) = [1.11,2.22,3.33]
    integer :: pos(1)
  
    pos = findloc(a, 2.22)
  
    write(*,'(A,1X,I5)') "REAL:", pos
  end subroutine
  
  !========================
  ! A-3 complex
  !========================
  subroutine test_complex()
    complex :: a(3)
    integer :: pos(1)
  
    a = [(1.1,-1.1), (2.2,-2.2), (3.3,-3.3)]
  
    pos = findloc(a, (2.2,-2.2))
  
    write(*,'(A,1X,I5)') "COMPLEX:", pos
  end subroutine
  
  !========================
  ! A-4 character
  !========================
  subroutine test_character()
    character(len=1) :: a(3) = ['a','b','c']
    integer :: pos(1)
  
    pos = findloc(a, 'b')
  
    write(*,'(A,1X,I5)') "CHARACTER:", pos
  end subroutine
  
  !========================
  ! A-5 logical
  !========================
  subroutine test_logical()
    logical :: a(3) = [.false., .true., .false.]
    integer :: pos(1)
  
    pos = findloc(a, .true.)
  
    write(*,'(A,1X,I5)') "LOGICAL:", pos
  end subroutine

end program
