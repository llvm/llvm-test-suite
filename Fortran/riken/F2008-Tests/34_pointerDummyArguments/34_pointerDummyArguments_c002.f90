! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: F2008 Introduction, 12.5.2.7

! ====================
! A-2 function
! B-1 intent(in)
! C-1 pointer
! D-2 target none
! E-1 none
! ====================
integer function func(p, a)
  integer, pointer, intent(in) :: p
  integer, intent(in) :: a
  print *, 'associated(p) = ', associated(p)
  if (.not. associated(p)) then
    func = -1
  else
    func = p / a
  end if
end function func

program main
  implicit none
  interface
    integer function func(p, a)
      integer, pointer, intent(in) :: p
      integer, intent(in) :: a
    end function func
  end interface
  integer :: x, res
  integer :: i
  x = 30
  i = 5500
  
  res = func(i, x)
  print *, 'res =', res

end program main

! FLANG: 34_pointerDummyArguments_c002.f90:37:
! FLANG-SAME: error:

! GFORT: 34_pointerDummyArguments_c002.f90:37:
! GFORT-NOT: .f90
! GFORT: Error: