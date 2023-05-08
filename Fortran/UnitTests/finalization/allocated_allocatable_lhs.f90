module allocated_allocatable_lhs_m
  include "object_type_m.f90"

  function allocated_allocatable_lhs() result(outcome)
    !! Test conformance with Fortran 2018 clause 7.5.6.3, paragraph 1 behavior:
    !! "allocated allocatable variable"
    !! finalizes an allocated allocatable LHS of an intrinsic assignment
    type(object_t), allocatable :: lhs
    type(object_t) rhs
    logical outcome
    integer initial_tally

    rhs%dummy = avoid_unused_variable_warning
    initial_tally = finalizations
    allocate(lhs)
    lhs = rhs ! finalizes lhs
    associate(finalization_tally => finalizations - initial_tally)
      outcome = finalization_tally==1
    end associate
  end function

end module allocated_allocatable_lhs_m

program main
  use allocated_allocatable_lhs_m, only : allocated_allocatable_lhs, report
  implicit none
  character(len=*), parameter :: description = "finalizes an allocated allocatable LHS of an intrinsic assignment"

  write(*,"(A)") report(allocated_allocatable_lhs()) // description

end program
