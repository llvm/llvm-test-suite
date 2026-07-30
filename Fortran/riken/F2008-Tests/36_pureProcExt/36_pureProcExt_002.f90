! SPEC: F2008 12.7 / 12.8.1

program main
  implicit none
  real :: arr(3) = [1.0, 4.0, 6.0]
  real :: res(3)
  real, save :: seed = 12345.0
  integer :: i

  res = random(arr)

  write(*,'(A,3F6.2)') "res =", res

contains

  impure elemental function random(a) result(x)
    real, intent(in) :: a 
    real :: x
    seed = mod(seed*3 + a, 100.0)
    x = seed / 100.0
    write(*,'(A,F6.2)') "seed =", seed 
  end function

end program
