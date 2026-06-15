! Test for conditional expressions (Fortran 2023)

module M_condexpr_array_rval_01
contains
  function fs(idx, sz) result(ans)
    integer :: idx, sz
    real    :: ans(sz)
    ans = [ (2.0 * idx * i, i = 1, sz) ]
  end function fs
end module M_condexpr_array_rval_01

subroutine S(result, c1, k, sz)
  use M_condexpr_array_rval_01
  logical :: c1
  integer :: k, sz
  real    :: result(sz)
  result = ( c1 ? fs(k, sz) : [ 1.0, 2.0, 3.0 ] )
end subroutine S

program main
  use M_condexpr_array_rval_01
  real :: r(3)
  call S(r, .false., 1, 3); print *, 'False: ', r
  call S(r, .true.,  2, 3); print *, 'True:  ', r
end program main
