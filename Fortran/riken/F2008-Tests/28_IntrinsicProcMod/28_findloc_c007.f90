! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: F2008:13.7.61 FINDLOC

program main
  implicit none
  integer :: a(2,2) = reshape([1,2,3,4],[2,2])
  logical :: m(3,3)

  m = reshape([ &
      .true.,.true.,.true., &
      .true.,.true.,.true., &
      .true.,.true.,.true. ], [3,3])

  ! ====================
  ! D-3 mask shape mismatch
  ! ====================
  print *, findloc(a, 2, mask=m)

end program

! GFORT: 28_findloc_c007.f90:19:
! GFORT-NOT: .f90
! GFORT: Error:

! FLANG: 28_findloc_c007.f90:19:
! FLANG-SAME: error:
