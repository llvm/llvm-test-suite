module rhs_function_reference_m

  include "object_type_m.f90"

  function rhs_function_reference() result(outcome)
    !! Test conformance with Fortran 2018 clause 7.5.6.3, paragraph 5 behavior:
    !! "nonpointer function result"
    !! finalizes a function reference on the RHS of an intrinsic assignment
    type(object_t), allocatable :: object
    logical outcome
    integer initial_tally

    initial_tally = finalizations
    object = construct_object() ! finalizes object_t result
    associate(finalization_tally => finalizations - initial_tally)
      outcome = finalization_tally==1
    end associate
  end function

end module rhs_function_reference_m

program main
  use rhs_function_reference_m, only : rhs_function_reference, report
  implicit none
  character(len=*), parameter :: description = &
       "finalizes a function reference on the RHS of an intrinsic assignment"

  write(*,"(A)") report(rhs_function_reference()) // description

end program
