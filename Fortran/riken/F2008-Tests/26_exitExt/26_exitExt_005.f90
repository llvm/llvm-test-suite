! SPEC: F2008 R850

! ====================
! A-4 select type
! B-1 self construct
! C-1 with construct-name
! ====================

program main
  implicit none
  class(*), allocatable :: obj
  integer :: st = 0

  allocate(obj, source=10)

  outer: select type(obj)
    type is (integer)
      st = 1
      exit outer
      st = -1
    class default
      st = 0
  end select outer
  
  write(*,*) "st =",st

end program
