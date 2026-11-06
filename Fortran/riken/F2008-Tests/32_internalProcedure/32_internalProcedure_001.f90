! SPEC: F2008 Introduction, 12.2.2.2

! ====================
! A-1 
! B-1
! ====================
real function integrate(f, a, b, c) result(integral)
  interface
    real function f(x, y)
      real, value :: x
      integer :: y
    end function f
  end interface
  real, intent(in) :: a, b
  integer :: c
  real :: contains

  integral = f(a, c) + b
end function integrate

program main
  implicit none
  interface
    real function integrate(f, a, b, c) result(integral)
      interface
        real function f(x, y)
          real, value :: x
          integer :: y
        end function f
      end interface
      real, intent(in) :: a, b
      integer :: c
    end function integrate
  end interface

  real :: r1, r2, res
  integer :: i1 = 2

  r1 = 3.0
  r2 = 2.0

  res = integrate(my_f1, r1, r2, i1)

  print "(a, f6.2)", "res(my_f1) =", res

  res = integrate(my_f2, r1, r2, i1)

  print "(a, f6.2)", "res(my_f2) =", res

contains
  real function my_f1(x, y)
    real, value :: x
    integer :: y
    my_f1 = x + y
  end function my_f1

  real function my_f2(x, y)
    real, value :: x
    integer :: y
    my_f2 = x * y
  end function my_f2

end program main
