! Test for conditional expressions (Fortran 2023)

module M_condexpr_scalar_call_03
contains
  function fs(idx) result(ans)
    integer idx
    character(len=:), allocatable :: ans
    if      ( idx .eq. 1 ) then
       ans = 'one'
    else if ( idx .eq. 2 ) then
       ans = 'two'
    else
       ans = 'other'
    endif
  end function fs
end module M_condexpr_scalar_call_03

subroutine S(result, c1, k)
  use M_condexpr_scalar_call_03
  character*(*) :: result
  logical :: c1
  integer :: k
  result = 'ABC:' // ( c1 ? fs(k) : 'XYZ' )
end subroutine S

program main
  character(len=7) :: r
  call S(r, .false., 1); print *, 'False: ', r
  call S(r, .true.,  2); print *, 'True:  ', r
end program main
