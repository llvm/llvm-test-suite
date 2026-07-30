! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: F2008 C440

program main
  implicit none
  type :: Node
    integer :: value
    type(Node) :: next ! non allocatable
  end type Node
  type(Node) :: n1

  allocate(n1%next)
  n1%next%value = 10

  print *, n1%next%value

end program

! GFORT: 08_recursiveAlloc_c001.f90:10:
! GFORT-NOT: .f90
! GFORT: Error:

! FLANG: 08_recursiveAlloc_c001.f90:10:
! FLANG-SAME: error:

