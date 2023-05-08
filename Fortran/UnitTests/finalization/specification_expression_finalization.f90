module finalizable_m
  !! This module supports the main program at the bottom of this file, which
  !! tests compiler conformance with clause 7.5.6.3, paragraph 6 in the Fortran
  !! Interpretation Document (https://j3-fortran.org/doc/year/18/18-007r1.pdf):
  !! "If a specification expression in a scoping unit references
  !! a function, the result is finalized before execution of the executable
  !! constructs in the scoping unit."  (The same statement appears in clause
  !! 4.5.5.2, paragraph 5 of the Fortran 2003 standard.) In such a scenario,
  !! the final subroutine must be pure.  The only way to observe output from
  !! a pure final subroutine is for the subroutine to execute an error stop
  !! statement.  A correct execution of this test will error-terminate and ouput
  !! the text "finalize: intentional error termination to verify finalization".
  implicit none

  private
  public :: finalizable_t, component

  type finalizable_t
    private
    integer, pointer :: component_ => null()
  contains
    !! Comment out the next line to make the tests fail
    final :: finalize
  end Type

  interface finalizable_t
    module procedure construct
  end interface

contains

  pure function construct(component) result(finalizable)
    integer, intent(in) :: component
    type(finalizable_t) finalizable
    allocate(finalizable%component_, source = component)
  end function

  pure function component(self) result(self_component)
    type(finalizable_t), intent(in) :: self
    integer self_component
    if (.not. associated(self%component_)) error stop "component: unassociated component"
    self_component = self%component_
  end function

  pure subroutine finalize(self)
    type(finalizable_t), intent(inout) :: self
    if (associated(self%component_)) deallocate(self%component_)
    error stop "finalize: intentional error termination to verify finalization"
  end subroutine

end module

program specification_expression_finalization
  !! Test the finalization of a function result in a specification expression
  use finalizable_m, only : finalizable_t, component
  implicit none

  call finalize_specification_expression_result

contains

  subroutine finalize_specification_expression_result
    real tmp(component(finalizable_t(component=0))) !! Finalizes the finalizable_t function result
    real eliminate_unused_variable_warning
    tmp = eliminate_unused_variable_warning
  end subroutine

end program
