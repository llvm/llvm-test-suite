! SPEC: F2008 Introduction, 12.5.2.12, C544

function fun1(x, y, z) result(sum)
  implicit none
  integer, intent(in) :: x, y
  integer, optional, intent(in) :: z
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
      integer, optional, intent(in) :: z
      integer :: sum
    end function fun1
  end interface

  integer :: a, b, res
  integer, allocatable :: c
  integer, target :: d
  integer, pointer :: p => null()

  a = 10
  b = 5

  ! ====================
  ! A-2 function
  ! B-1 optional
  ! C-1 none
  ! D-1 nonallocate
  ! ====================
  res = fun1(a, b, c)
  print *, "sum 1:", res

  ! ====================
  ! A-2 function
  ! B-1 optional
  ! C-1 none
  ! D-2 allocated
  ! ====================
  allocate(c)
  c = 30
  res = fun1(a, b, c)
  print *, "sum 2:", res

  ! ====================
  ! A-2 function
  ! B-1 optional
  ! C-1 none
  ! D-3 null
  ! ====================
  res = fun1(a, b, p)
  print *, "sum 3:", res

  ! ====================
  ! A-2 function
  ! B-1 optional
  ! C-1 none
  ! D-4 pointer
  ! ====================
  d = 100
  p => d
  res = fun1(a, b, p)
  print *, "sum 4:", res

end program main
