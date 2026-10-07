! RUN: not %flang -c %s 2>&1 | FileCheck --check-prefix=FLANG %s
! RUN: not %gfortran -c %s 2>&1 | FileCheck --check-prefix=GFORT %s

! SPEC: F2008:13.7.128 PARITY

program main
  implicit none
  integer :: a(2) = [1, 2]

  ! ====================
  ! A-3 logical scalar
  ! B-1 no dim
  ! ====================
  write (*,*) "parity =", parity(a)

end program

! GFORT: 28_parity_c002.f90:14:
! GFORT-NOT: .f90
! GFORT: Error:

! FLANG: 28_parity_c002.f90:14:
! FLANG-SAME: error:
