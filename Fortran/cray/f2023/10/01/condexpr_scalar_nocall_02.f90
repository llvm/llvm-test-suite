! Test for conditional expressions (Fortran 2023)

subroutine S(A, X, n)
  real :: A(n), X
  X = sum(A)
  X = X + ( sum(A) > 1.0 ? product(A) : A(1) )  !! PE-52297
end subroutine S

program main
  parameter (n = 8)
  real :: B(n), X = 0.0
  B = [ 1.0, 2.0, 3.0, 4.0, 4.0, 3.0, 2.0, 1.0 ]
  call S(B, X, n)
  print *, X
  B = [ 1.0, 2.0, 3.0, 4.0, -4.0, -3.0, -2.0, -1.0 ]
  call S(B, X, n)
  print *, X
end program main
