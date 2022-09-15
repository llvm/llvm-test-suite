  !! This file gets `include "..."`-ed from each main program.
  !! To prevent a CMake race condition, each main program also declares
  !! a unique module name so that the .mod files don't clobber eachother.
  !!
  !! Common object type module to be included in the test that:
  !! Define tests for each scenario in which the Fortran 2018
  !! standard mandates type finalization.
  implicit none

  public !! Needed for declaring module procedures at the top of each main program
  public :: report
  private :: construct_object, count_finalizations, object_t, wrapper_t, finalizations, avoid_unused_variable_warning

  type object_t
    integer dummy
  contains
    !! Comment out the following line to prove the tests will fail
    final :: count_finalizations
  end type

  type wrapper_t
    private
    type(object_t), allocatable :: object
  end type

  integer :: finalizations = 0
  integer, parameter :: avoid_unused_variable_warning = 1

contains

  function construct_object() result(object)
    !! Constructor for object_t
    type(object_t) object
    object % dummy = avoid_unused_variable_warning
  end function

  subroutine count_finalizations(self)
    !! Destructor for object_t
    type(object_t), intent(inout) :: self
    finalizations = finalizations + 1
    self % dummy = avoid_unused_variable_warning
  end subroutine

  pure function report(outcome)
    logical, intent(in) :: outcome
    character(len=:), allocatable ::  report
    report = merge("Pass: ", "Fail: ", outcome)
  end function

  !! No end module statement since this will be `include`d from other source files
