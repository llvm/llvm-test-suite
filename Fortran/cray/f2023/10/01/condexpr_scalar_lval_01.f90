! Test for conditional arguments (Fortran 2023)

module M_condexpr_scalar_lval_01
contains
  subroutine S(X)
    real    :: X
    X = 10. * X
  end subroutine S
end module M_condexpr_scalar_lval_01

program main
  use M_condexpr_scalar_lval_01
  real :: A(5), B(5)
  do i = 1, 5
     X = 17.0
     Y = 37.0
     call S( (mod(i,2) .eq. 0 ? X : Y) )
     A(i) = X
     B(i) = Y
  enddo
  print *, 'A: ', A
  print *, 'B: ', B
end program main
