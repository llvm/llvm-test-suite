module intent_out_m

  include "object_type_m.f90"

  function intent_out() result(outcome)
    !! Test conformance with Fortran 2018 standard clause 7.5.6.3, paragraph 7:
    !! "nonpointer, nonallocatable, INTENT (OUT) dummy argument"
    !! finalizes an intent(out) derived type dummy argument
    logical outcome
    type(object_t) object
    integer initial_tally

    initial_tally = finalizations
    call finalize_intent_out_arg(object)
    associate(finalization_tally => finalizations - initial_tally)
      outcome = finalization_tally==1
    end associate
  contains
    subroutine finalize_intent_out_arg(output)
      type(object_t), intent(out) :: output ! finalizes output
      output%dummy = avoid_unused_variable_warning
    end subroutine
  end function

end module intent_out_m

program main
  use intent_out_m, only : intent_out, report
  implicit none
  character(len=*), parameter :: description = "finalizes an intent(out) derived type dummy argument"

  write(*,"(A)") report(intent_out()) // description

end program
