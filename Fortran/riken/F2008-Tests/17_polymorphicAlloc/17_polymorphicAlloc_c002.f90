! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: F2008 C638

module mc
  type :: t1
    integer :: n1
  end type t1

  type :: t3
    integer :: n3
  end type t3
end module mc

! ====================
! A-2 derived
! B-1 scalar
! C-2 source
! F-3 incompatible type
! ====================
program main
  use mc
  implicit none
  class(t1), allocatable :: p  ! polymorphic
  type(t3) :: a

  a%n3 = 30

  allocate(p, source=a)
  write(*,*) p%n3
end program

! GFORT: 17_polymorphicAlloc_c002.f90:30:
! GFORT-NOT: .f90
! GFORT: Error:

! FLANG: 17_polymorphicAlloc_c002.f90:30:
! FLANG-SAME: error:
