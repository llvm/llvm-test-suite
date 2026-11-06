! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -std=f2008 -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: F2008 R448

module m
  implicit none

  type :: t
    integer :: v = 0
  contains
    procedure :: p1, p1
  end type

contains

  subroutine p1(this)
    class(t) :: this
    this%v = this%v + 1
  end

end module

program main
  use m
  implicit none

  type(t) :: obj

  call obj%p1()

  print *, obj%v

end program

! GFORT: 14_typeBoundProc_c003.f90:12:
! GFORT-NOT: .f90
! GFORT: Error:

! FLANG: 14_typeBoundProc_c003.f90:12:
! FLANG-SAME: error:
