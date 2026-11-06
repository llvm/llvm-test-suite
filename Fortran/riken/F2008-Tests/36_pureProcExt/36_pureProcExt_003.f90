! SPEC: F2008 12.7 / 12.8.1

module mrand
  implicit none
  real :: seed = 12345.0
contains
  impure elemental subroutine random(x)
    real, intent(out) :: x
    seed = mod(seed*3 + 1, 100.0)
    x = seed / 100.0
    write(*,'(A,F6.2)') "seed =", seed 
  end subroutine random
end module mrand

program main
  use mrand
  implicit none
  real :: arr(3)
  integer :: i

  call random(arr)

  write(*,'(A,3F6.2)') "arr =", arr
end program
