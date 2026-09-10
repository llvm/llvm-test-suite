! SPEC: F2008 Introduction, 12.5.2.7

! ====================
! A-3 module
! B-1 intent(in)
! C-1 pointer
! D-1 target
! E-1 none
! ====================
module mod1

contains
  subroutine sub1(p, a, res)
    integer, pointer, intent(in) :: p
    integer, intent(in) :: a
    integer, intent(out) :: res
    print *, 'associated(p) = ', associated(p)
    if (.not. associated(p)) then
      res = -1
    else
      res = a + p
    end if
  end subroutine sub1
end module mod1

program main
  use mod1
  implicit none
  integer :: x, res
  integer, target :: i
  x = 200
  i = 7
  
  call sub1(i, x, res)
  print *, 'res =', res

end program main
