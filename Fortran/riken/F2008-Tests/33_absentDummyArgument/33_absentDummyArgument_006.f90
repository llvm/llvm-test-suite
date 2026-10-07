! SPEC: F2008 Introduction, 12.5.2.12, C544

function fun1(x, y, z) result(sum)
  implicit none
  integer, intent(in) :: x, y
  integer, optional, pointer, intent(in) :: z
  integer :: sum

  print *, 'present(z) = ', present(z)
  if (.not. present(z)) then
    sum = x + y
  else 
    sum = x + y + z
  end if
end function fun1

program main
  implicit none

  interface
    function fun1(x, y, z) result(sum)
      integer, intent(in) :: x, y
      integer, optional, pointer, intent(in) :: z
      integer :: sum
    end function fun1
  end interface

  integer :: a, b, res
  integer, target :: c
  integer, pointer :: p => null()

  a = 10
  b = 5

  ! ====================
  ! A-2 function
  ! B-1 optional
  ! C-3 pointer
  ! D-4 pointer
  ! ====================
  c = 100
  p => c
  res = fun1(a, b, p)
  print *, "sum 1:", res

end program main
