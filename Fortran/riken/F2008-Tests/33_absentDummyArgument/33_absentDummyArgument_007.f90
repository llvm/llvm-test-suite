! SPEC: F2008 R505, R442, C510, C461

module mod1

contains

  function func1(x, y, z) result(sum)
    implicit none
    integer, intent(in) :: x, y
    integer, optional, intent(in) :: z(:)
    integer :: sum

    print *, 'present(z) = ', present(z)
    if (.not. present(z)) then
      sum = x + y
    else 
      sum = x + y + z(1)
    end if
  end function func1

end module mod1

program main
  use mod1
  implicit none
  integer :: a, b, res
  integer, allocatable :: c(:)

  a = 150
  b = 7

  ! ====================
  ! A-3 ontains
  ! B-1 optional
  ! C-1 none
  ! D-1 nonallocate
  ! ====================
  res = func1(a, b, c)
  print *, "sum 1:", res

end program
