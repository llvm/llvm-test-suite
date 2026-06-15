! Test for conditional arguments (Fortran 2023)

module M_condexpr_array_lval_01
contains
  subroutine S(X)
    real    :: X(3)
    X = 10. * X
  end subroutine S
end module M_condexpr_array_lval_01

program main
  use M_condexpr_array_lval_01
  real :: A(5), B(5), X(3), Y(3)
  do i = 1, 5
     X = [ 17.0, 19.0, 21.0 ]
     Y = [ 37.0, 39.0, 41.0 ]
     call S( (mod(i,2) .eq. 0 ? X : Y) )
     A(i) = X(1) + X(3)
     B(i) = Y(2) - Y(1)
  enddo
  print *, 'A: ', A
  print *, 'B: ', B
end program main
