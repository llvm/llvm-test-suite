! Test for conditional arguments (Fortran 2023)

module M_condexpr_array_lval_02
contains
  subroutine final_sub( S_OUTPUT, S_INPUT  )
    real, intent(out) :: S_OUTPUT(5)
    real, intent(in)  :: S_INPUT(5)

    S_OUTPUT = S_INPUT
  end subroutine final_sub

  subroutine intermediate_sub(cond, ANSWER, TRUE_INPUT, FALSE_INPUT)
    logical, intent(in)             :: cond
    real, contiguous, intent(out)   :: ANSWER(:)
    real, contiguous, intent(in)    :: TRUE_INPUT(:)
    real, contiguous, intent(in)    :: FALSE_INPUT(:)
    call final_sub( ANSWER,  (cond ? TRUE_INPUT : FALSE_INPUT))
  end subroutine intermediate_sub
end module M_condexpr_array_lval_02

program main
  use M_condexpr_array_lval_02
  REAL :: MAIN_A(5)
  REAL :: MAIN_T(5)
  REAL :: MAIN_F(5)
  logical, parameter :: c(5) = [ .false., .true., .true., .false., .true. ]

  do i = 1, 5
      MAIN_T = [ 1.0, 2.0, 3.0, 4.0, 5.0 ]
      MAIN_F = MAIN_T + 10.0 !-- [ 11.0, 12.0, 13.0, 14.0, 15.0 ]
      call intermediate_sub(c(i), MAIN_A, MAIN_T, MAIN_F)
      print '(I2,": ",5F8.2)', i, MAIN_A
  enddo
end program main
