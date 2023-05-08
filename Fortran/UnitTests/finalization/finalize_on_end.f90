module finalize_on_end_m

  include "object_type_m.f90"

  function finalize_on_end() result(outcome)
    !! Test conformance with Fortran 2018 clause 7.5.6.3, paragraph 3:
    !! "before return or END statement"
    !! finalizes a non-pointer non-allocatable object at the END statement
    logical outcome
    integer initial_tally

    initial_tally = finalizations
    call finalize_on_end_subroutine() ! Finalizes local_obj
    associate(final_tally => finalizations - initial_tally)
      outcome = final_tally==1
    end associate

  contains

    subroutine finalize_on_end_subroutine()
      type(object_t) :: local_obj
      local_obj % dummy = avoid_unused_variable_warning
    end subroutine

  end function

end module finalize_on_end_m

program main
  use finalize_on_end_m, only : finalize_on_end, report
  implicit none
  character(len=*), parameter :: description = &
       "finalizes a non-pointer non-allocatable object at the END statement"

  write(*,"(A)") report(finalize_on_end()) // description

end program
