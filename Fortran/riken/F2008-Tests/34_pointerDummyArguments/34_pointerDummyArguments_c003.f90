! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: F2008 Introduction, 12.5.2.7

! ====================
! A-3 module
! B-1 intent(in)
! C-1 pointer
! D-2 target none
! E-1 none
! ====================
module mod1

contains
  subroutine sub1(p, a, res)
    integer, pointer, intent(in) :: p
    integer, intent(in) :: a
    integer, intent(out) :: res
    print *, 'associated(p) = ', associated(p)
    if (.not. associated(p)) then
      res = -1
    else
      res = a + p
    end if
  end subroutine sub1
end module mod1

program main
  use mod1
  implicit none
  integer :: x, res
  integer :: i
  x = 200
  i = 7
  
  call sub1(i, x, res)
  print *, 'res =', res

end program main

! FLANG: 34_pointerDummyArguments_c003.f90:37:
! FLANG-SAME: error:

! GFORT: 34_pointerDummyArguments_c003.f90:37:
! GFORT-NOT: .f90
! GFORT: Error: