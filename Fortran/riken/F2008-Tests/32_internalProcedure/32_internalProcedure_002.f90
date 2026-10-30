! SPEC: F2008 Introduction, 12.2.2.2

! ====================
! A-1 
! B-2
! ====================
real function integrate(f, a, b) result(integral)
  interface
    real function f(x)
      real, value :: x
    end function f
  end interface
  real, intent(in) :: a, b
  real :: contains

  integral = f(a) + b
end function integrate

program main
  implicit none
  interface
    real function integrate(f, a, b) result(integral)
      interface
        real function f(x)
          real, value :: x
        end function f
      end interface
      real, intent(in) :: a, b
    end function integrate
  end interface

  integer :: n = 2
  real :: a, b, res

  a = 3.0
  b = 2.0

  res = integrate(my_f1, a, b)

  print "(a, f6.2)", "res(my_f1) =", res

  res = integrate(my_f2, a, b)

  print "(a, f6.2)", "res(my_f2) =", res

contains
  real function my_f1(x)
    real, value :: x
    my_f1 = x * n
  end function my_f1

  real function my_f2(x)
    real, value :: x
    my_f2 = x**n
  end function my_f2

end program main
