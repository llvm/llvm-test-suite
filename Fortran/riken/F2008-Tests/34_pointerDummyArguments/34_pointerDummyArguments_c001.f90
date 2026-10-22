! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: F2008 Introduction, 12.5.2.7

! ====================
! A-1 subroutine
! B-1 intent(in)
! C-1 pointer
! D-2 target none
! E-1 none
! ====================
subroutine sub(p, a, res)
  integer, pointer, intent(in) :: p
  integer, intent(in) :: a
  integer, intent(out) :: res
  print *, 'associated(p) = ', associated(p)
  if (.not. associated(p)) then
    res = -1
  else
    res = a * p
  end if

end subroutine sub

program main
  implicit none
  interface
    subroutine sub(p, a, res)
      integer, pointer, intent(in) :: p
      integer, intent(in) :: a
      integer, intent(out) :: res
    end subroutine sub
  end interface
  integer :: x, res
  integer :: i
  x = 5
  i = 10
  
  call sub(i, x, res)
  print *, 'res =', res

end program main

! FLANG: 34_pointerDummyArguments_c001.f90:40:
! FLANG-SAME: error:

! GFORT: 34_pointerDummyArguments_c001.f90:40:
! GFORT-NOT: .f90
! GFORT: Error: