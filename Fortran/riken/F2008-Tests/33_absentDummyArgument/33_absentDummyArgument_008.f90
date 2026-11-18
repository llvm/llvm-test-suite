! SPEC: F2008 R505, R442, C510, C461

module mod2

contains

  subroutine sub1(x, y, z, sum)
    implicit none
    integer, intent(in) :: x, y
    integer, optional, intent(in) :: z
    integer, intent(out) :: sum

    print *, 'present(z) = ', present(z)
    if (.not. present(z)) then
      sum = x + y
    else 
      sum = x + y + z
    end if
  end subroutine sub1

end module mod2

program main
  use mod2
  implicit none
  integer :: a, b, res
  integer, pointer :: p => null()

  a = 40
  b = 8

  ! ====================
  ! A-3 ontains
  ! B-1 optional
  ! C-1 none
  ! D-3 null
  ! ====================
  call sub1(a, b, p, res)
  print *, "sum 1:", res

end program
