! SPEC: F2008 Introduction, Table 2.2

! ====================
! A-1 empty contains
! B-3 submodule
! ====================
module parent_mod
  implicit none

  interface
    module subroutine sub()
    end subroutine sub
  end interface

end module parent_mod

submodule(parent_mod) child_mod1
  implicit none
  integer :: x = 10

contains
  module procedure sub
    print *, "x =", x
  end procedure sub
end submodule child_mod1

submodule(parent_mod) child_mod2
  implicit none
  integer :: y = 20

! Empty contains section
contains

end submodule child_mod2

program main
    use parent_mod
    implicit none

    call sub()
    print *, "Empty contains test done!"

end program main
