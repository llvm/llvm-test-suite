! Test for conditional expressions (Fortran 2023)
!
! To ensure calls under cond-expr control
! are called only when expected

module M_condexpr_scalar_call_01
contains
  integer function f1()
    f1 = 27
  end function f1

  integer function f2(cond, side)
    logical :: cond, side
    if ( cond .eqv. side ) then
      f2 = 100
    else
      print *, 'f2: FAIL' ! should not get here.
      f2 = -100
    endif
  end function f2
end module M_condexpr_scalar_call_01

subroutine S(A, c1 )
  use M_CONDEXPR_SCALAR_CALL_01
  integer :: A
  logical :: c1
  A = f1() + ( c1 ? f2(c1, .true.) : f2(c1, .false.) )
end subroutine S

program main
  integer :: AA
  call S( AA, .false. ); print *, 'first:  ', AA
  call S( AA, .true.  ); print *, 'second: ', AA
end program main
