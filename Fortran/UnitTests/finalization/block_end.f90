module block_end_m
  include "object_type_m.f90"

  function block_end() result(outcome)
    !! Test conformance with Fortran 2018 clause  7.5.6.3, paragraph 4:
    !! "termination of the BLOCK construct"
    !! finalizes a non-pointer non-allocatable object at the end of a block construct
    logical outcome
    integer initial_tally

    initial_tally = finalizations
    block
      type(object_t) object
      object % dummy = avoid_unused_variable_warning
    end block ! Finalizes object
    associate(finalization_tally => finalizations - initial_tally)
      outcome = finalization_tally==1
    end associate
  end function

end module block_end_m

program main
  use block_end_m, only : block_end, report
  implicit none
  character(len=*), parameter :: description = &
       "finalizes a non-pointer non-allocatable object at the end of a block construct"

  write(*,"(A)") report(block_end()) // description

end program
