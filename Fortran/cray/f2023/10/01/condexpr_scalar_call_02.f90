! Test for conditional expressions (Fortran 2023)
!
! Constructors subject to a conditional expression should not be
! evaluated when the controlling condition is not satisfied.

module M_condexpr_scalar_call_02
contains
  integer function fr(arr)
    real :: arr(:)
    fr = sum(arr)
  end function fr

  integer function fv(x)
    integer, value :: x
    fv = x*x
  end function fv
end module M_condexpr_scalar_call_02

subroutine S(result, c1, kr)
  use M_condexpr_scalar_call_02
  integer :: result
  logical :: c1
  real    :: kr
  result = 42 + ( c1 ? fr([1.0, 2.0, 3.0, 1.0/kr]) : fv(13) )
end subroutine S

program main
  integer :: r
  call S(r, .false., 0.0); print *, 'False: ', r
  call S(r, .true.,  1.0); print *, 'True:  ', r
end program main
