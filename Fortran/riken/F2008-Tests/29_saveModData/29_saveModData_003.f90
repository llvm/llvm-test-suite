! SPEC: F2008 5.3.16

! ====================
! A-1 module
! B-3 proc-pointer
! C-1 automatically save
! ====================

module m
  implicit none
  procedure(), pointer :: p => null()  ! Implicit save attribute
contains
  subroutine set()
    p => foo
  end subroutine

  subroutine callp()
    call p()
  end subroutine

  subroutine foo()
    print *, "OK"
  end subroutine
end module

program main
  use m
  call set()
  call callp()

end program
