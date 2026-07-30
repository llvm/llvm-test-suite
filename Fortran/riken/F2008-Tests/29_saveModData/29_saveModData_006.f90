! SPEC: F2008 5.3.16

! ====================
! A-1 module
! B-3 proc-pointer
! C-1 automatically save
! ====================

module m
  implicit none
  interface
    module subroutine set_pointer()
    end subroutine
    module subroutine call_pointer()
    end subroutine
    module subroutine foo()
    end subroutine
  end interface
end module m

submodule (m) smod
  implicit none
  procedure(), pointer :: p => null()  ! Implicit save attribute
contains
  module procedure foo
    print *, "OK"
  end procedure foo

  module procedure set_pointer
    p => foo
  end procedure set_pointer

  module procedure call_pointer
    call p()
  end procedure call_pointer
end submodule smod

program main
  use m
  implicit none

  call set_pointer()
  call call_pointer()

end program main
