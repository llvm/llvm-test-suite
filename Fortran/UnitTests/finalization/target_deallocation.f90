module target_deallocation_m
  include "object_type_m.f90"

  function target_deallocation() result(outcome)
    !! Test conformance with Fortran 2018 clause 7.5.6.3, paragraph 2 behavior:
    !! "pointer is deallocated"
    !! finalizes a target when the associated pointer is deallocated
    type(object_t), pointer :: object_ptr => null()
    logical outcome
    integer initial_tally

    allocate(object_ptr, source=object_t(dummy=0))
    initial_tally = finalizations
    deallocate(object_ptr) ! finalizes object
    associate(finalization_tally => finalizations - initial_tally)
      outcome = finalization_tally==1
    end associate
  end function

end module target_deallocation_m

program main
  use target_deallocation_m, only : target_deallocation, report
  implicit none
  character(len=*), parameter :: description = "finalizes a target when the associated pointer is deallocated"

  write(*,"(A)") report(target_deallocation()) // description

end program
