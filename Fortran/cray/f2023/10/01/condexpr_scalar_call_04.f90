! Test for conditional expressions (Fortran 2023)

module M_condexpr_scalar_call_04
  type T
    real :: x, y, z
  end type T
contains
  function fs(idx) result(ans)
    integer :: idx
    type(T) :: ans
    ans%x = 10.0 * idx
    ans%y = 20.0 * idx
    ans%z = 30.0 * idx
  end function fs
end module M_condexpr_scalar_call_04

subroutine S(result, c1, k)
  use M_condexpr_scalar_call_04
  type(T) :: result
  logical :: c1
  integer :: k
  result = ( c1 ? fs(k) : T(1.0, 2.0, 3.0) )
end subroutine S

program main
  use M_condexpr_scalar_call_04
  type(T) :: r
  call S(r, .false., 1)
  if (r%x .eq. 1. .and. r%y .eq. 2. .and. r%z .eq. 3.) then
    print *, "PASS"
  else
    print *, "FAIL:", r
  endif
  call S(r, .true.,  2)
  if (r%x .eq. 20. .and. r%y .eq. 40. .and. r%z .eq. 60.) then
    print *, "PASS"
  else
    print *, "FAIL:", r
  endif
end program main
