! SPEC: F2008 Introduction, 12.5.2.12, C544

subroutine sub1(x, y, z, sum)
  implicit none
  integer, intent(in) :: x, y
  integer, optional, pointer, intent(in) :: z
  integer, intent(out) :: sum

  print *, 'present(z) = ', present(z)
  if (.not. present(z)) then
    sum = x + y
  else 
    sum = x + y + z
  end if
end subroutine sub1

program main
  implicit none

  interface
    subroutine sub1(x, y, z, sum)
      integer, intent(in) :: x, y
      integer, optional, pointer, intent(in) :: z
      integer, intent(out) :: sum
    end subroutine sub1
  end interface

  integer :: a, b, res
  integer, target :: c
  integer, pointer :: p => null()

  a = 10
  b = 5

  ! ====================
  ! A-1 subroutine
  ! B-1 optional
  ! C-3 pointer
  ! D-4 pointer
  ! ====================
  c = 100
  p => c
  call sub1(a, b, p, res)
  print *, "sum 1:", res

end program main
