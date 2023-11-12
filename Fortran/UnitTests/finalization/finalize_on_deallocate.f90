module finalize_on_deallocate_m

  include "object_type_m.f90"

  function finalize_on_deallocate() result(outcome)
    !! Test conformance with Fortran 2018 clause 7.5.6.3, paragraph 2:
    !! "allocatable entity is deallocated"
    !! finalizes an object upon explicit deallocation
    type(object_t), allocatable :: object
    logical outcome
    integer initial_tally

    initial_tally = finalizations
    allocate(object)
    object%dummy = 1
    deallocate(object)          ! finalizes object
    associate(final_tally => finalizations - initial_tally)
      outcome = final_tally==1
    end associate
  end function

end module finalize_on_deallocate_m

program main
  use finalize_on_deallocate_m, only : finalize_on_deallocate, report
  implicit none
  character(len=*), parameter :: description = "finalizes an object upon explicit deallocation"

  write(*,"(A)") report(finalize_on_deallocate()) // description

end program
