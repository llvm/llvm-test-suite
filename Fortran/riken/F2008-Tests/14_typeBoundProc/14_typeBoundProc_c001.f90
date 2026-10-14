! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -std=f2008 -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: F2008 R448 (binding-name-list)

module m
  implicit none

  type, abstract :: t
    integer :: v = 0
  contains
    procedure(iface) :: p1, p2
  end type

  interface
     subroutine iface(x)
       import t
       class(t) :: x
     end subroutine
  end interface

end module

module m2
  use m
  implicit none

  type, extends(t) :: child
  contains
    procedure :: p1 => c1
    procedure :: p2 => c2
  end type

contains

  subroutine c1(x)
    class(child) :: x
    x%v = x%v + 1
  end subroutine

  subroutine c2(x)
    class(child) :: x
    x%v = x%v + 2
  end subroutine

end module

program main
  use m2
  implicit none

  type(child) :: obj

  call obj%p1()
  call obj%p2()

  print *, obj%v

end program

! GFORT: 14_typeBoundProc_c001.f90:12:
! GFORT-NOT: .f90
! GFORT: Error:

! FLANG: 14_typeBoundProc_c001.f90:12:
! FLANG-SAME: error:
