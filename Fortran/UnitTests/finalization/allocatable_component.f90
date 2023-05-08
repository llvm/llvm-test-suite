module  allocatable_component_m
  include "object_type_m.f90"

  function allocatable_component() result(outcome)
    !! Test conformance with Fortran 2018 clause 7.5.6.3, para. 2 ("allocatable entity is deallocated")
    !! + 9.7.3.2, para. 6 ("INTENT(OUT) allocatable dummy argument is deallocated")
    !! finalizes an allocatable component object
    type(wrapper_t), allocatable :: wrapper
    logical outcome
    integer initial_tally

    initial_tally = finalizations

    allocate(wrapper)
    allocate(wrapper%object)
    call finalize_intent_out_component(wrapper)
    associate(finalization_tally => finalizations - initial_tally)
      outcome = finalization_tally==1
    end associate

  contains

    subroutine finalize_intent_out_component(output)
      type(wrapper_t), intent(out) :: output ! finalizes object component
      allocate(output%object)
      output%object%dummy = avoid_unused_variable_warning
    end subroutine

  end function

end module allocatable_component_m

program main
  use allocatable_component_m, only : allocatable_component, report
  implicit none
  character(len=*), parameter :: description = "finalizes an allocatable component object"

  write(*,"(A)") report(allocatable_component()) // description

end program
