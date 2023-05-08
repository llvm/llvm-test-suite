module lhs_object_m

  include "object_type_m.f90"

  function lhs_object() result(outcome)
    !! Test conformance with Fortran 2018 clause 7.5.6.3, paragraph 1 behavior:
    !! "not an unallocated allocatable variable"
    !! finalizes a non-allocatable object on the LHS of an intrinsic assignment
    type(object_t) lhs, rhs
    logical outcome
    integer initial_tally

    rhs%dummy = avoid_unused_variable_warning
    initial_tally = finalizations
    lhs = rhs ! finalizes lhs
    associate(finalization_tally => finalizations - initial_tally)
      outcome = finalization_tally==1
    end associate
  end function

end module lhs_object_m

program main
  use lhs_object_m, only : lhs_object, report
  implicit none
  character(len=*), parameter :: description = &
       "finalizes a non-allocatable object on the LHS of an intrinsic assignment"

  write(*,"(A)") report(lhs_object()) // description

end program
